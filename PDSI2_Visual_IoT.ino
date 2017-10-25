#include <assert.h>
#include <Ultrasonic.h>


//Pinos trigger e echo usado para leitura do sensor Ultrasonic.
//Sensor ultrasonic 1
#define trigger1 4
#define echo1 5
//Sensor ultrasonic 2
#define trigger2 6
#define echo2 7
//Sensor ultrasonic 3
#define trigger3 8
#define echo3 9

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

float metros3(){
  //Teste sensor de Ultrasonic 
    float cmMsec, DistMetros;
    long microsec = ultrasonic2.timing();
 
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec / 100.0);
    return DistMetros; 
}

void setup()
{
  //Abri a comunicação serial com a porta 9600;
  Serial.begin(9600);
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trigger3, OUTPUT);
  pinMode(echo3, INPUT);
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
 	Serial.print("Distancia do Objeto do sensor 1: Metros =>  "); 
    Serial.println(metros1());//chamar sensor funcao metro
	Serial.print("Distancia do Objeto do sensor 2: Metros =>  "); 
    Serial.println(metros2());//chamar sensor funcao metro
	Serial.print("Distancia do Objeto do sensor 3: Metros =>  "); 
    Serial.println(metros3());//chamar sensor funcao metro
  delay(4000);
}
 
