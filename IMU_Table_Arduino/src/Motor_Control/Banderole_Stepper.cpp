#include "Banderole_Stepper.h"

//  BanderoleStepper -- Public Functions    ///////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
    Constructor -- Default
*/
Banderole_Stepper::Banderole_Stepper(const float fStepSize, int nPulsePin, int nDirectionPin, int nEnablePin) :
    m_fStepSize(fStepSize),
    m_stepper(nPulsePin, nDirectionPin, nEnablePin)
{
}

/*-------------------------------------------------------------------------------------------------
    Set_TargetPosition

    Sets a new target position (in degrees) for the stepper motor.

    INPUT (float)   --  fPosition_Target
        The target position in degrees.

    OUTPUT (void)
*/
void Banderole_Stepper::Set_TargetPosition(const float fPosition_Target)
{
    //Calculate the number of steps required to acheive this
    float fDiff = fPosition_Target - Get_CurrentPosition();
    int nSteps = fDiff / m_fStepSize;

    //Step required amount
    m_stepper.Step(nSteps);
}

/*-------------------------------------------------------------------------------------------------
    Set_RPM
    
    Sets the rotational speed of the stepper in revolutions per minute.

    INPUT (float)   --  fRPM
        The new speed in revolutions per minute for the stepper to match.
    
    OUTPUT (void)
*/
void Banderole_Stepper::Set_RPM(const float fRPM)
{
    //Calculate maximum allowable RPM
    float fStepWindow = 2 * (.03);                          //Minimum allowable step-window size
    int nStepsPerRev = 360 / m_fStepSize;                   //Calculate steps per revolutions
    float fRPM_Allowed = 60 / (fStepWindow * nStepsPerRev); //Calculate maximum allowable RPM

    //Set new target RPM. Floor if too large for the hardware to support
    m_fRPM = (fRPM > fRPM_Allowed) ? fRPM_Allowed : fRPM;

    //Calculate the rotational speed in steps/s
    float fStepsPerSec = (m_fRPM * nStepsPerRev) / 60;

    m_stepper.Set_StepsPerSecond(fStepsPerSec);
}

/*-------------------------------------------------------------------------------------------------
    Initialize

    Initializes operation of the stepper by launching the task which automates it.

    INPUT (int) --  nNum
        Unique number with which to identify the stepper motor and its respective thread.

    OUTPUT (void)
*/
void Banderole_Stepper::Initialize(int nNum)
{
    m_stepper.Initialize(nNum);
}