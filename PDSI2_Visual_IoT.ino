//Biblioteca do sensor Ultrasonic
#include <assert.h>
#include <Ultrasonic.h>


//Pinos trigger e echo usado para leitura do sensor Ultrasonic.
#define trigger 4
#define echo 5
// sensor de presença módulo PIR DYP-ME003
int sensorPresenca = 3, movimento, cont =0, calibracao = 45,iniciaSensor = 0, pinoSensor = 8;
//teste entradas
static void testeEntradasUltrasonic(){
  assert(trigger == 4 && "testTrigger");
    assert(echo == 5 && "testTrigger");
}

Ultrasonic ultrasonic(trigger, echo);

float metros(){
  //Teste sensor de Ultrasonic 
    float cmMsec, DistMetros;
    long microsec = ultrasonic.timing();
 
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec / 100.0);
    return DistMetros; 
}
void calibrar()
{ //calibrar o sensor de presença
  for(int i = 0; i < calibracao; i++){
      Serial.print(".");
      delay(1000);
  }
      Serial.println("Sensor Ativado");
      delay(500);
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
    testeEntradasUltrasonic();
      calibrar();
      cont=1;
   }else{
      
   }
  //chamar sensor funcao metro
 Serial.print("Distancia do Objeto: Metros =>  ");
    Serial.println(metros());
  // ler valor do sensor de presença módulo PIR DYP-ME003
  delay(4000);
}
 

