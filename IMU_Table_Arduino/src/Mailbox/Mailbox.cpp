#include "Mailbox.h"

//  Mailbox -- Public Functions ///////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
    Constructor -- Default
*/
MailBox::MailBox()
{
    bLOC_Induced = false;
    bStartup = true;

    nRXSequenceNum = 0;
    nBytesReceived = 0;
    nBytesSent = 0;
    nRX_Message_Length = _RX_MESSAGE_LENGTH_NORMAL;
    nTX_Message_Length = _TX_MESSAGE_LENGTH_NORMAL;

    stTXState = MailboxState_T::eStart;
}

/*-------------------------------------------------------------------------------------------------
    Destructor -- Default
*/
MailBox::~MailBox()
{

}

//  Mailbox -- Protected Functions  ///////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
    updateStateMachine

    Updates the central mailbox state machine and runs its state-change logic.

    INPUT   --  NONE

    OUTPUT (MailboxState_T)
        The output of the next-state logic. This is what the mailbox state will be for the next
        process frame.
*/
MailBox::MailboxState_T MailBox::updateStateMachine()
{
    MailboxState_T stNext_MailboxState;

    //State change logic
    switch(stTXState)
    {
    case MailboxState_T::eStart:

        //Once a TX message is ready, shift to normal state
        if(!bStartup)                                       //If the mailbox is no longer in startup
            stNext_MailboxState = MailboxState_T::eNormal;      //Change the state to normal operations
        else                                                //Else
            stNext_MailboxState = MailboxState_T::eStart;       //Remain in startup

        break;

    case MailboxState_T::eNormal:

        if(bLOC_Induced || is_LOC(stRXState))               //If we have induced LOC, or the other device is still in LOC
            stNext_MailboxState = MailboxState_T::eLOC_1;       //Change state to LOC1
        else                                                //Else
            stNext_MailboxState = MailboxState_T::eNormal;      //Continue normal operations

        break;

    case MailboxState_T::eLOC_1:

        if(bLOC_Induced || is_LOC(stRXState))               //If we have induced LOC, or the other device is still in LOC
            stNext_MailboxState = MailboxState_T::eLOC_2;       //Change state to LOC2
        else if(stRXState == MailboxState_T::eNormal)       //If the master device is back to normal operations
            stNext_MailboxState = MailboxState_T::eNormal;      //Shift to normal state as well
        else                                                //Else
            stNext_MailboxState = MailboxState_T::eLOC_1;       //Continue in LOC1

        break;

    case MailboxState_T::eLOC_2:

        if(bLOC_Induced || is_LOC(stRXState))               //If we have induced LOC, or the other device is still in LOC
            stNext_MailboxState = MailboxState_T::eLOC_3;       //Change state to LOC3
        else if(stRXState == MailboxState_T::eNormal)       //If the master device is back to normal operations
            stNext_MailboxState = MailboxState_T::eNormal;      //Shift to normal state as well
        else                                                //Else
            stNext_MailboxState = MailboxState_T::eLOC_2;       //Continue in LOC2

        break;

    case MailboxState_T::eLOC_3:

        if(bLOC_Induced || is_LOC(stRXState))                       //If we have induced LOC, or the other device is still in LOC
            stNext_MailboxState = MailboxState_T::eRecovery_LOC;       //Change state to Recovery_LOC
        else if(stRXState == MailboxState_T::eNormal)               //If the master device is back to normal operations
            stNext_MailboxState = MailboxState_T::eNormal;              //Shift to normal state as well
        else                                                        //Else
            stNext_MailboxState = MailboxState_T::eLOC_1;               //Continue in LOC3

        break;

    case MailboxState_T::eRecovery_LOC:

        //Remain in Recovery_LOC until the main process in loop() sets the recovery flag
        stNext_MailboxState = MailboxState_T::eRecovery_LOC;

        break;

    case MailboxState_T::eRecovery:

        if(stRXState == MailboxState_T::eNormal)            //If the master device is back to normal operations
            stNext_MailboxState = MailboxState_T::eNormal;      //Shift to normal state as well
        else                                                //Else
            stNext_MailboxState = MailboxState_T::eRecovery;    //Remain in recovery

        break;
    
    default:

        //Should not be here
        //Set state to eRecovery
        stNext_MailboxState = MailboxState_T::eRecovery;

        break;
    }

    //Output logic
    switch(stNext_MailboxState)
    {
    case MailboxState_T::eStart:

        //Continue down

    case MailboxState_T::eNormal:

        //Set TX message length
        nTX_Message_Length = _TX_MESSAGE_LENGTH_NORMAL + _LETTER_LENGTH;

        break;

    case MailboxState_T::eLOC_1:

        //Continue down

    case MailboxState_T::eLOC_2:

        //Continue down

    case MailboxState_T::eLOC_3:

        //Continue down

    case MailboxState_T::eRecovery_LOC:

       //Continue down

    case MailboxState_T::eRecovery:

        //Set TX message length
        nTX_Message_Length = _TX_MESSAGE_LENGTH_RECOVERY + _LETTER_LENGTH;

        break;
    
    default:

        //Do nothing

        break;
    }

    //Return the next state
    return stNext_MailboxState;
}

