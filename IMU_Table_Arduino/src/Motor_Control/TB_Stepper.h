#ifndef TB_STEPPER_H
#define TB_STEPPER_H

#include <Arduino.h>
#include <stdint.h>

#include "..//Arduino_freeRTOS/Arduino_FreeRTOS.h"
#include "..//Arduino_freeRTOS/task.h"

class TB_Stepper 
{
public:

  //Public Functions
  TB_Stepper();

  bool Get_Enabled() const  { return bEnabled; }

  uint32_t Get_CurrentSteps() { return nSteps_Current; }
  
  void Set_Enable(const bool bEnable)                  
  { 
    bEnabled = bEnable;
    digitalWrite(nEnablePin, bEnabled);
  }

  void Set_StepsPerSecond(const float fStepsPerSecond)  { this->fStepsPerSecond = fStepsPerSecond; }

  void Initialize(int nPulse, int nDirection, int nEnable);
  void Step(int steps);

  static void Task_Step(void * vParameters);

private:

  //Private Functions
  bool Toggle();

  //Private Members
  bool bEnabled;
  int nPulsePin, nDirectionPin, nEnablePin;
  uint32_t nSteps_Current, nSteps_Target;
  float fStepsPerSecond;

};

#endif
