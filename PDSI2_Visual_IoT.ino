//Biblioteca do sensor Ultrasonic
#include <Ultrasonic.h>

//Pinos trigger e echo usado para leitura do sensor Ultrasonic.
#define trigger 4
#define echo 5
// sensor de presença módulo PIR DYP-ME003
int sensorPresenca = 3, movimento, cont =0, calibracao = 45,iniciaSensor = 0, pinoSensor = 8;

Ultrasonic ultrasonic(trigger, echo);

void teste_Ultrasonic()
{
  long microsec = 0;
  do{
  microsec = ultrasonic.timing();  
  Serial.println(microsec);
  delay(500);
  }while(microsec == 1023);
}
void teste2()
{
  for(int i = 0; i < calibracao; i++){
  Serial.print(".");
  delay(1000);
  }
  Serial.println("Sensor Ativado");
  delay(500);
}

void alarme_on()
{  //Função que ativa o alarme - Detectou presença, o LED Vermelho fica acende
//E o LED VERDE apaga.

}
void alarme_off()
{ //Função que desativa o alarme - N foi detectado presença, o LED Vermelho apaga
//E o LED VERDE acende. 

}
   


void setup()
{
  //Abri a comunicação serial com a porta 9600;
  Serial.begin(9600);
  pinMode(sensorPresenca, INPUT);
   pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pinoSensor,INPUT);
}

void loop()
{
  // 1 teste sensor Ultrasonic;
  if(cont ==0){
    teste_Ultrasonic();
    teste2();
    cont=1;
   }else{
      
   }
  //Teste sensor de presença 
  iniciaSensor = digitalRead(pinoSensor);
  //ler o sensor retornando o o valor do sinal;
  long microsec = ultrasonic.timing();
  // retornar em centimetros a distancia do objeto a frente;
  float centimetros = ultrasonic.convert(microsec, Ultrasonic::CM);
  String cmMsecToMetersFinal = String(centimetros/100);
  Serial.println(cmMsecToMetersFinal);
  // ler valor do sensor de presença módulo PIR DYP-ME003
   movimento = digitalRead(sensorPresenca);
   if(movimento == LOW)
   {
    Serial.println("Sem presenca");
   }else
   {
    Serial.println("Objeto identificado"); 
   }
    delay(2000);

  if (iniciaSensor == 1) {
    alarme_on();
  }else {
    alarme_off();
  } 
}
 

