/*
  Humedad.cpp - Libreria para el uso del sensor de humedad.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  Humedad_init();              -- Función de inicio del sensor de humedad
  Medir_Humedad();             -- Funcion para adquirir la humedad
  
*/
 
#include "Arduino.h"
#include "Humedad.h"


int   Humedad::sensorPin = A3;
int   Humedad::sensorValue = 0;
float Humedad::RH = 0;
int   Humedad::intervalo = 1000;

/************************** Constructores ***************************************/

Humedad::Humedad()
{
}

/************************** Metodos publicos ***********************************/

void Humedad::Humedad_init(void){
  
}

float Humedad::Medir_Humedad(){

  sensorValue = analogRead(sensorPin);
  RH = (sensorValue - 163) / 6.32;
  
  return RH;
}




