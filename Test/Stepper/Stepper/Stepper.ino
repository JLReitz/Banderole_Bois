#include "src/Motor_Control/Banderole_Stepper.h"

Banderole_Stepper stepper((float)1.8, 2, 3, 4);

void Task_Main(void * vParameters)
{
  Serial.println("Main task launched");
  
  float fCurrentPos;
  
  stepper.Initialize(1);
  stepper.Set_RPM(.01);
  stepper.Set_Enable(true);

  while(1)
  {
    Serial.println("Main task iteration");
    
    fCurrentPos = stepper.Get_CurrentPosition();
    Serial.print("Current Position: ");
    Serial.println(fCurrentPos);
    
    if(fCurrentPos < 180)
      stepper.Set_TargetPosition(180);
    else
      stepper.Set_TargetPosition(0);

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
