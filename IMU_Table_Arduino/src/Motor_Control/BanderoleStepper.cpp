#include "BanderoleStepper.h"

//  BanderoleStepper -- Public Functions    ///////////////////////////////////////////////////////

BanderoleStepper::BanderoleStepper(const float sStepSize)
{
    this->fStepSize = fStepSize;
}

void BanderoleStepper::Set_TargetPosition(const float fPosition_Target)
{
    this->fPosition_Target = fPosition_Target;
}

void BanderoleStepper::Set_RPM(const float fRPM)
{
    this->fRPM = fRPM;
}

void BanderoleStepper::Initialize()
{
    
}