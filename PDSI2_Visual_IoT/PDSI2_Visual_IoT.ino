#include <assert.h>// biblioteca para o teste 
#include <Ultrasonic.h>//bibliote do sensor ultrasonic 
#include <SoftwareSerial.h>//biblioteca para o bluetooth


//Pinos trigger e echo usado para leitura do sensor Ultrasonic.
//Sensor ultrasonic 1
#define trigger1 4
#define echo1 5
//Sensor ultrasonic 2
#define trigger2 6
#define echo2 7
//Sensor ultrasonic 3
#define trigger3 8
#define echo3 9//Pinos do bluetooth

#define TX 10
#define RX 11

String comando ="";


/*static void Noparametro1(){
  float  distancia = metros1();
    assert((distancia >=0) && (distancia <= 2.0));
    Serial.println("passou teste 1");
}

static void TestErro1(){
    float  distancia = metros1();
    assert((distancia < 0) && (distancia > 2.0)); 
    Serial.println("Erro 1");
}

static void Noparametro2(){
    float  distancia = metros2();
    assert((distancia >=0) && (distancia <= 2.0));
    Serial.println("passou teste 2");
}

static void TestErro2(){
    float  distancia = metros2();
    assert((distancia < 0) && (distancia > 2.0)); 
    Serial.println("Erro 2");
}

static void Noparametro3(){
    float  distancia = metros3();
    assert((distancia >=0) && (distancia <= 2.0));
    Serial.println("passou teste 3"); 
}

static void TestErro3(){
    float  distancia = metros3();
    assert((distancia < 0) && (distancia > 2.0)); 
    Serial.println("Erro 3");
}
*/
SoftwareSerial bluetooth(10,11);

Ultrasonic ultrasonic1(trigger1, echo1);
Ultrasonic ultrasonic2(trigger2, echo2);
Ultrasonic ultrasonic3(trigger3, echo3);

float metros1(){
  //Teste sensor de Ultrasonic 
    float cmMsec, DistMetros;
    long microsec = ultrasonic1.timing();
    cmMsec = ultrasonic1.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec / 100.0);
    return DistMetros; 
}

float metros2(){
  //Teste sensor de Ultrasonic 
    float cmMsec, DistMetros;
    long microsec = ultrasonic2.timing();
    cmMsec = ultrasonic2.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec / 100.0);
    return DistMetros; 
}

float metros3(){
  //Teste sensor de Ultrasonic 
    float cmMsec, DistMetros;
    long microsec = ultrasonic3.timing();
    cmMsec = ultrasonic3.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec / 100.0);
    return DistMetros; 
}

void setup()
{
  //Abri a comunicação serial com a porta 9600;
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
float d1=0, d2=0, d3=0; 
  // 1 teste sensor Ultrasonic;
  String sensor= "", mensagem="&";
  /*if(contador ==0){
     Noparametro1();
     Noparametro2();
     Noparametro3();
     break;
      TestErro1();
      TestErro2();
      TestErro3();
      
      contador=1;
   }else{
      
   }*/

if(bluetooth.available()){
    while(bluetooth.available()){
    char caractere =  bluetooth.read();
    comando += caractere;
  }

}  
   d1 = metros1();
   d2 = metros2();
   d3 = metros3();
   sensor =(d1+mensagem+d2+mensagem+d3);
   Serial.println("Distancia em M: ");
   Serial.println(sensor);//chamar sensor funcao metro
	 
  
   bluetooth.println(sensor);

     delay(1000);

}
 