/*-------------------------------------------------------------------------------------------------
    Process_RX

    Subroutine which processes the command message that was most recently received from the other
    device.

    INPUT   --  NONE

    OUTPUT (void)
*/
void MailBox::Process_RX()
{
    RX_Message_Structure_Normal_T * stRX_msg;
    RX_Message_Structure_Recovery_T * stRXmsg;
    
    //Begin parsing the buffered message based on the master's mailbox state, as that will
    //determine the type of message that was received
    switch(stRXState)
    {
    case MailboxState_T::eNormal:

        //Create message structure
        stRX_msg = (RX_Message_Structure_Normal_T *)cRX_Buf;

        //Load into RX Message
        mRX = RX_Message(*stRX_msg);

        //If the RX_Message's reports LOC, or the RX sequence number isn't 1 + the last RX'd message's, induce LOC
        if(is_LOC(stRXState) && (nRXSequenceNum != (nRXSequenceNum + 1)))
            Induce_LOC();

        break;

    case MailboxState_T::eLOC_1:

        //Continue down  

    case MailboxState_T::eLOC_2:

        //Contnue down

    case MailboxState_T::eLOC_3:

        //Induce LOC and continue down
        Induce_LOC();

    case MailboxState_T::eRecovery_LOC:

    case MailboxState_T::eRecovery:

        //Create message structure
        stRX_msg = (RX_Message_Structure_Normal_T *)cRX_Buf;

        //If the RX_Message's reports LOC, or the RX sequence number isn't 1 + the last RX'd message's, induce LOC
        if(is_LOC(stRXState) && (nRXSequenceNum != (nRXSequenceNum + 1)))
            Induce_LOC();

        //Load into RX message
        mRX = RX_Message(*stRX_msg);

        break;

    default:
        
        //Do nothing but return before clearing the RX_Buf_Ready flag
        return;
    }
}

/*-------------------------------------------------------------------------------------------------
    Process_TX

    Subroutine which processes the TX_Message received from the other device.

    INPUT   --  NONE

    OUTPUT (void)
*/
void MailBox::Process_TX()
{
    //Set TX message sequence number
    nTXSequenceNum++;

    //Populate the message into cTX_Buf according to the current mailbox state
    switch(stTXState)
    {
    case MailboxState_T::eNormal:
        //Create message structure
        TX_Message_Structure_Normal_T * stTX_msg;
        mTX = TX_Message(*stTX_msg);

        //Copy to the TX buffer
        memcpy(cTX_Buf, stTX_msg, _TX_MESSAGE_LENGTH_NORMAL);

        break;

    case MailboxState_T::eLOC_1:

        //Continue down

    case MailboxState_T::eLOC_2:

        //Continue down

    case MailboxState_T::eLOC_3:

        //Continue down

    case MailboxState_T::eRecovery_LOC:

        //Continue down

    case MailboxState_T::eRecovery:

        //Copy hash compare from RX message
        mTX.Set_HashCompare(mRX.HashCompare());

        //Create message structure
        TX_Message_Structure_Recovery_T * stTXmsg;
        mTX = TX_Message(*stTX_msg);

        //Copy to the TX buffer
        memcpy(cTX_Buf, stTX_msg, _TX_MESSAGE_LENGTH_RECOVERY);

        break;

    default:
        
        //Do nothing but return before clearing the TX_Buf_Ready flag
        return;
        break;
    }
}

/*-------------------------------------------------------------------------------------------------
    RX

    Subroutine for receiving a message from the other device.

    INPUT   --  NONE

    OUPUT (void)
*/
void MailBox::RX()
{ 
    Letter_T lLetter;

    RX_Specific(lLetter); //Record the length of the string that was read in

    if(nBytesReceived && (lLetter.nMessageLength == nBytesReceived)) //If the message reports its correct length
    {
        if(checkCRC(lLetter)) //If the CRC returns no errors
        {
            stRXState = (MailboxState_T)lLetter.cMessageType; //Set the master's mailbox status to the message code
            nRXSequenceNum = lLetter.nSequenceNum;
            
            //Set the expected RX message length
            if((stRXState == MailboxState_T::eNormal) || (stRXState == MailboxState_T::eStart))
                nRX_Message_Length = _RX_MESSAGE_LENGTH_NORMAL;
            else
                nRX_Message_Length = _RX_MESSAGE_LENGTH_RECOVERY;                
            
            memcpy(cRX_Buf, lLetter.sMessage.c_str(), nRX_Message_Length); //Copy the message to the RX buffer
            
            return;
        }        
    }
    
    Induce_LOC(); //Flag Loss of Coms
}

