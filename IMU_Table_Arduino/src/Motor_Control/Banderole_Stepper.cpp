#include "Banderole_Stepper.h"

//  BanderoleStepper -- Public Functions    ///////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
    Constructor -- Default
*/
Banderole_Stepper::Banderole_Stepper(const float sStepSize)
{
    this->fStepSize = fStepSize;
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
    float fDiff = fPosition_Target - stepper.Get_CurrentPosition();
    int nSteps = (fPosition_Target - (int)fDiff) / fStepSize;

    //Step required amount
    stepper.step(nSteps);
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
    float fStepWindow = 2 * (1/configTICK_RATE_HZ);             //Minimum allowable step-window size
    float fRPM_Allowed = 166.66 * (fStepSize / fStepWindow);    //Maximum allowable RPM

    //Set new target RPM. Floor if too large for the hardware to support
    this->fRPM = (fRPM > fRPM_Allowed) ? fRPM_Allowed : fRPM;

    //Calculate the rotational speed in steps/s
    float fStepsPerSec = (this->fRPM / 60) * (360 / fStepSize);
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
    string sTaskName = "Stepper" + nNum + "_Step";

    //Launch TB_Stepper task
    xTaskCreate(TB_Stepper::Task_Step,  //Stepper thread
                sTaskName.c_str(),      //English name for humans. Is "Stepper#_Step" where # is the int value passed in
                0,                      //Minimum allowable stack depth
                &stepper,               //Pass in this stepper's instance to control it within the thread
                5,                      //Priority of 5
                NULL);                  //No task handle created
}