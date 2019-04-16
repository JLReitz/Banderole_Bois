#include "BanderoleStepper.h"

//  BanderoleStepper -- Public Functions    ///////////////////////////////////////////////////////

BanderoleStepper::BanderoleStepper(const float sStepSize)
{
    this->fStepSize = fStepSize;
}

void BanderoleStepper::Set_TargetPosition(const float fPosition_Target)
{
    //Set the new target position
    this->fPosition_Target = fPosition_Target;

    //Calculate the number of steps required to acheive this
    int nSteps = (fPosition_Target - Get_CurrentPosition()) / fStepSize;

    //Enable the stepper if there is a distance to travel
    if(nSteps)
        stepper.Set_Enable(true);
    else
        stepper.Set_Enable(false);

    //Step required amount
    stepper.step(nSteps);
}

void BanderoleStepper::Set_RPM(const float fRPM)
{
    //Calculate maximum allowable RPM
    float fStepWindow = 2 * (1/configTICK_RATE_HZ);             //Minimum allowable step-window size
    float fRPM_Allowed = 166.66 * (fStepSize / fStepWindow);    //Maximum allowable RPM

    //Set new target RPM. Floor if too large for the hardware to support
    this->fRPM = (fRPM > fRPM_Allowed) ? fRPM_Allowed : fRPM;

    //Calculate the rotational speed in steps/s
    float fStepsPerSec = (this->fRPM / 60) * (360 / fStepSize);
}

void BanderoleStepper::Initialize()
{
    
}