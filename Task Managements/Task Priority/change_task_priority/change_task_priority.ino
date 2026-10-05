
#define  RED     2
#define  BLUE    3
#define  YELLOW  21 

typedef int TaskProfiler;

TaskProfiler REDLEDProfiler;
TaskProfiler BLUELEDProfiler;
TaskProfiler YELLOWLEDProfiler;

void setup() {
  Serial.begin(115200);
  xTaskCreate(redLedControllerTask, "red led task", 1024,NULL,1,NULL);
  xTaskCreate(blueLedControllerTask, "blue led task", 1024,NULL,1,NULL);
  xTaskCreate(yellowLedControllerTask, "yellow led task", 1024,NULL,1,NULL);
}

void redLedControllerTask(void *pvParameter)
{
  pinMode(RED,OUTPUT);
  while(1)
  {
    digitalWrite(RED,digitalRead(RED)^1);
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}


void blueLedControllerTask(void *pvParameter)
{
  pinMode(BLUE,OUTPUT);
  while(1)
  {
    digitalWrite(BLUE,digitalRead(BLUE)^1);
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void yellowLedControllerTask(void *pvParameter)
{
  pinMode(YELLOW,OUTPUT);
  while(1)
  {
    digitalWrite(YELLOW,digitalRead(YELLOW)^1);
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}


void loop() {}
