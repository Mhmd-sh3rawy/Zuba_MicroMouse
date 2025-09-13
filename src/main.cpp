/*#include <Arduino.h>

#define IR1_PIN 36
#define IR2_PIN 39
#define IR3_PIN 23
#define IR4_PIN 22

void setup() {
  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);
  pinMode(IR3_PIN, INPUT);
  pinMode(IR4_PIN, INPUT);
  Serial.begin(115200); 
}

void loop() {
  uint8_t IR_PINS[4] = {IR1_PIN, IR2_PIN, IR3_PIN, IR4_PIN};
  for(int i=0; i<4; i++){
    int reading = digitalRead(IR_PINS[i]);
    Serial.print(" Reading from sensor ");
    Serial.print(i);
    Serial.print(" ");
    Serial.println(reading);
  }
  Serial.println("---------------");
  delay(1000);
}*/

/*
#include <Arduino.h>
#include <Wire.h>
 
#define I2C_Freq 100000
#define SDA_0 21
#define SCL_0 22
 
TwoWire I2C_0 = TwoWire(0);
 
void setup()
{
  Serial.begin(115200);
  I2C_0.begin(SDA_0 , SCL_0 , I2C_Freq);
}
 
void loop() 
{
  byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    I2C_0.beginTransmission(address);
    error = I2C_0.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
 
  delay(5000);           // wait 5 seconds for next scan
}*/

#include <Arduino.h>
#include <SteerBot_TB6612.h>

const int AIN1 = 13;
const int AIN2 = 12;
const int BIN1 = 14;
const int BIN2 = 15;
int speed = 155; 
const int ENA = 16;
const int ENB = 17;
int r;  

// Create an instance of the SteerBot-TB6612 class for QCTT
SteerBot_TB6612 QCTT(ENA, ENB, AIN1, AIN2, BIN1, BIN2, speed);
void setup() {
  //pinMode(3, INPUT); // Line sensors
  //pinMode(10, INPUT);
  //pinMode(6, INPUT); // IR distance sensor

  // Speed control
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // Outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  QCTT.Backward(1000,255,15);

  QCTT.Stop(1000);
}