#include <assert.h>
#include <Ultrasonic.h>


//Pinos trigger e echo usado para leitura do sensor Ultrasonic.
//Sensor ultrasonic 1
#define trigger1 4
#define echo1 5
//Sensor ultrasonic 2
#define trigger2 4
#define echo2 5
//Sensor ultrasonic 3
#define trigger3 4
#define echo3 5

static void Noparametro1(){
    float  distancia = metros1();
    assert((distancia >=0) || (distancia <= 2.0));
}

static void Noparametro2(){
    float  distancia = metros2();
    assert((distancia >=0) || (distancia <= 2.0));
}


Ultrasonic ultrasonic1(trigger1, echo1);
Ultrasonic ultrasonic2(trigger2, echo2);
Ultrasonic ultrasonic3(trigger3, echo3);

float metros1(){
  //Teste sensor de Ultrasonic 
    float cmMsec, DistMetros;
    long microsec = ultrasonic1.timing();
 
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec / 100.0);
    return DistMetros; 
}

float metros2(){
  //Teste sensor de Ultrasonic 
    float cmMsec, DistMetros;
    long microsec = ultrasonic2.timing();
 
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec / 100.0);
    return DistMetros; 
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
     Noparametro1();
     Noparametro2();
     Noparametro3();
      cont=1;
   }else{
      
   }
 Movimento();
 Serial.print("Distancia do Objeto: Metros =>  "); 
    Serial.println(metros());//chamar sensor funcao metro
  delay(4000);
}
 
