#include "Mailbox.h"

//  Mailbox -- Public Functions ///////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
    Constructor -- Default
*/
Mailbox::Mailbox()
{
    bRX_Ready = false;
    bTX_Ready = false;
    bRX_Buf_Ready = false;
    bTX_Buf_Ready = false;

    stMailboxState = MailboxState_T::eStart;
    nRX_Message_Length = _RX_MESSAGE_LENGTH;
    nTX_Message_Length = _TX_MESSAGE_LENGTH;
}

/*-------------------------------------------------------------------------------------------------
    Destructor -- Default
*/
Mailbox::~Mailbox()
{

}

/*-------------------------------------------------------------------------------------------------
    runFrame_USB

    Runs a single process frame which executes the mailbox's primary functions through the Arduino's
    USB serial port.

    INPUT   --  NONE

    Output (void)
*/
void Mailbox::runFrame_USB()
{
    //RX Message from master
    RX_USB();

    //Process RX message
    Process_RX();

    //Update state machine
    stMailboxState = updateStateMachine();

    //Create response message
    Process_TX();

    //TX Message to master
    TX_USB();
}

//  Mailbox -- Private Functions //////////////////////////////////////////////////////////////////

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
bool Mailbox::checkCRC(Letter_T & lLetter)
{
    //Create a string with the length of the letter minus the stop byte
    int nStr_Len = sizeof(lLetter) + strlen(lLetter.cData) - 1;
    char cData[nStr_Len];

    //Copy over the letter header
    cData[0] = lLetter.cMessageType;
    cData[1] = lLetter.nMessageLength;

    //Copy over the message
    memcpy(&cData[2], lLetter.cData, strlen(lLetter.cData));
    
    //Copy over the CRC
    cData[2+nStr_Len] = HI_16(lLetter.nCRC);
    cData[3+nStr_Len] = LO_16(lLetter.nCRC);

    if(!computeCRC(cData, *((uint16_t *)cData), nStr_Len);
        return true;
    else
        return false;
    
}

/*-------------------------------------------------------------------------------------------------
    RX_USB

    Secondary subprocess for receiving a command message from the master device through the Arduino's 
    USB serial port.

    INPUT (Letter_T &)  --  lLetter
        An empty letter structure ready to be populated. Passed by reference.

    OUTPUT (int)
        Returns the number of characters that was read in through the serial event.
*/
int Mailbox::RX_USB(Letter_T & lLetter)
{
    //Else continue to fill up the buffer
    int i = 0;
    char cData[_RX_MESSAGE_LENGTH_NORMAL];

    //Grab letter headers
    while(Serial.available() && (i<2))
    {
        cData[i] = Serial.read();
        i++;
    }

    //If the header was read in correctly
    if(i == 2)
    {
        lLetter.cMessageType = (uint8_t)cData[0];
        lLetter.nMessageLength = (uint8_t)cData[1];
    }
    else
        return 0;

    //Read in cData and the tail of the letter
    while(Serial.available() && (i < lLetter.nMessageLength) && cData[i] != lLetter.nStopByte)
    {
        cData[i] = Serial.read();
        i++;
    }

    memcpy(lLetter.cData, &cData[2], nRX_Message_Length);       //Copy cData to the letter's cData
    lLetter.nCRC = (MERGE_16(cData[i-3], cData[i-2]) & 0x7FFF); //Load in the 15 bit CRC

    return i;
}

/*-------------------------------------------------------------------------------------------------
    computeCRC

    Runs the provided letter through a 16 bit hashing process to find the 15 bit CRC value for the
    message. This CRC value is then sent along with the message and re-evaluated by the receiver to
    check for errors in the data transfer.

    INPUT (Letter_T &)  --  lLetter
        Populated with a full message. Passed by reference.

    OUTPUT (uint16_t)
        Returns the 15 bit CRC that is generated in the form of a 16 bit integer.
*/
uint16_t Mailbox::computeCRC(Letter_T & lLetter)
{
    //Create a string with the length of the letter minus the cData pointer and stop byte
    int nStr_Len = sizeof(lLetter) + strlen(lLetter.cData) - 2;
    char cData[nStr_Len];

    //Copy over the letter header
    cData[0] = lLetter.cMessageType;
    cData[1] = lLetter.nMessageLength;

    //Copy over the message
    memcpy(&cData[2], lLetter.cData, strlen(lLetter.cData));

    //The remaining 2 bytes will remain 0, as we concatenate 15 0 bits to the end of the string
    //Compute CRC
    return computeCRC(cData, nStr_Len) & 0x7FFF;
}

/*-------------------------------------------------------------------------------------------------
    computeCRC

    Computes the CRC of a C string by hashing subsequenct 16 bit words and shifting the divisor by
    1 bit to the right every Xor operation.

    INPUT (char *)  --  cStr
        The C string for the CRC to be generated off of.

    INPUT (int)     --  nLen
        The length of the C string in bits.

    OUTPUT (uint16_t)
        Returns the 15 bit CRC that is generated in the form of a 16 bit integer.
*/
uint16_t Mailbox::computeCRC(char * cStr, int nLen)
{
    int nPos = 0;
    uint16_t nProduct, nNumerator = MERGE_16(*cData, *(cData+1)), nDenominator;

    //Iterate through string
    while(nPos <= nLen)
    {
        if(!(nNumerator & 0x8000))  //If the first bit of the passed down value is 0
            nDenominator - 0;           //Set the second value to 0
        else                        //Else
            nDenominator = 0xAAAA;      //Set it to the divisor

        //Calculate product for the current 16 bit window
        nNumerator = (nPassdown << 1);                                      //Shift the passdown to the right by 1
        nNumerator += ((uint16_t *)(cStr+(nPos/8)) & (0x80 >> (nPos % 8))); //Add the next bit in the string
        nNumerator ^ nDenominator;                                          //Xor the numerator and denominator   
    
        nPos++;
    }

    //Return the final 15 bits of the numerator as the remainder
    return nNumerator & 0x7FFF;
}

/*-------------------------------------------------------------------------------------------------
    updateStateMachine

    Updates the central mailbox state machine and runs its state-change logic.

    INPUT   --  NONE

    OUTPUT (MailboxState_T)
        The output of the next-state logic. This is what the mailbox state will be for the next
        process frame.
*/
MailboxState_T Mailbox::updateStateMachine()
{
    MailboxState_T stNext_MailboxState;

    switch(stMailboxState)
    {
    case MailboxState_T::eStart:

        //Once a TX message is ready, shift to normal state
        if(bTX_Ready)
            stNext_MailboxState = MailboxState_T::eNormal;

        //Otherwise remain in startup
        stNext_MailboxState = MailboxState_T::eStart;

        break;

    case MailboxState_T::eNormal:

        //If loss of coms is induced, shift to LOC_1
        if(bLOC_Induced)
            stNext_MailboxState = MailboxState_T::eLOC_1;

        //If the master device is still in LOC, shift to LOC_1
        if(is_LOC(stMasterState))
            stNext_MailboxState = MailboxState_T::eLOC_1;

        //Otherwise continue normal operations
        stNext_MailboxState = MailboxState_T::eNormal;

        break;

    case MailboxState_T::eLOC_1:

        //If loss of coms is induced, shift to LOC_2
        if(bLOC_Induced)
            stNext_MailboxState = MailboxState_T::eLOC_2;
        
        if(is_LOC(stMasterState))                           //If the master device is still in LOC
            stNext_MailboxState = MailboxState_T::eLOC_2;       //Shift to LOC_2
        else if(stMasterState == MailboxState_T::eNormal)   //If the master device is back to normal operations
            stNext_MailboxState = MailboxState_T::eNormal;      //Shift to normal state as well

        //Otherwise remain in LOC_1
        stNext_MailboxState = MailboxState_T::eLOC_1

        break;

    case MailboxState_T::eLOC_2:

        //If loss of coms is induced, shift to LOC_3
        if(bLOC_Induced)
            stNext_MailboxState = MailboxState_T::eLOC_3;

        if(is_LOC(stMasterState))                           //If the master device is still in LOC
            stNext_MailboxState = MailboxState_T::eLOC_3;       //Shift to LOC_3
        else if(stMasterState == MailboxState_T::eNormal)   //If the master device is back to normal operations
            stNext_MailboxState = MailboxState_T::eNormal;      //Shift to normal state as well

        //Otherwise remain in LOC_2
        stNext_MailboxState = MailboxState_T::eLOC_2

        break;

    case MailboxState_T::eLOC_3:

        //If loss of coms is induced, shift to LOC Recovery
        if(bLOC_Induced)
            stNext_MailboxState = MailboxState_T::eRecovery_LOC;

        if(is_LOC(stMasterState))                               //If the master device is still in LOC
            stNext_MailboxState = MailboxState_T::eRecovery_LOC;    //Shift to Recovery_LOC
        else if(stMasterState == MailboxState_T::eNormal)       //If the master device is back to normal operations
            stNext_MailboxState = MailboxState_T::eNormal;          //Shift to normal state as well

        //Otherwise remain in LOC_3
        stNext_MailboxState = MailboxState_T::eLOC_3

        break;

    case MailboxState_T::eRecovery_LOC:

        //Remain in Recovery_LOC until the main process in loop() sets the recovery flag
        stNext_MailboxState = MailboxState_T::eRecovery_LOC;

        break;

    case MailboxState_T::eRecovery:

        if(stMasterState == MailboxState_T::eNormal)        //If the master device is back to normal operations
            stNext_MailboxState = MailboxState_T::eNormal;      //Shift to normal state as well
        else                                                //Else
            stNext_MailboxState = MailboxState_T::eRecovery;    //Remain in recovery

        break;
    
    default:

        //Should not be here
        //Set state to eRecovery
        stNext_MailboxState = MailboxState_T::eRecovery;
    }

    //Update internal information in preparation for potential state change
    switch(stNext_MailboxState)
    {
    case MailboxState_T::eStart:

        //Continue down

    case MailboxState_T::eNormal:

        //Set TX message length
        nTX_Message_Length = _TX_MESSAGE_LENGTH_NORMAL;

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
        nTX_Message_Length = _TX_MESSAGE_LENGTH_RECOVERY;

        break;
    
    default:

        //Do nothing
    }

    //Return the next state
    return stNext_MailboxState;
}

/*-------------------------------------------------------------------------------------------------
    Process_RX

    Subprocess which processes the command message that was most recently received. Will not execute 
    unless one condition is met:
        
        1.  bRX_Buf_ready is set, which means cRX_Buf is populated with a full message ready for
            processing

    INPUT   --  NONE

    OUTPUT (void)
*/
void Mailbox::Process_RX()
{
    //Check to see if the RX buffer is ready for processing and there is no untouched message
    if(!RX_Buf_Ready())
        return;
    
    //Begin parsing the buffered message based on the master's mailbox state, as that will
    //determine the type of message that was received
    switch(stMasterState)
    {
    case MailboxState_T::eNormal:

        //Create message structure
        RX_Message_Structure_Normal_T * stRX_msg = (RX_Message_Structure_Normal_T *)cRX_Buf;

        //Load into RX Message
        mRX = RX_Message(stRX_msg);

        //If the RX_Message's sequence number isn't 1 + the last TX'd message's, induce LOC
        if(mRX.SequenceNum() != (mTX.SequenceNum()+1))
            induce_LOC();

        break;

    case MailboxState_T::eLOC_1:

        //Continue down  

    case MailboxState_T::eLOC2:

        //Contnue down

    case MailboxState_T::eLOC3:

        //Induce LOC and continue down
        induce_LOC();

    case MailboxState_T::eRecovery_LOC:

    case MailboxState_T::eRecovery:

        //Create message structure
        RX_Message_Structure_Recovery_T * stRXmsg = (RX_Message_Structure_Recovery_T *)cRX_Buf;

        //If the mailbox state is already LOC_x, then we have already reset the sequence number.
        //  So if the RX message's sequence number isn't 1 + the last TX'd message's, incude LOC
        if(is_LOC(stMailboxState) && (mRX.SequenceNum() != (mTX.SequenceNum()+1)))
            induce_LOC();

        //Load into RX message
        mRX = RX_Message(stRX_msg);

        break;

    default:
        
        //Do nothing but return before clearing the RX_Buf_Ready flag
        return;
    }


    Set_RX_Buf_Ready(false);    //Clear bRX_Buf_Ready as the buffer's message has now been processed
    Set_RX_Ready();             //Set bRX_Ready to signal loop() that a new message has been processed
}

/*-------------------------------------------------------------------------------------------------
    Process_TX

    Subprocess which processes the TX_Message received from loop(). Will not execute unless
    one condition is met:
        
        1.  bTX_Ready is set, which means that loop() has updated the mailbox with a new TX
            message.

    INPUT   --  NONE

    OUTPUT (void)
*/
void Mailbox::Process_TX()
{
    //Check to see if a TX message is ready to be processed
    if(!TX_Ready())
        return;

    //Set TX message sequence number
    mTX.Set_SequenceNum(mRX.SequenceNum()+1);

    //Populate the message into cTX_Buf according to the current mailbox state
    switch(stMailboxState)
    {
    case MailboxState_T::eNormal:
        //Create message structure
        TX_Message_Structure_Normal_T * stTX_msg;
        mTX.encode_MessageStructure(*stTX_msg);

        //Copy to the TX buffer
        memcpy(cTX_Buf, stTX_msg, _TX_MESSAGE_LENGTH_NORMAL);

        break;

    case MailboxState_T::eLOC_1:

        //Continue down

    case MailboxState_T::eLOC2:

        //Continue down

    case MailboxState_T::eLOC3:

        //Continue down

    case MailboxState_T::eRecovery_LOC:

        //Continue down

    case MailboxState_T::eRecovery:

        //Copy hash compare from RX message
        mTX.Set_HashCompare(mRX.HashCompare());

        //Create message structure
        TX_Message_Structure_Recovery_T * stTXmsg;
        mTX.encode_MessageStructure(*stTX_msg);

        //Copy to the TX buffer
        memcpy(cTX_Buf, stTX_msg, _TX_MESSAGE_LENGTH_RECOVERY);

        break;

    default:
        
        //Do nothing but return before clearing the TX_Buf_Ready flag
        return;
        break;
    }

    Set_TX_Buf_Ready(true); //Set bTX_Buf_Ready to pend the TX subprocess
    Clear_TX_Ready();       //Clear bTX_Ready as the message has now been processed
}

/*-------------------------------------------------------------------------------------------------
    RX_USB

    Primary subprocess for receiving a message from the master device over the Arduino's USB port.
    Will not execute unless one condition is met:

        1.  bRX_Event is set, which means that a serial event has been recorded.

    INPUT   --  NONE

    OUPUT (void)
*/
void Mailbox::RX_USB()
{
    //Check for nonexistant serial event
    if(!Check_RX_Event())
        return;
    
    unsigned long tCurrentCall;
    static unsigned long tPrevCall = 0;
    Letter_T lLetter;

    if(Check_Timeout()) //If a timeout has occured
    {
        //Update the timer
        tCurrentCall = millis();
        Update_TimeoutCounter(tCurrentCall - tPrevCall);
        tPrevCall = tCurrentCall;
        
        int nRX_Length = RX_USB(lLetter); //Record the length of the string that was read in

        if(nRX_Length && lLetter.nMessageLength == nRX_Length) //If the message reports its correct length
        {
            if(checkCRC(lLetter)) //If the CRC returns no errors
            {
                stMasterState = (MailboxState_T)lLetter.cMessageType   //Set the master's mailbox status to the message code
                
                //Set the expected RX message length
                if((stMasterState == MailboxState_T::eNormal) || (stMasterState == MailboxState_T::eStart))
                    nRX_Message_Length = _RX_MESSAGE_LENGTH_NORMAL;
                else
                    nRX_Message_Length = _RX_MESSAGE_LENGTH_RECOVERY;                
                
                memcpy(cRX_Buf, lLetter.cData, nRX_Message_Length);     //Copy the message to the RX buffer
                Set_RX_Buf_Ready(true);                                 //Set bRX_Buf_ready to pend Process_RX()
                
                Reset_TimeoutCounter(); //Reset the timeout counter
                
                return;
            }        
        }
    }
    
    induce_LOC(); //FLag Loss of Coms
}

/*-------------------------------------------------------------------------------------------------
    TX_USB

    Primary subprocess for transmitting a response message to the master device over the Arduino's
    USB port. Will not execute unless one condition is met:

        1.  bTX_Buf_Ready is set, which means that cTX_Buf has been populated with a processed TX
            message
    
    INPUT   --  NONE

    OUPUT (void)
*/
void Mailbox::TX_USB()
{
    //Check for a processed message within the TX buffer
    if(!TX_Buf_Ready())
        return;

    //Clear bTX_Buf_Ready to show that the message is being sent
    Set_TX_Buf_Ready(false);
    
    //Create and send a letter
    Letter_T lLetter;

    lLetter.cMessageType = cMailboxStatus;
    lLetter.nMessageLength = nTX_Message_Length + sizeof(lLetter) - sizeof(lLetter.cData);
    lLetter.cData = cTX_Buf;
    lLetter.nCRC = computeCRC(lLetter) & 0x7FFF;

    TX_USB(lLetter);
}

/*-------------------------------------------------------------------------------------------------
    TX_USB

    Secondary subprocess for transmitting a response message to the master device over the Arduino's
    USB port.

    INPUT (Letter_T)  --  lLetter
        A populated letter structure that needs to be transmitted. Passed by reference.

    OUPUT (void)
*/
void Mailbox::TX_USB(Letter_T & lLetter)
{
    Serial.write(lLetter.cMessageType);
    Serial.write(lLetter.nMessageLength);
    Serial.write(lLetter.cData);
    Serial.write(lLetter.nCRC);
    Serial.write(lLetter.nStopByte);
}