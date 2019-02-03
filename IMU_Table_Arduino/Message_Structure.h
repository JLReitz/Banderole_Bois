#ifndef MESSAGE_STRUCTURE_H
#define MESSAGE_STRUCTURE_H

#include <string.h>

#define _RX_MESSAGE_LENGTH 41
#define _TX_MESSAGE_LENGTH 139

class RX_Message
{
public:

    typedef struct RX_Status_T
    {
        int bOperation_En   :   1,
            bMotor_x_En     :   1,
            bMotor_y_En     :   1,
            bMotor_z_En     :   1,
            bLOC            :   1;

        RX_Status_T & operator = (char N)
        {
            bOperation_En = (N & 0x01);
            bMotor_x_En = (N & 0x02);
            bMotor_y_En = (N & 0x04);
            bMotor_z_En = (N & 0x08);
            bLOC        = (N & 0x10);
        }
    };


    RX_Message();
    ~RX_Message();

    //Public Functions
    unsigned long   SequenceNum()       const   { return nSequenceNum; }

    bool            Operation_En()      const   { return stStatus.bOperation_En; }
    bool            Motor_x_en()        const   { return stStatus.bMotor_x_En; }
    bool            Motor_y_en()        const   { return stStatus.bMotor_y_En; }
    bool            Motor_z_en()        const   { return stStatus.bMotor_z_En; }
    bool            LOC()               const   { return stStatus.bLOC;}

    float           Position_x_cmd()    const   { return fPosition_x_cmd; }
    float           Position_y_cmd()    const   { return fPosition_x_cmd; }
    float           Position_z_cmd()    const   { return fPosition_x_cmd; }
    float           Velocity_x_cmd()    const   { return fVelocity_x_cmd; }
    float           Velocity_y_cmd()    const   { return fVelocity_x_cmd; }
    float           Velocity_z_cmd()    const   { return fVelocity_x_cmd; }
    float           Torque_x_cmd()      const   { return fTorque_x_cmd; }
    float           Torque_y_cmd()      const   { return fTorque_x_cmd; }
    float           Torque_z_cmd()      const   { return fTorque_x_cmd; }

    void decode_RX(char cBuff[]);

private:

    //Private Members
    unsigned long nSequenceNum;
    float fPosition_x_cmd, fPosition_y_cmd, fPosition_z_cmd;
    float fVelocity_x_cmd, fVelocity_y_cmd, fVelocity_z_cmd;
    float fTorque_x_cmd, fTorque_y_cmd, fTorque_z_cmd;
    RX_Status_T stStatus;
};

class TX_Message
{
public:

    typedef struct TX_Status_T
    {
        typedef struct TX_Flags_T
        {
            int bOverTemp       :   1,
                bOverVoltage    :   1,
                bOverCurrent    :   1,
                bOverVelocity   :   1,
                bOverTorque     :   1;
        };

        int bOperating          :   1,
            bCommandInProgress  :   1,
            bCommandComplete    :   1,
            bLOC                :   1;

        TX_Flags_T stFlags_x, stFlags_y, stFlags_z;
    };

    TX_Message();
    ~TX_Message();

    //Public Functions
    void    Set_SequenceNum         (const unsigned long nNum)  { nSequenceNum = nNum; }\

    void    Set_Operating           (const bool bStatus)        { stStatus.bOperating = bStatus; }
    void    Set_CommandInProgress   (const bool bStatus)        { stStatus.bCommandInProgress = bStatus; }
    void    Set_CommandComplete     (const bool bStatus)        { stStatus.bCommandComplete = bStatus; }
    void    Set_LOC                 (const bool bStatus)        { stStatus.bLOC = bStatus; }

    void    Set_OverTemp_x          (const bool bStatus)        { stStatus.stFlags_x.bOverTemp = bStatus; }
    void    Set_OverVoltage_x       (const bool bStatus)        { stStatus.stFlags_x.bOverVoltage = bStatus; }
    void    Set_OverCurrent_x       (const bool bStatus)        { stStatus.stFlags_x.bOverCurrent = bStatus; }
    void    Set_OverVelocity_x      (const bool bStatus)        { stStatus.stFlags_x.bOverVelocity = bStatus; }
    void    Set_OverTorque_x        (const bool bStatus)        { stStatus.stFlags_x.bOverTorque = bStatus; }

    void    Set_OverTemp_y          (const bool bStatus)        { stStatus.stFlags_y.bOverTemp = bStatus; }
    void    Set_OverVoltage_y       (const bool bStatus)        { stStatus.stFlags_y.bOverVoltage = bStatus; }
    void    Set_OverCurrent_y       (const bool bStatus)        { stStatus.stFlags_y.bOverCurrent = bStatus; }
    void    Set_OverVelocity_y      (const bool bStatus)        { stStatus.stFlags_y.bOverVelocity = bStatus; }
    void    Set_OverTorque_y        (const bool bStatus)        { stStatus.stFlags_y.bOverTorque = bStatus; }

