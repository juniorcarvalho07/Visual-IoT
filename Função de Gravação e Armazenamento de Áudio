// Programa : Gravador de voz e player ISD1820

// Pino ligado ao REC do modulo
int pino_rec = 5;
// Pino ligado ao P-E (PLAYE) do modulo
int pino_playe = 7;

void setup()
{ 
  pinMode(pino_rec, OUTPUT);
  pinMode(pino_playe, OUTPUT);
}

void loop()
{
  delay(5000);
  // Inicia a gravacao
  digitalWrite(pino_rec, HIGH);
  delay(10000);
  // Para a gravacao
  digitalWrite(pino_rec, LOW);
  // Aguarda 5 segundos
  delay(5000);
  // Inicial a reproducao
  digitalWrite(pino_playe, HIGH);
  delay(100);
  
} 
