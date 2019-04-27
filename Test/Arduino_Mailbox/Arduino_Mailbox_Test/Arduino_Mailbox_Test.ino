#include "src/Arduino_freeRTOS/Arduino_FreeRTOS.h"
#include "src/Arduino_freeRTOS/task.h"
#include "src/Arduino_freeRTOS/semphr.h"

#include "ArduinoMailbox.h"

void Task_Main(void * vParameters)
{
  ArduinoMailbox::Initialize();

  while(1)
  {
    
  }
}

void setup() 
{
  Serial.begin(115200);
  
  //Launch tasks
  xTaskCreate(Task_Main,  //Main Thread
              "Main",     //English name for humans
              100,        //Stack depth of 100 layers
              NULL,       //No parameters passed in
              1,          //Priority of 1
              NULL);      //No handle for this task
              
  //Start scheduler to begin task execution
  vTaskStartScheduler();
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
