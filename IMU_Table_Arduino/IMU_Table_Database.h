#ifndef IMU_TABLE_DATABASE
#define IMU_TABLE_DATABASE

#include "IMU_Table_3Axis_Control.h"
#include "ArduinoMailbox.h"

class IMU_Table_Database
{
public:

    //Public Functions
    void Update();

private:

    //Private Members
    bool boperation_En_Cmd, bMotor_x_En_Cmd, bMotor_y_En_Cmd, bMotor_z_En_Cmd;
    bool bOperation_En, bTaskInProgress, bTaskComplete;
    float fStepper_x_Position, fStepper_y_Position, fStepper_z_Position;
    float fStepper_x_Position_Cmd, fStepper_y_Position_Cmd, fStepper_z_Position_Cmd;
    float fStepper_x_Velocity, fStepper_y_Velocity, fStepper_z_Velocity;
    float fStepper_x_Velocity_Cmd, fStepper_y_Velocity_Cmd, fStepper_z_Velocity_Cmd;

    RX_Message rx;
    TX_Message tx;
};

#endif