#ifndef MESSAGE_STRUCTURE_H
#define MESSAGE_STRUCTURE_H

#ifdef __AVR__
#include <Arduino.h>
#endif
#ifdef _MAILBOX_EMULATOR
#include <stdint.h>
#endif

class CU_Message
{
public:

    //Structs
    typedef struct CU_Status_T
    {
        int bOperation_En   :   1,
            bMotor_x_En     :   1,
            bMotor_y_En     :   1,
            bMotor_z_En     :   1;
    };

    typedef struct CU_Message_Structure_Normal_T
    {
        /*
            Message structure for use during normal operations
            Size = 29 Bytes
        */

        //Header
        uint32_t nSequenceNum;  //4 Bytes
        CU_Status_T stStatus;   //1 Byte (4 bits)

        //Data
        float fPosition_x_cmd, fPosition_y_cmd, fPosition_z_cmd;    //12 Bytes (4 each)
        float fVelocity_x_cmd, fVelocity_y_cmd, fVelocity_z_cmd;    //12 Bytes (4 each)
    };

    typedef struct CU_Message_Structure_Recovery_T
    {
        /*
            Message structure for use during Recovery or Loss of Com stages
            Size = 9 Bytes
        */

        //Header
        uint32_t nSequenceNum;  //4 Bytes
        CU_Status_T stStatus;   //1 Byte (4 bits)

        //Data
        uint32_t nHashCompare;  //4 Bytes
    };

    //Public Functions
    CU_Message();
    CU_Message(CU_Message_Structure_Normal_T & stMessage);
    CU_Message(CU_Message_Structure_Recovery_T & stMessage);
    ~CU_Message();

	bool            Operation_En() const { return stStatus.bOperation_En; }
	bool            Motor_x_En()   const { return stStatus.bMotor_x_En; }
	bool            Motor_y_En()   const { return stStatus.bMotor_y_En; }
	bool            Motor_z_En()   const { return stStatus.bMotor_z_En; }

    unsigned long   SequenceNum() const { return nSequenceNum; }
    unsigned long   HashCompare() const { return nHashCompare; }

    float           Position_x_cmd() const  { return fPosition_x_cmd; }
    float           Position_y_cmd() const  { return fPosition_x_cmd; }
    float           Position_z_cmd() const  { return fPosition_x_cmd; }
    float           Velocity_x_cmd() const  { return fVelocity_x_cmd; }
    float           Velocity_y_cmd() const  { return fVelocity_x_cmd; }
    float           Velocity_z_cmd() const  { return fVelocity_x_cmd; }

	void    Set_SequenceNum(const unsigned long nNum) { nSequenceNum = nNum; }
	void    Set_HashCompare(const unsigned long nNum) { nHashCompare = nNum; }

	void	Set_Operation_En(const bool bSet)	{ stStatus.bOperation_En = bSet; }
	void	Set_Motor_x_En(const bool bSet)		{ stStatus.bMotor_x_En = bSet; }
	void	Set_Motor_y_En(const bool bSet)		{ stStatus.bMotor_y_En = bSet; }
	void	Set_Motor_z_En(const bool bSet)		{ stStatus.bMotor_z_En = bSet; }

	void    Set_Position_x_cmd(const float fCommand) { fPosition_x_cmd = fCommand; }
	void    Set_Position_y_cmd(const float fCommand) { fPosition_y_cmd = fCommand; }
	void    Set_Position_z_cmd(const float fCommand) { fPosition_z_cmd = fCommand; }
	void    Set_Velocity_x_cmd(const float fCommand) { fVelocity_x_cmd = fCommand; }
	void    Set_Velocity_y_cmd(const float fCommand) { fVelocity_y_cmd = fCommand; }
	void    Set_Velocity_z_cmd(const float fCommand) { fVelocity_z_cmd = fCommand; }

private:

    //Private Members
    unsigned long nSequenceNum, nHashCompare;
    float fPosition_x_cmd, fPosition_y_cmd, fPosition_z_cmd;
    float fVelocity_x_cmd, fVelocity_y_cmd, fVelocity_z_cmd;
    CU_Status_T stStatus;
};

class UUC_Message
{
public:

    //Structs
    typedef struct UUC_Status_T
    {
        int bOperating          :   1,
            bTaskInProgress  :   1,
            bTaskComplete    :   1;
    };

    typedef struct UUC_Message_Structure_Normal_T
    {
        /*
            Message structure for use during normal operations
            Size = 53 Bytes
        */

        //Header
        uint32_t nSequenceNum;  //4 Bytes
        UUC_Status_T stStatus;  //1 Byte

        //Data
        float fPosition_x_cmd, fPosition_y_cmd, fPosition_z_cmd;    //12 Bytes (4 each)
        float fVelocity_x_cmd, fVelocity_y_cmd, fVelocity_z_cmd;    //12 Bytes (4 each)
        float fPosition_x, fPosition_y, fPosition_z;                //12 Bytes (4 each)
        float fVelocity_x, fVelocity_y, fVelocity_z;                //12 Bytes (4 each)
    };

