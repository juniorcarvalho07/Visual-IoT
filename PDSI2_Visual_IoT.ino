#include <Ultrasonic.h>

//Pinos trigger e echo usado para leitura do sensor.
#define pino_trigger 4
#define pino_echo 5

Ultrasonic ultrasonic(pino_trigger, pino_echo);


void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
