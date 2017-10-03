#include <assert.h>
  
double somar(double a, double b){
       return a + b;



static void testsomar(){
  double resultadoespe = 7.5;
  double resultado =  somar(3.5,4.0);
  assert(resultadoespe == somar(3.5,3.0) && "testsomar()");
}
void setup() {
Serial.begin(9600);
}


void loop() {
testsomar();
Serial.println(somar(3.5,4.0));

}
