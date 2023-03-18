/*
   Arduino and MPU6050 Accelerometer and Gyroscope Sensor Tutorial
   by Dejan, https://howtomechatronics.com
   Edited by Natasha Setiadi for NPRL
*/

int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrReading;      // the analog reading from the FSR resistor divider


void setup() {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
}


void loop() {  
  fsrReading = analogRead(fsrAnalogPin);
 
  Serial.println("<0," + String(fsrReading) + ">");
 
  delay(100);
}
