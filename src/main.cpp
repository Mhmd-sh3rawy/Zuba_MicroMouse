#include <Arduino.h>

#define RECEIVER_IR 12
#define EMMITTER_PIN 36
int reading = 0;

#define FREQ 5000 
#define DUTY_CYCLE 64
#define CHANNEL 0
#define RESOLUTION 8 

unsigned long irReload = 125;

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
  readIR();
}

void readIR(){
  unsigned long current_time = millis();

  if(millis() - current_time >= irReload){
    reading = analogRead(RECEIVER_IR);
    current_time = millis();
    Serial.println(reading); 
  }

}

void enEmmitter(){ 
  ledcWrite(CHANNEL, 64);
}