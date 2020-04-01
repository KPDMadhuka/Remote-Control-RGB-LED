#include <IRremote.h>  
int i = 0;
IRrecv irrecv(2);
decode_results results;

void setup()
{
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
    //Enable serial usage and IR signal in
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); 
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {//irrecv.decode(&results) returns true if anything is recieved, and stores info in varible results
    long int value = results.value; //Get the value of results as an unsigned int, so we can use switch case
    Serial.println(value);
    switch (value) {
      //button 1      
      case 33444015: 
      digitalWrite(4, 255);
      digitalWrite(6, 0);
      digitalWrite(9, 0);
        break;
        
      //button 2
      case 33478695:
      digitalWrite(4, 0);
      digitalWrite(6, 255);
      digitalWrite(9, 0);
        break;
        
      //button 3
      case 33486855:
      digitalWrite(4, 0);
      digitalWrite(6, 0);
      digitalWrite(9, 255);
        break;
        
      //button 4
      case 33435855:
      digitalWrite(4, 100);
      digitalWrite(6, 0);
      digitalWrite(9, 100);
        break;
        
      //button 5 
      case 33468495:
      digitalWrite(4, 100);
      digitalWrite(6, 100);
      digitalWrite(9, 0);
        break;
        
      //button 6
      case 33452175:
      digitalWrite(4, 0);
      digitalWrite(6, 100);
      digitalWrite(9, 100);
        break;
        
      //button Power OFF        
      case 33441975:
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
        break;
    }
    
    
    irrecv.resume(); // Receive the next value
  }
}
