#include <Arduino.h>

#define RECEIVER_IR 32
#define EMMITTER_PIN 23
int reading = 0;

#define FREQ 2 
#define DUTY_CYCLE 64
#define CHANNEL 0
#define RESOLUTION 8 

unsigned long irReload = 100;
int current_time = millis();

void readIR();
void enEmmitter();

void setup(){ 
  Serial.begin(115200);
  pinMode(RECEIVER_IR, INPUT);
  pinMode(EMMITTER_PIN, OUTPUT);
  ledcSetup(CHANNEL, FREQ, RESOLUTION);
  ledcAttachPin(EMMITTER_PIN, CHANNEL); 
}

void loop(){
  //Serial.println("IGlol");
  ledcWrite(CHANNEL, 64);

  if(millis() - current_time >= irReload){
    reading = analogRead(RECEIVER_IR);
    current_time = millis();
    Serial.println(reading); 
  }
}

void readIR(){
  

}

void enEmmitter(){ 
  
}