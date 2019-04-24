#include "TB_Stepper.h"

//  TB_Stepper -- Public Functions  ///////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
  Constructor -- Default
*/
TB_Stepper::TB_Stepper(int nPulsePin, int nDirectionPin, int nEnablePin) 
{
  nSteps_Current = 0;
  nSteps_Target = 0;

  this->nPulsePin = nPulsePin;
  this->nDirectionPin = nDirectionPin;
  this->nEnablePin = nEnablePin;

  pinMode(nPulsePin, OUTPUT);
  pinMode(nDirectionPin, OUTPUT);
  pinMode(nEnablePin, OUTPUT);
}


void TB_Stepper::Initialize()
{
    Serial.println("Beginning stepper task");

    BaseType_t ret;

    //Launch TB_Stepper task
    ret = xTaskCreate(Task_Step,      //Stepper thread
                "Step",                     //English name for humans. Is "Stepper#_Step" where # is the int value passed in
                configMINIMAL_STACK_SIZE,   //Minimum allowable stack depth
                this,                 //Pass in this stepper's instance to control it within the thread
                1,                          //Priority of 5
                NULL);                      //No task handle created

    if(ret == pdFAIL)
        Serial.println("Stepper task creation failed");
    else
        Serial.println("Stepper task creation success");
}

/*-------------------------------------------------------------------------------------------------
  Step

  Increments the number of steps for the stepper motor to complete.

  INPUT (int) --  nSteps
                  The number of steps for the motor to take. Adds on to what is currently left.
  
  OUTPUT (void)
*/
void TB_Stepper::Step(int nSteps) 
{
  this->nSteps_Target += nSteps;
}

/*-------------------------------------------------------------------------------------------------
  Task_Step

  Task which handles scheduling and timing for a TB_Stepper instance.

  INPUT (void *)  --  vParameters
                      Parameters to be passed to the task upon launch. Contains the address in
                      memory of the TB_Stepper instance to step upon operation of this thread.

  OUTPUT (void)
*/
void TB_Stepper::Task_Step(void * vParameters)
{
  Serial.println("Stepper task launched");

  volatile bool bPulse;
  volatile float fToggleDelay;
  TickType_t tLastWakeTime = xTaskGetTickCount();

  //Initialize stepper instance from the task parameters
  TB_Stepper * stepperInstance = (TB_Stepper *)vParameters;

  //Infinite Loop
  while(1)
  {
    //Toggle the pulse pin
    bPulse = stepperInstance->Toggle();

    //  Calculate the delay between each pulse toggle:
    //
    //    1. Time-between-each-step = 1 second / fStepsPerSecond
    //    2. Toggle delay (in seconds) = Time-Between-Each-Step / 2
    //    3. Toggle delay (in milliseconds) = Toggle delay (in seconds) * 1000
    //
    //  Do this only on high pulses so that each step window is split evenly (the delay only updates before the next step)
    //
    if(bPulse)
    {
      fToggleDelay = ((1 / stepperInstance->fStepsPerSecond) / 2) * 1000;

      //If the delay is smaller than a tick window, resize it to one tick
      fToggleDelay = (fToggleDelay < (1/configTICK_RATE_HZ)) ? (1/configTICK_RATE_HZ) : fToggleDelay;
    }
    
    //Delay the task until next toggle
    vTaskDelayUntil(&tLastWakeTime, pdMS_TO_TICKS((int)fToggleDelay));
  }
}

//  TB_STepper -- Private Functions ///////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
  Toggle

  Toggles the pulse pin associated with the TB driver to incrememnt the step count on this motor.

  INPUT (void)
  OUTPUT (void)
*/
bool TB_Stepper::Toggle()
{
  //  Boolean to keep track of which state the pulse pin is currently in
  //
  //  Each motor step has two phases:
  //    Low Pulse -- bToggle = false
  //    High Pulse -- bToggle = true
  //
  //  When disabled, bToggle will remain false in order to keep the pulse pin LOW
  //
  static bool bToggle = true;

  //Invert bToggle if the stepper is enabled, keep it the same if not
  bToggle = (bEnabled) ? ((bToggle) ? false : true) : bToggle;

  //  Determine the required state of the directional pin:
  //
  //    If going in the positive direction, the direction signal is LOW
  //    If going in the negative direction, the direction signal is HIGH
  //
  bool bDir = (nSteps_Target >= 0) ? false : true;
  digitalWrite(nDirectionPin, bDir);

  if(bEnabled || !bToggle)             //If the stepper is enabled or if the pulse pin needs to return to LOW
  {
    digitalWrite(nPulsePin, bToggle); //Write the toggle state to the pulse pin

    //Update the target steps and current steps if on the high pulse
    if(bToggle)
    {
      if(bDir)
      {
        nSteps_Target++;
        nSteps_Current--;
      }
      else
      {
        nSteps_Target--;
        nSteps_Current++;
      }
    }
  }

  return bToggle;
}
