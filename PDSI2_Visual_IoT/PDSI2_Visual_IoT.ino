# include  < assert.h > // biblioteca para o teste
# include  < Ultrasonic.h > // bibliote do sensor ultrasonic
# include  < SoftwareSerial.h > // biblioteca para o bluetooth


// Pinos dispara e echo usado para leitura do sensor ultra-sônico.
// Sensor ultrasônico 1
# define  trigger1  4
# define  echo1  5
// Sensor ultrasonic 2
# define  trigger2  6
# define  echo2  7
// Sensor ultrasonic 3
# define  trigger3  8
# define  echo3  9 // Pinos do bluetooth
# define  TX  10
# define  RX  11
int contador = 0 ;

String comando, recebido, mensagem1, mensagem2, mensagem3;


/ * vazio estático Noparametro1 () {
  float distancia = metros1 ();
    assert ((distancia> = 0) && (distancia <= 2.0));
    Serial.println ("passé teste 1");
}
static void TestErro1 () {
    float distancia = metros1 ();
    assert ((distancia <0) && (distancia> 2.0)); 
    Serial.println ("Erro 1");
}
vazio estático Noparametro2 () {
    float distancia = metros2 ();
    assert ((distancia> = 0) && (distancia <= 2.0));
    Serial.println ("passé teste 2");
}
static void TestErro2 () {
    float distancia = metros2 ();
    assert ((distancia <0) && (distancia> 2.0)); 
    Serial.println ("Erro 2");
}
vazio estático Noparametro3 () {
    float distancia = metros3 ();
    assert ((distancia> = 0) && (distancia <= 2.0));
    Serial.println ("passé teste 3"); 
}
static void TestErro3 () {
    float distancia = metros3 ();
    assert ((distancia <0) && (distancia> 2.0)); 
    Serial.println ("Erro 3");
}
* /
Software bluetooth ( 10 , 11 );

Ultrassônico ultra- sônico1 (trigger1, echo1);
Ultra - sons2 ultra- sônicos (trigger2, echo2);
Ultrassônico ultra- sônico3 (trigger3, echo3);

float  metros1 () {
  // Teste sensor de Ultrasonic
    flutuador cmMsec, DistMetros;
    microsec longo = ultra-sônico1. timing ();
    cmMsec = ultrasonic1. converter (microsec, Ultrasonic :: CM);
    DistMetros = (cmMsec / 100.0 );
    retornar DistMetros;
}

float  metros2 () {
  // Teste sensor de Ultrasonic
    flutuador cmMsec, DistMetros;
    microsec longo = ultra-sônico2. timing ();
    cmMsec = ultrasonic2. converter (microsec, Ultrasonic :: CM);
    DistMetros = (cmMsec / 100.0 );
    retornar DistMetros;
}

float  metros3 () {
  // Teste sensor de Ultrasonic
    flutuador cmMsec, DistMetros;
    microsec longo = ultra-sons3. timing ();
    cmMsec = ultrasonic3. converter (microsec, Ultrasonic :: CM);
    DistMetros = (cmMsec / 100.0 );
    retornar DistMetros;
}

 configuração vazia ()
{
  // Abri a comunicação serial com a porta 9600;
  Serial. começar ( 9600 );
  Bluetooth. começar ( 9600 );
  pinMode (trigger1, OUTPUT);
  pinMode (echo1, INPUT);
  pinMode (trigger2, OUTPUT);
  pinMode (echo2, INPUT);
  pinMode (trigger3, OUTPUT);
  pinMode (echo3, INPUT);
}

 loop vazio ()
{
float distance1 = 0 , distancia2 = 0 , distancia3 = 0 ;
  // sensor de teste 1 Ultrassônico;
  String sensor = " " , mensagem1 = " 1 = " , mensagem2 = " 2 = " , mensagem3 = " 2 = " ;
  / * if (contador == 0) {
     Noparametro1 ();
     Noparametro2 ();
     Noparametro3 ();
     pausa;
      TestErro1 ();
      TestErro2 ();
      TestErro3 ();
      
      contador = 1;
   }outro{
      
   } * /

se (bluetooth. available ()) {
    enquanto (bluetooth. available ()) {
    char caractere = bluetooth. ler ();
    comando + = caractere;
  }

}  
   distance1 = metros1 ();
   distance2 = metros2 ();
   distance3 = metros3 ();
   sensor = (mensagem1 + distancia1 + mensagem2 + distancia2 + mensagem3 + distancia3);
   Serial. println (sensor); // sensor chamar funcao metro
	 
   atraso ( 1000 );
  
   // enviando dados sensor1
   recebido = " " ;
   recebido = sensor;
   Bluetooth. println (recebido);
  
}