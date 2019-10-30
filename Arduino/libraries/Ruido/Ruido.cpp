/*
  MLP115A2.h - Libreria para el uso del sensor de presion y temperatura MLP115A2.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  mlp115a2_init();              -- Función de inicio del sensor de T y P
  mlp115a2_Medir_Presion();     -- Funcion para adquirir la presion
  mlp115a2_Medir_Temperatura(); -- Funcion para adquirir la temperatura
  
*/
 
#include <math.h>
#include "Arduino.h"
#include "Ruido.h"


int Ruido::sensorPin = A2;                                                // Entrada analoga
int Ruido::intervalo = 100;
int Ruido::muestras = 10;
int Ruido::sensorValue;
float Ruido::voltaje;
float Ruido::Prms = 0;
float Ruido::x;
float Ruido::G = 101;
float Ruido::L;
float Ruido::Pref = 20e-6;
int Ruido::N;
int Ruido::i;

/************************** Constructores ***************************************/

Ruido::Ruido()
{
}

/************************** Metodos publicos ***********************************/

void Ruido::Ruido_init(void){
  
}

float Ruido::Medir_Ruido(){

  N = intervalo/muestras;
  x = 0;
  
  for (i=1;i<=N;i++){
    
    sensorValue = analogRead(sensorPin);                          // Lee el valor del sensor  
    voltaje = sensorValue * 5.0 / 1024.0;  
    x =  x + pow(voltaje/G, 2);      
  }
  
  Prms = sqrt(x/N);
  L = 20*log10(Prms/Pref);
  
  return L;
}




