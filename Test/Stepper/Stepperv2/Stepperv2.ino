#include "src/Motor_Control/Banderole_Stepper.h"

Banderole_Stepper stepper1(.036, 10, 9, 8);
Banderole_Stepper stepper2(.036, 7, 6, 5);
Banderole_Stepper stepper3(.036, 4, 3, 2);

void Task_Main(void * vParameters)
{
  Serial.println("Main task launched");

  bool bUp1 = true;
  bool bUp2 = false;
  float fCurrentPos1, fCurrentPos2, fCurrentPos3;
  
  stepper1.Set_RPM(1);
  stepper1.Set_TargetPosition(-15);
  stepper1.Set_Enable(true);
  
  stepper2.Set_RPM(1);
  stepper2.Set_TargetPosition(180);
  stepper2.Set_Enable(true);

  stepper3.Set_RPM(1);
  stepper3.Set_TargetPosition(90);
  stepper3.Set_Enable(true);

  stepper1.Initialize(1);
  stepper2.Initialize(2);
  stepper3.Initialize(3);

  while(1)
  {
    fCurrentPos1 = stepper1.Get_CurrentPosition();
    Serial.print("Current Position 1: ");
    Serial.println(fCurrentPos1);
    
    fCurrentPos2 = stepper2.Get_CurrentPosition();
    Serial.print("Current Position 2: ");
    Serial.println(fCurrentPos2);

    fCurrentPos3 = stepper3.Get_CurrentPosition();
    Serial.print("Current Position 3: ");
    Serial.println(fCurrentPos3);

    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

void setup() 
{
  Serial.begin(9600);

  BaseType_t ret;
  // put your setup code here, to run once:
  ret = xTaskCreate(Task_Main,  //Main Thread
              "Main",     //English name for humans
              configMINIMAL_STACK_SIZE,        //Stack depth of 100 layers
              NULL,       //No parameters passed in
              1,          //Priority of 1
              NULL);      //No handle for this task

  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
}
