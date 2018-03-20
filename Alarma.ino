/*
*Instituto Tecnologíco de León
*Last Modification: March 13th, 2018
*Objective of the program: the objective of the program is to simulate an alarm using a REED SWITCH and a BUZZER.
 If the magnetic field of the REED SWITCH is interfered with by some signal, it sends a signal to the BUZZER and the LED so that it
 turn on simulating the alarm with sound and light.
*/

int led = 13; //variable of the LED initialized in 13
int reedswitch = 5; //variable of the REED SWITCH initialized in 5
int buzzer = 8; //variable of the BUZZER initialized in 8
int val = 0; 

// the method setup Configures the specified pin to behave either as an input or an output
void setup(){
  pinMode(led, OUTPUT); //configure the LED pin to behave like an output 
  pinMode(reedswitch, INPUT); //configure the REED SWITCH pin to behave like an input
  pinMode(buzzer, OUTPUT); //configure the BUZZER pin to behave like an output 
}

/* the loop method is responsible for validating if the value of the REED SWHITCH is in the LOW state, 
if it is true it changes the pins of the LED and from the BUZZER to HIGH,
in case the REED SWITCH pin is in the HIGH state, change the LED and BUZZER pins to LOW
*/
void loop(){
  val = digitalRead(reedswitch); //the variable "val" take the value of the pin of the REED SWITHC
  if(val == LOW){ //the clausule IF, check if the value of the variable "val" is equal to LOW
    digitalWrite(led, HIGH); // then the pin of the LED take the value HIGH
    digitalWrite(buzzer, HIGH); // then the pin of the BUZZER take the value HIGH
    delay(200);  
  } else {
      digitalWrite(led, LOW);  // if the clasule "IF" is not met, the pin of the LED and the BUZZER take the value LOW 
      digitalWrite(buzzer, LOW);
  }
}