    void    Set_OverTemp_z          (const bool bStatus)        { stStatus.stFlags_z.bOverTemp = bStatus; }
    void    Set_OverVoltage_z       (const bool bStatus)        { stStatus.stFlags_z.bOverVoltage = bStatus; }
    void    Set_OverCurrent_z       (const bool bStatus)        { stStatus.stFlags_z.bOverCurrent = bStatus; }
    void    Set_OverVelocity_z      (const bool bStatus)        { stStatus.stFlags_z.bOverVelocity = bStatus; }
    void    Set_OverTorque_z        (const bool bStatus)        { stStatus.stFlags_z.bOverTorque = bStatus; }

    void    Set_Position_x_cmd      (const float fCommand)      { fPosition_x_cmd = fCommand; }
    void    Set_Position_y_cmd      (const float fCommand)      { fPosition_y_cmd = fCommand; }
    void    Set_Position_z_cmd      (const float fCommand)      { fPosition_z_cmd = fCommand; }
    void    Set_Velocity_x_cmd      (const float fCommand)      { fVelocity_x_cmd = fCommand; }
    void    Set_Velocity_y_cmd      (const float fCommand)      { fVelocity_y_cmd = fCommand; }
    void    Set_Velocity_z_cmd      (const float fCommand)      { fVelocity_z_cmd = fCommand; }
    void    Set_Torque_x_cmd        (const float fCommand)      { fTorque_x_cmd = fCommand; }
    void    Set_Torque_y_cmd        (const float fCommand)      { fTorque_y_cmd = fCommand; }
    void    Set_Torque_z_cmd        (const float fCommand)      { fTorque_z_cmd = fCommand; }

    void    Set_Position_x          (const float fPosition)     { fPosition_x = fPosition; }
    void    Set_Position_y          (const float fPosition)     { fPosition_y = fPosition; }
    void    Set_Position_z          (const float fPosition)     { fPosition_z = fPosition; }
    void    Set_Velocity_x          (const float fVelocity)     { fVelocity_x = fVelocity; }
    void    Set_Velocity_y          (const float fVelocity)     { fVelocity_y = fVelocity; }
    void    Set_Velocity_z          (const float fVelocity)     { fVelocity_z = fVelocity; }
    void    Set_Torque_x            (const float fTorque)       { fTorque_x = fTorque; }
    void    Set_Torque_y            (const float fTorque)       { fTorque_y = fTorque; }
    void    Set_Torque_z            (const float fTorque)       { fTorque_z = fTorque; }
    void    Set_Temp_x              (const float fTemp)         { fTemp_x = fTemp; }
    void    Set_Temp_y              (const float fTemp)         { fTemp_y = fTemp; }
    void    Set_Temp_z              (const float fTemp)         { fTemp_z = fTemp; }
    void    Set_Voltage_x           (const float fVoltage)      { fVoltage_x = fVoltage; }
    void    Set_Voltage_y           (const float fVoltage)      { fVoltage_y = fVoltage; }
    void    Set_Voltage_z           (const float fVoltage)      { fVoltage_z = fVoltage; }
    void    Set_Current_x           (const float fCurrent)      { fCurrent_x = fCurrent; }
    void    Set_Current_y           (const float fCurrent)      { fCurrent_y = fCurrent; }
    void    Set_Current_z           (const float fCurrent)      { fCurrent_z = fCurrent; }
    void    Set_DiffDegrees_x       (const float fDiff)         { fDiffDegrees_x = fDiff; }
    void    Set_DiffDegrees_y       (const float fDiff)         { fDiffDegrees_y = fDiff; }
    void    Set_DiffDegrees_z       (const float fDiff)         { fDiffDegrees_z = fDiff; }
    void    Set_DiffSteps_x         (const float fDiff)         { fDiffSteps_x = fDiff; }
    void    Set_DiffSteps_y         (const float fDiff)         { fDiffSteps_y = fDiff; }
    void    Set_DiffSteps_z         (const float fDiff)         { fDiffSteps_z = fDiff; }

    void encode_TX(char cBuff[]) const;

private:

    //Private Members
    unsigned long nSequenceNum;
    float fPosition_x_cmd, fPosition_y_cmd, fPosition_z_cmd;
    float fVelocity_x_cmd, fVelocity_y_cmd, fVelocity_z_cmd;
    float fTorque_x_cmd, fTorque_y_cmd, fTorque_z_cmd;
    float fPosition_x, fPosition_y, fPosition_z;
    float fVelocity_x, fVelocity_y, fVelocity_z;
    float fTorque_x, fTorque_y, fTorque_z;
    float fTemp_x, fTemp_y, fTemp_z;
    float fVoltage_x, fVoltage_y, fVoltage_z;
    float fCurrent_x, fCurrent_y, fCurrent_z;
    float fDiffDegrees_x, fDiffDegrees_y, fDiffDegrees_z;
    float fDiffSteps_x, fDiffSteps_y, fDiffSteps_z;
    TX_Status_T stStatus;
};

#endif