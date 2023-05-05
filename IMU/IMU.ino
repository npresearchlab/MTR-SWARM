/*
   Arduino and MPU6050 Accelerometer and Gyroscope Sensor Tutorial
   by Dejan, https://howtomechatronics.com
   Edited by Natasha Setiadi for NPRL
*/
#include <Wire.h>
#include "global_constants.h"

#define BYTE_SPLIT (3 + 32)
#define PIN_FSR   (0)


void setup() {
  Serial.begin(19200);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission
  /*
  // Configure Accelerometer Sensitivity - Full Scale Range (default +/- 2g)
  Wire.beginTransmission(MPU);
  Wire.write(0x1C);                  //Talk to the ACCEL_CONFIG register (1C hex)
  Wire.write(0x10);                  //Set the register bits as 00010000 (+/- 8g full scale range)
  Wire.endTransmission(true);
  // Configure Gyro Sensitivity - Full Scale Range (default +/- 250deg/s)
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);                   // Talk to the GYRO_CONFIG register (1B hex)
  Wire.write(0x10);                   // Set the register bits as 00010000 (1000deg/s full scale)
  Wire.endTransmission(true);
  delay(20);
  */
  // Call this function if you need to get the IMU error values for your module
  calculate_IMU_error();
  delay(20);
}


void loop() {  
  // Print the values on the serial monitor
  float accelxyz[ACCEL_COUNT];
  
  gyro_signals(accelxyz);
  
  //Loop through and send each measurement.
  for (int i = 0; i < ACCEL_COUNT; i++)
  {
    Serial.println("<0," + String(i) + "," + String(accelxyz[i]) + ">");
  }

  //Only for index finger right now.
  Serial.println("<1,1," + String(analogRead(PIN_FSR)) + ">");
}
