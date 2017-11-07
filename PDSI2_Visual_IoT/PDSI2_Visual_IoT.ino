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
int contador = 0;

String comando, recebido, mensagem1, mensagem2, mensagem3;


//static void Noparametro1(){
  //float  distancia = metros1();
    //assert((distancia >=0) || (distancia <= 2.0));
//}

//static void TestErro1(){
   // float  distancia = metros1();
   // assert((distancia < 0) || (distancia > 2.0)); 
//}

//static void Noparametro2(){
//    float  distancia = metros2();
  //  assert((distancia >=0) || (distancia <= 2.0));
//}

//static void TestErro2(){
  //  float  distancia = metros2();
   // assert((distancia < 0) || (distancia > 2.0)); 
//}

//static void Noparametro3(){
  //  float  distancia = metros3();
    //assert((distancia >=0) || (distancia <= 2.0)); 
//}

//static void TestErro3(){
    //float  distancia = metros3();
  //  assert((distancia < 0) || (distancia > 2.0)); 
//}

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
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trigger3, OUTPUT);
  pinMode(echo3, INPUT);
}

void loop()
{
float distancia1 = 0,distancia2 = 0, distancia3 = 0; 
  // 1 teste sensor Ultrasonic;
  String sensor1,sensor2,sensor3;
  if(contador ==0){
    // Noparametro1();
    // TestErro1();
    // Noparametro2();
    // TestErro2();
    // Noparametro3();
    // TestErro3();
      contador=1;
   }else{
      
   }

if(bluetooth.available()){
    while(bluetooth.available()){
    char caractere =  bluetooth.read();
    comando += caractere;
  }

}  
   distancia1 = metros1();
   distancia2 = metros2();
   distancia3 = metros3();
   mensagem1= "Bundinha 1=";

   sensor1 = (distancia1);
   sensor2 = (distancia2);
   sensor3 = (distancia3);
   
   Serial.println("1="+sensor1);//chamar sensor funcao metro
	 Serial.println("2="+sensor2);//chamar sensor funcao metro
   Serial.println("3="+sensor3);//chamar sensor funcao metro
  
   delay(1000);
  
   //enviando dados sensor1
   recebido = "";
   recebido = sensor1;
   bluetooth.println(recebido);
   
   //enviando dados sensor2
   recebido = "";
   recebido = sensor2;
   bluetooth.println(recebido);
   
  //enviando dados sensor3
   recebido = "";
   recebido = sensor3;
   bluetooth.println(recebido);
   
  
}
 