    typedef struct UUC_Message_Structure_Recovery_T
    {
        /*
            Message structure for use during Recovery or Loss of Com stages
            Size = 33
        */

        //Header
        uint32_t nSequenceNum;  //4 Bytes
        UUC_Status_T stStatus;  //1 Byte

        //Data
        float fPosition_x, fPosition_y, fPosition_z;                //12 Bytes (4 each)
        float fVelocity_x, fVelocity_y, fVelocity_z;                //12 Bytes (4 each)
        uint32_t nHashCompare;                                      //4 Bytes
    };

    //Public Functions
    UUC_Message();
	UUC_Message(UUC_Message_Structure_Normal_T & stMessage);
	UUC_Message(UUC_Message_Structure_Recovery_T & stMessage);
    ~UUC_Message();

	bool	Operating() const			{ return stStatus.bOperating; }
	bool	TaskInProgress() const	{ return stStatus.bTaskInProgress; }
	bool	TaskComplete() const		{ return stStatus.bTaskComplete; }

	unsigned long   SequenceNum() const { return nSequenceNum; }
	unsigned long   HashCompare() const { return nHashCompare; }

	float	Position_x_cmd() const	{ return fPosition_x_cmd; }
	float   Position_y_cmd() const	{ return fPosition_x_cmd; }
	float   Position_z_cmd() const	{ return fPosition_x_cmd; }
	float   Velocity_x_cmd() const	{ return fVelocity_x_cmd; }
	float   Velocity_y_cmd() const	{ return fVelocity_x_cmd; }
	float   Velocity_z_cmd() const	{ return fVelocity_x_cmd; }

	float	Position_x() const	{ return fPosition_x; }
	float   Position_y() const	{ return fPosition_x; }
	float   Position_z() const	{ return fPosition_x; }
	float   Velocity_x() const	{ return fVelocity_x; }
	float   Velocity_y() const	{ return fVelocity_x; }
	float   Velocity_z() const	{ return fVelocity_x; }

    void    Set_SequenceNum(const unsigned long nNum)   { nSequenceNum = nNum; }
    void    Set_HashCompare(const unsigned long nNum)   { nHashCompare = nNum; }

    void    Set_Operating(const bool bStatus)           { stStatus.bOperating = bStatus; }
    void    Set_CommandInProgress(const bool bStatus)   { stStatus.bTaskInProgress = bStatus; }
    void    Set_CommandComplete(const bool bStatus)     { stStatus.bTaskComplete = bStatus; }

    void    Set_Position_x_cmd(const float fCommand)    { fPosition_x_cmd = fCommand; }
    void    Set_Position_y_cmd(const float fCommand)    { fPosition_y_cmd = fCommand; }
    void    Set_Position_z_cmd(const float fCommand)    { fPosition_z_cmd = fCommand; }
    void    Set_Velocity_x_cmd(const float fCommand)    { fVelocity_x_cmd = fCommand; }
    void    Set_Velocity_y_cmd(const float fCommand)    { fVelocity_y_cmd = fCommand; }
    void    Set_Velocity_z_cmd(const float fCommand)    { fVelocity_z_cmd = fCommand; }

    void    Set_Position_x(const float fPosition)   { fPosition_x = fPosition; }
    void    Set_Position_y(const float fPosition)   { fPosition_y = fPosition; }
    void    Set_Position_z(const float fPosition)   { fPosition_z = fPosition; }
    void    Set_Velocity_x(const float fVelocity)   { fVelocity_x = fVelocity; }
    void    Set_Velocity_y(const float fVelocity)   { fVelocity_y = fVelocity; }
    void    Set_Velocity_z(const float fVelocity)   { fVelocity_z = fVelocity; }

    //Private Functions
    void encode_MessageStructure(UUC_Message_Structure_Normal_T & stTX);
    void encode_MessageStructure(UUC_Message_Structure_Recovery_T & stTX);

private:

    //Private Members
    unsigned long nSequenceNum, nHashCompare;
    float fPosition_x_cmd, fPosition_y_cmd, fPosition_z_cmd;
    float fVelocity_x_cmd, fVelocity_y_cmd, fVelocity_z_cmd;
    float fPosition_x, fPosition_y, fPosition_z;
    float fVelocity_x, fVelocity_y, fVelocity_z;
    UUC_Status_T stStatus;
};

#endif