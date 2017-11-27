#include <assert.h> //Biblioteca para o Teste 
#include <Ultrasonic.h> //Biblioteca do Sensor Ultrassonico
#include <SoftwareSerial.h> //Biblioteca para o Bluetooth

//Define os pinos para o trigger e echo

//Sensor Ultrasonic 1
#define trigger1 4
#define echo1 5

//Sensor Ultrasonic 2
#define trigger2 6
#define echo2 7

//Sensor Ultrasonic 3
#define trigger3 8
#define echo3 9

//Pinos do Bluetooth
#define TX 10
#define RX 11

String comando = "";


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


// Inicializa o Bluetooth nos pinos definidos acima
SoftwareSerial bluetooth(10,11);


// Inicializa os Sensores nos pinos definidos acima
Ultrasonic ultrasonic1(trigger1, echo1);
Ultrasonic ultrasonic2(trigger2, echo2);
Ultrasonic ultrasonic3(trigger3, echo3);

void setup()
{
Serial.begin(9600);
Serial.println("Lendo dados do sensor…");
bluetooth.begin(9600);
}

float metros1(){

    //Le as informacoes do sensor, em cm, e retorna em metros
    float cmMsec, DistMetros;
    long microsec = ultrasonic1.timing();
    cmMsec = ultrasonic1.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec/100);
    
    return DistMetros; 
}

float metros2(){

    //Le as informacoes do sensor, em cm, e retorna em metros
    float cmMsec, DistMetros;
    long microsec = ultrasonic2.timing();
    cmMsec = ultrasonic2.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec/100);
    
    return DistMetros; 
}

float metros3(){

    //Le as informacoes do sensor, em cm, e retorna em metros
    float cmMsec, DistMetros;
    long microsec = ultrasonic3.timing();
    cmMsec = ultrasonic3.convert(microsec, Ultrasonic::CM);
    DistMetros = (cmMsec/100);
    
    return DistMetros; 
}

void loop()
{

  float d1 = 0, d2 = 0, d3 = 0; 
  
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
      comando += (char)bluetooth.read();
    }
  } 

  
  d1 = metros1();
  d2 = metros2();
  d3 = metros3();
  
  sensor =(d1+mensagem+d2+mensagem+d3);
  
  //Exibe informacoes no serial monitor
  Serial.println("Distancia em M: ");
  Serial.println(sensor);
  
  // Envia os dados via Bluetooth
  bluetooth.println(sensor);
  
  delay(1000);

}