/*-------------------------------------------------------------------------------------------------
    TX

    Subroutine for transmitting a response message to the other device.
    
    INPUT   --  NONE

    OUPUT (void)
*/
void MailBox::TX()
{    
    //Create and send a letter
    Letter_T lLetter;

    lLetter.nSequenceNum = nTXSequenceNum;
    lLetter.cMessageType = (uint8_t)stTXState;
    lLetter.nMessageLength = nTX_Message_Length;
    lLetter.sMessage = cTX_Buf;
    lLetter.nCRC = computeCRC(lLetter) & 0x7FFF;

    TX_Specific(lLetter);

    //Check for successful message transmission
    if(nBytesSent != lLetter.nMessageLength)
        Induce_LOC(); //Induce Loss of Coms if not
}

//  MailBox -- Private Functions //////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
    checkCRC

    Runs the provided letter through a 16 bit hashing process to determine whether the CRC value
    appended to the end is valid. This ensures that there are no errors in the letter as it was
    received.

    INPUT (Letter_T &)  --  lLetter
        Populated with a full message. Passed by reference.

    OUTPUT (bool)
        Returns true if the CRC is correct. Returns false if not.
*/
bool MailBox::checkCRC(Letter_T & lLetter)
{
    //Create a string with the length of the letter
    const int nStr_Len = _LETTER_LENGTH + lLetter.sMessage.length();
	char cMessage[256];

    //Copy over the letter header
    cMessage[0] = lLetter.cMessageType;
    cMessage[1] = lLetter.nMessageLength;

    //Copy over the message
    memcpy(&cMessage[2], lLetter.sMessage.c_str(), lLetter.sMessage.length());
    
    //Copy over the CRC
    cMessage[nStr_Len-3] = HI_16(lLetter.nCRC);
    cMessage[nStr_Len-2] = LO_16(lLetter.nCRC);

	//We don't need the stop byte

    if(!computeCRC(cMessage, nStr_Len))
        return true;
    else
        return false;
    
}

/*-------------------------------------------------------------------------------------------------
    computeCRC

    Runs the provided letter through a 8 bit hashing process to find the 15 bit CRC value for the
    message. This CRC value is then sent along with the message and re-evaluated by the receiver to
    check for errors in the data transfer.

    INPUT (Letter_T &)  --  lLetter
        Populated with a full message. Passed by reference.

    OUTPUT (uint8_t)
        Returns the 15 bit CRC that is generated in the form of a 8 bit integer.
*/
uint8_t MailBox::computeCRC(Letter_T & lLetter)
{
    //Create a string with the length of the letter minus the cData pointer and stop byte
	const int nStr_Len = _LETTER_LENGTH + lLetter.sMessage.length();
    char sMessage[256];

    //Copy over the letter header
    sMessage[0] = lLetter.cMessageType;
    sMessage[1] = lLetter.nMessageLength;

    //Copy over the message
    memcpy(&sMessage[2], lLetter.sMessage.c_str(), lLetter.sMessage.length());

    //The remaining 2 bytes will remain 0, as we concatenate 15 0 bits to the end of the string
    //Compute CRC
    return computeCRC(sMessage, nStr_Len) & 0x7FFF;
}

/*-------------------------------------------------------------------------------------------------
    computeCRC

    Computes the CRC of a C string by hashing subsequenct 16 bit words and shifting the divisor by
    1 bit to the right every Xor operation.

    INPUT (char *)  --  cStr
        The C string for the CRC to be generated off of.

    INPUT (int)     --  nLen
        The length of the C string in bits.

    OUTPUT (uint8_t)
        Returns the 8 bit CRC that is generated in the form of a 16 bit integer.
*/
uint8_t MailBox::computeCRC(char * cStr, int nLen)
{
    uint8_t nRemainder = 0, nDivisor = 0x8D;

    //Perform division on entire byte of data
    for(int i=0; i<nLen; i++)
    {
        nRemainder ^= cStr[i];

        //Perform division bit-by-bit on the data byte
        for(int j=0; j<8; j++)
            nRemainder = (nRemainder & 0x80) ? (nRemainder << 1) ^ nDivisor : (nRemainder << 1);
    }

    return nRemainder;
}
