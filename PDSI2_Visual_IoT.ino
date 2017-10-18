#include <assert.h>
#include <Ultrasonic.h>


//Pinos trigger e echo usado para leitura do sensor Ultrasonic.
#define trigger 4
#define echo 5
// sensor de presença módulo PIR DYP-ME003
int movimento, cont =0, calibracao = 45, pirPin = 3, cali = 0;
//teste entradas

static void Noparametro(){
    float  distancia = metros();
    assert((distancia >=0) || (distancia <= 2.0));
}

static void testecalibramentro(){
  int cont = 0;
    cont = calibrar();
    assert(cont = 44 && "testeCalibramento");
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

int calibrar()
{ //calibrar o sensor de presença
  for(int i = 0; i < calibracao; i++){
      Serial.print(".");
      delay(1000);
      
  }
      Serial.println("Sensor Ativado");
      delay(500);
   return i 
}

int LerPresenca(){
 int pirVal = digitalRead(pirPin);
return pirVal;
}

void Movimento(){
   int  movimento = LerPresenca();
if(movimento == LOW){
Serial.println("movimento detectado");
delay(2000);
}
else
{
}
}

void setup()
{
  //Abri a comunicação serial com a porta 9600;
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(echo, INPUT);
}

void loop()
{
   
  // 1 teste sensor Ultrasonic;
  if(cont ==0){
    testecalibramentro();
     cali = calibrar();
     Noparametro();
      cont=1;
   }else{
      
   }
 Movimento();
 Serial.print("Distancia do Objeto: Metros =>  "); 
    Serial.println(metros());//chamar sensor funcao metro
  delay(4000);
}
 
