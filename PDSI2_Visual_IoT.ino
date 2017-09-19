//Biblioteca do sensor Ultrasonic
#include <Ultrasonic.h>

//Pinos trigger e echo usado para leitura do sensor Ultrasonic.
#define pino_trigger 4
#define pino_echo 5
// sensor de presença módulo PIR DYP-ME003
int sensorPresenca = 3;
int movimento;

Ultrasonic ultrasonic(pino_trigger, pino_echo);

void teste_Ultrasonic()
{
  long microsec = 0;
  do{
  microsec = ultrasonic.timing();
  }while(microsec == 1023);
}

void setup()
{
  //Abri a comunicação serial com a porta 9600;
  Serial.begin(9600);
  pinMode(sensorPresenca, INPUT);
}

void loop()
{
  // 1 teste sensor Ultrasonic;
  teste_Ultrasonic();

  
  //ler o sensor retornando o o valor do sinal;
  long microsec = ultrasonic.timing();
  // retornar em centimetros a distancia do objeto a frente;
  float centimetros = ultrasonic.convert(microsec, Ultrasonic::CM);

  // ler valor do sensor de presença módulo PIR DYP-ME003
   movimento = digitalRead(sensorPresenca);
   if(movimento == LOW)
   {
    Serial.print("Sem presenca");
   }else
   {
    Serial.println("Objeto identificado"); 
   }

   
}
