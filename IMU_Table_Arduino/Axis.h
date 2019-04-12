#ifndef AXIS_H
#define AXIS_H

class Axis
{
public:

    //Public Functions
    Axis();
    ~Axis();

    void Set_Position_cmd(const float fCommand)   { fPosition_cmd = fCommand; }
    void Set_Velocity_cmd(const float fCommand)   { fVelocity_cmd = fCommand; }
    void Set_Torque_cmd(const float fCommand)     { fTorque_cmd = fCommand; }

    float Position()    { return fPosition; }
    float Velocity()    { return fVelocity; }
    float Torque()      { return fTorque; }

private:

    float fPosition, fPosition_cmd;
    float fVelocity, fVelocity_cmd;
    float fTorque, fTorque_cmd;
};

#endif