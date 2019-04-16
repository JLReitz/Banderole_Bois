#include "IMU_Table_Database.h"

//  IMU_Table_Database -- Public Functions  -------------------------------------------------------

voud IMU_TABLE_DATABASE::Update()
{
    //If the ArduinoMailbox has received an RX message, update CU information
    if(xSemaphoreTake(ArduinoMailbox::RX_Ready(), 0) == pdPASS)
    {
        rx = ArduinoMailbox::Get_RX();

        //Sequence number and hashcompare
        nSequenceNum = 

        //RX Status bits
        boperation_En_Cmd = rx.Operation_En();
        bMotor_x_En_Cmd = rx.Motor_x_En();
        bMotor_y_En_Cmd = rx.Motor_y_En();
        bMotor_z_En_Cmd = rx.Motor_z_En();

        //Position command data

    }
}