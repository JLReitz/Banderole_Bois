#ifndef TB_STEPPER_H
#define TB_STEPPER_H

#include <Arduino.h>
#include <stdint.h>

#include "../Arduino_freeRTOS/Arduino_FreeRTOS.h"
#include "../Arduino_freeRTOS/task.h"

class TB_Stepper 
{
public:

  //Public Functions
  TB_Stepper(int nPulsePin, int nDirectionPin, int nEnablePin);

  bool Get_Enabled() const  { return bEnabled; }

  int Get_CurrentSteps() { return nSteps_Current; }
  
  void Set_Enable(const bool bEnable)                  
  { 
    bEnabled = bEnable;
    digitalWrite(nEnablePin, bEnabled);
  }

  void Set_StepsPerSecond(const float fStepsPerSecond)  { this->fStepsPerSecond = fStepsPerSecond; }

  void Initialize(int nNum);
  void Step(int steps);

  static void Task_Step(void * vParameters);

private:

  //Private Functions
  bool Toggle();

  //Private Members
  bool bEnabled;
  int nPulsePin, nDirectionPin, nEnablePin;
  int nSteps_Current, nSteps_Target;
  float fStepsPerSecond;

};

#endif
