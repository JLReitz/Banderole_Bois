#include "src/Motor_Control/Banderole_Stepper.h"

Banderole_Stepper stepper1(.225, 2, 7, 4);
Banderole_Stepper stepper2(.225, 8, 10, 12);

void Task_Main(void * vParameters)
{
  Serial.println("Main task launched");

  bool bUp = true;
  float fCurrentPos1, fCurrentPos2;
  
  stepper1.Set_RPM(.5);
  stepper1.Set_TargetPosition(-180);
  stepper1.Set_Enable(true);

  stepper2.Set_RPM(1.25);
  stepper2.Set_TargetPosition(-360);
  stepper2.Set_Enable(true);
  
  stepper1.Initialize(1);
  stepper2.Initialize(2);

  while(1)
  {
    fCurrentPos1 = stepper1.Get_CurrentPosition();
    Serial.print("Current Position 1: ");
    Serial.println(fCurrentPos1);

    fCurrentPos2 = stepper2.Get_CurrentPosition();
    Serial.print("Current Position 2: ");
    Serial.println(fCurrentPos2);

    /*
    if(fCurrentPos >= 180 && bUp)
    {
      stepper.Set_Enable(false);
      vTaskDelay(pdMS_TO_TICKS(5000));
      Serial.println("Going down");
      stepper.Set_TargetPosition(0);
      stepper.Set_Enable(true);
      bUp = false;
    }
    else if(fCurrentPos <= 0 && !bUp)
    {
      stepper.Set_Enable(false);
      vTaskDelay(pdMS_TO_TICKS(5000));
      Serial.println("Going up");
      stepper.Set_TargetPosition(180);
      stepper.Set_Enable(true);
      bUp = true;
    }
    */

    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

void setup() 
{
  Serial.begin(9600);

  Serial.println("Beginning Main Task");

  BaseType_t ret;
  // put your setup code here, to run once:
  ret = xTaskCreate(Task_Main,  //Main Thread
              "Main",     //English name for humans
              configMINIMAL_STACK_SIZE,        //Stack depth of 100 layers
              NULL,       //No parameters passed in
              1,          //Priority of 1
              NULL);      //No handle for this task

  if(ret == pdFAIL)
    Serial.println("Main task creation failed");
  else
    Serial.println("Main task creation success");

  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
}
