#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
unsigned long time;

void setup(void) 
{
  uint32_t currentFrequency;
    
  Serial.begin(115200);
  //Serial.println("Hello!");
  
  //Serial.println("Measuring voltage and current with INA219 ...");
  while (Serial.available() <= 0) {
  
  }
  
  ina219.begin();
}

float shuntvoltage;
float busvoltage;
float current_mA;
float loadvoltage;

void loop(void) 
{
  shuntvoltage = 0;
  busvoltage = 0;
  current_mA = 0;
  loadvoltage = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  time = millis();
  Serial.print(time);
  Serial.print(",");
  Serial.print(loadvoltage); 
  Serial.print(",");
  Serial.println(current_mA);
  
  // Too fast makes the plotting script lag.
  delay(100);
}
