#ifndef MAILBOX_H
#define MAILBOX_H

#ifdef _MAILBOX_EMULATOR
#include <String>
using namespace std;
#endif

#include "Message_Structure.h"

#ifdef __AVR__

#define _RX_MESSAGE_LENGTH_NORMAL   53
#define _RX_MESSAGE_LENGTH_RECOVERY 33
#define _TX_MESSAGE_LENGTH_NORMAL   29
#define _TX_MESSAGE_LENGTH_RECOVERY 9

typedef CU_Message RX_Message;
typedef UUC_Message TX_Message;

#endif
#ifdef _MAILBOX_EMULATOR

#define _TX_MESSAGE_LENGTH_NORMAL   29
#define _TX_MESSAGE_LENGTH_RECOVERY 9
#define _RX_MESSAGE_LENGTH_NORMAL   53
#define _RX_MESSAGE_LENGTH_RECOVERY 33

typedef CU_Message TX_Message;
typedef CU_Message::CU_Status_T TX_Status_T;
typedef CU_Message::CU_Message_Structure_Normal_T TX_Message_Structure_Normal_T;
typedef CU_Message::CU_Message_Structure_Recovery_T TX_Message_Structure_Recovery_T;

typedef UUC_Message RX_Message;
typedef UUC_Message::UUC_Status_T RX_Status_T;
typedef UUC_Message::UUC_Message_Structure_Normal_T RX_Message_Structure_Normal_T;
typedef UUC_Message::UUC_Message_Structure_Recovery_T RX_Message_Structure_Recovery_T;

#endif

#define HI_16(x)    ((x) & 0xFF00)
#define LO_16(x)    ((x) & 0x00FF)
#define HI_32(x)    ((x) & 0xFFFF0000)
#define LO_32(x)    ((x) & 0x0000FFFF)

#define MERGE_16(hi, lo)    ((((hi) & 0x00FF) << 8) + ((lo) & 0x00FF))
#define MERGE_32(hi, lo)    ((((hi) & 0x0000FFFF) << 16) + ((lo) & 0x0000FFFF))

#define _LETTER_LENGTH	8

#define _LOC_TIMEOUT_MS 100
/* The timeout threshold for communications in milliseconds ///////////////////////////////////////

	If the amount of time specified above (in ms) is reached without a proper message being
	received, the mailbox state will divert into Loss of Communications.
*/

class MailBox
{
public:

    //Structs
    typedef enum class MailboxState_T
    {
        eNormal         =   0x10,

        //Loss of Com states
        eLOC_1          =   0x11,
        eLOC_2          =   0x12,
        eLOC_3          =   0x13,

        //Recovery states
        eRecovery       =   0x18,
        eRecovery_LOC   =   0x19,

        //Startup phase
        eStart          =   0xAA
    };    

    //Public Functions
    MailBox();
    ~MailBox();

    RX_Message & Get_RX()   { return mRX; }

    MailboxState_T MailboxState() const { return stTXState; }

    void Set_Recovery() { stTXState = MailboxState_T::eRecovery; }

    void Set_TX(TX_Message & oTX)    
    {
        //Set TX_Ready to true to show that a new message has been set
        bStartup = false;
        mTX = oTX;
    }

protected:

    //Protected Structs
    typedef struct Letter_T
    {
		/*
			Envelope which contains headers for the mailbox messaging system.
			Size (not including the actual message) = 8 Bytes
		*/

        //Message header
        uint32_t nSequenceNum;  //4 Bytes
        uint8_t cMessageType;	//1 Byte
        uint8_t nMessageLength;	//1 Byte

        //Data
        string sMessage;
        uint8_t nCRC : 15;	//1 Byte

        //Stop byte
        const uint8_t nStopByte = 0xE7;	//1 Byte
    };
    
    //Protected Functions
    MailboxState_T updateStateMachine();

    void Induce_LOC()   { bLOC_Induced = true; }
    void Process_RX();
    void Process_TX();
    void RX();
    void TX();

    //Protected Members
    uint8_t nTX_Message_Length, nRX_Message_Length;   //Dynamic message size depending on the mailbox status
    uint8_t nBytesReceived, nBytesSent;
    uint32_t nRXSequenceNum, nTXSequenceNum;

private:

    //Private Functions
    bool is_LOC(MailboxState_T stState)
    {
        if(stState == MailboxState_T::eLOC_1 ||
           stState == MailboxState_T::eLOC_2 ||
           stState == MailboxState_T::eLOC_3 ||
           stState == MailboxState_T::eRecovery_LOC)
            return true;
        else
            return false;
    }

    bool checkCRC(Letter_T & lLetter);

    uint8_t computeCRC(Letter_T & lLetter);
    uint8_t computeCRC(char * cStr, int nLen);
    
    virtual void RX_Specific(Letter_T & lLetter) = 0;    //Pure virtual function to define the RX subroutine specific to the supporting platform
    virtual void TX_Specific(Letter_T & lLetter) = 0;    //Pure virtual function to define the TX subroutine specific to the supporting platform

    //Private Members                                          //Flags for message timing
    bool bLOC_Induced, bStartup;
    char cRX_Buf[_RX_MESSAGE_LENGTH_NORMAL], cTX_Buf[_TX_MESSAGE_LENGTH_NORMAL];    //Char buffers for serial messaging

    MailboxState_T stTXState, stRXState;
    RX_Message mRX;                                 //RX Message structure
    TX_Message mTX;                                 //TX Message structure
};

#endif
