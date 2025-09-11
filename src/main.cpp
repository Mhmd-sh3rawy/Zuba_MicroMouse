#include <Arduino.h>

const int ulmPIn = 0;
const int reciever = 12; 
const int IRloadTime = 25;
int IRraw_read = 0;


void setup(){ 
  pinMode(ulmPIn, OUTPUT);
  pinMode(reciever, INPUT);
  Serial.begin(115200);  
}


void loop(){ 
  IRraw_read = analogRead(reciever);
  Serial.println(IRraw_read);

}

void rawReadDebounced(){
  unsigned long current_time = millis();

  if(millis() - current_time >= IRloadTime){
    IRraw_read = analogRead(reciever);
  }

}