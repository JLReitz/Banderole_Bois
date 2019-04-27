#ifndef BB_STEPPER_H
#define BB_STEPPER_H

#include "TB_Stepper.h"

class Banderole_Stepper
{
public:

    //Public Functions
    Banderole_Stepper(const float fStepSize, int nPulsePin, int nDirectionPin, int nEnablePin);

    const float Get_CurrentPosition() const { return m_stepper.Get_CurrentSteps() * m_fStepSize; }

    void Set_Enable(const bool bEnable) { m_stepper.Set_Enable(bEnable); }

    void Set_TargetPosition(const float fPosition_Target);
    void Set_RPM(const float fRPM);

    void Initialize(int nNum);

private:

    //Private Members
    const float m_fStepSize;    //Step size in degrees
    float m_fRPM;                                 

    TB_Stepper m_stepper;
};

#endif