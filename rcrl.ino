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
    unsigned int value = results.value; //Get the value of results as an unsigned int, so we can use switch case
    Serial.println(value);
    switch (value) {
      case 20655: 
      digitalWrite(4, 255);
      digitalWrite(6, 0);
      digitalWrite(9, 0);
      delay(500);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
        break;
      
      case 63495:
      digitalWrite(4, 0);
      digitalWrite(6, 0);
      digitalWrite(9, 255);
      delay(500);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
        break;
      
      case 55335:
      digitalWrite(4, 0);
      digitalWrite(6, 255);
      digitalWrite(9, 0);
      delay(500);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
        break;
      
      case 12495:
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(9, HIGH);
      delay(500);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
        break;

      case 2103:
      digitalWrite(4, 245);
      digitalWrite(6, 242);
      digitalWrite(9, 66);
      delay(500);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
        break;
      
      case 55:
      digitalWrite(4, 245);
      digitalWrite(6, 242);
      digitalWrite(9, 66);
      delay(500);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      digitalWrite(9, LOW);
    }
    
    
    irrecv.resume(); // Receive the next value
  }
}
