#include <LowPower.h>

/*Programa que contiene: 
  1. Alarma con reedswitch y sensor PIR
     Existen muchos productos en la industria para tener una alarma:
       *Sensor de teperatura
       *Sensor de movimiento
       *entrada a un lugar
     En este programa se manejan as siguientes maneras:
       * Alarma con sensor de movimiento PIR: el PIR al detectar movimiento emite un sonido y prende una luz
       * Alarma con iman: el reedswitch al detectar una señal magnetica baja su voltaje/corriente provocando que emite un sonido y prenda una luz
 */
//#include <"LowPower.h">
//ALARMA
//variables para sensor con reedswitch
int led = 9; //variable of the LED initialized in 9
int reedswitch = 11; //variable of the REED SWITCH initialized in 11
int buzzer = 10; //variable of the BUZZER initialized in 10
int val = 0; 
//variables ara sensor PIR
const int LEDPin= 8;
const int PIRPin= 12;
int SLEEP_8s=1;


/*
The method setup() configures the pin of the lights of the traffic lights to behave like an exit with the method pinMode()
Also the method digitalWrite() Write a HIGH or a LOW value to a digital pin.
*/
void setup() {
  //ALARMA
    //pines para alarma con sensor de movimineto
  pinMode(LEDPin, OUTPUT);
  pinMode(PIRPin, INPUT);
  //pines para alarma con reedswitch
  pinMode(led, OUTPUT); //configure the LED pin to behave like an output 
  pinMode(reedswitch, INPUT); //configure the REED SWITCH pin to behave like an input
  pinMode(buzzer, OUTPUT); //configure the BUZZER pin to behave like an output 
}

/*
The method loop()has two conditions, one that verifies if the button is pressed, if it is true the variable "state" takes the value of "high",
the second validation is responsible for verifying if the variable "satate" has the value of "high" and if the time that has passed since
the button was pressed in greater than 10 seconds
*/
void loop() {
  //variables de lectura para reedswitch
  val = digitalRead(reedswitch); 
  //variables de lectura para sensor PIR
  int value= digitalRead(PIRPin); 

//ALARMA
//si el valor de señal del reedswitch es LOW
   if(val == LOW){ 
    //prende el led y el buzzer
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);  
  } else
  //si el valor del sensor es HIGH 
  if (value == HIGH)  {
    //el led prendey apaga 2 miliseg y el buzzer suena
    digitalWrite(LEDPin, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(LEDPin, LOW);
    digitalWrite(buzzer, HIGH);
    delay(50);
  } else {
    LowPower.powerDown(SLEEP_8s, ADC_OFF, BOD_OFF);
    //al no encontrarse ningun valor en ninguna variable
    //leds y buzzer permanecen apagados
    digitalWrite(LEDPin, LOW);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);  

    LowPower.powerDown(SLEEP_8s, ADC_OFF, BOD_OFF);
  }
}
