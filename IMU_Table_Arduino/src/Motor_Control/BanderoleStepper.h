#ifndef BB_STEPPER_H
#define BB_STEPPER_H

#include "TB_Stepper.h"

class BanderoleStepper
{
public:

    //Public Functions
    BanderoleStepper(const float fStepSize);

    const float Get_CurrentPosition() const { return stepper.Get_CurrentPosition() * fStepSize; }

    void Set_Enable(const bool bEnable) { stepper.Set_Enable(bEnable); }

    void Set_TargetPosition(const float fPosition_Target);
    void Set_RPM(const float fRPM);

    void Initialize();

private:

    //Private Members
    const float fStepSize;    //Step size in degrees
    float fPosition_Target;  //Angular position of stepper in degrees
    float fRPM;                                 

    TB_Stepper stepper;
};

#endif