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

  uint32_t Get_CurrentSteps() { return nSteps_Current; }
  
  void Set_Enable(const bool bEnable)                   { bEnabled = bEnable; } //TODO write to pin
  void Set_StepsPerSecond(const float fStepsPerSecond)  { this->fStepsPerSecond = fStepsPerSecond; }

  void Initialize(int nPulse, int nDirection, int nEnable);
  void Step(int steps);

  static void Set_Enable(TB_Stepper & stepperInstance, const bool bEnable);
  static void Set_StepsPerSecond(TB_Stepper & stepperInstance, const float fStepsPerSecond);

  //Tasks
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
