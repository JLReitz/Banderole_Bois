#ifndef IMU_TABLE_3AXIS_CONTROL_H
#define IMU_TABLE_3AXIS_CONTROL_H

#include "src/Motor_Control/Banderole_Stepper.h"

class TripleAxis_Control
{
public:

    //Public Functions
    bool Get_Stepper_x_En() const   { return stepper_x.Get_Enabled(); }
    bool Get_Stepper_y_En() const   { return stepper_y.Get_Enabled(); }
    bool Get_Stepper_z_En() const   { return stepper_z.Get_Enabled(); }

    float Get_Position_x() const    { return stepper_x.Get_CurrentPosition(); }
    float Get_Position_y() const    { return stepper_y.Get_CurrentPosition(); }
    float Get_Position_z() const    { return stepper_z.Get_CurrentPosition(); }

    void Set_Position_x(const float fPosition)  { stepper_x.Set_TargetPosition(fPosition); }
    void Set_Position_y(const float fPosition)  { stepper_y.Set_TargetPosition(fPosition); }
    void Set_Position_z(const float fPosition)  { stepper_z.Set_TargetPosition(fPosition); }
    void Set_Stepper_x_En(const bool bSet)      { stepper_x.Set_Enable(bSet); }
    void Set_Stepper_y_En(const bool bSet)      { stepper_y.Set_Enable(bSet); }
    void Set_Stepper_z_En(const bool bSet)      { stepper_z.Set_Enable(bSet); }
    void Set_Velocity_x(const float fRPM)       { stepper_x.Set_RPM(fRPM); }
    void Set_Velocity_y(const float fRPM)       { stepper_y.Set_RPM(fRPM); }
    void Set_Velocity_z(const float fRPM)       { stepper_z.Set_RPM(fRPM); }

private:

    //Private Members
    Banderole_Stepper stepper_x, stepper_y, stepper_z;
};

#endif