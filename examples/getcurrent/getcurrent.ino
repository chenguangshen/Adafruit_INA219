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

void loop(void) 
{
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  time = millis();
  
  //Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  //Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
   Serial.print(time);
   Serial.print(",");
   Serial.print(loadvoltage); 
   Serial.print(",");
   Serial.println(current_mA);
//  Serial.println(" V");
//  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
//Serial.println("");

//  delay(1000);
}
