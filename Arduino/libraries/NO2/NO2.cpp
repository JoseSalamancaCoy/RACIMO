/*
  NO2.cpp - Libreria para el uso del sensor de NO2.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  NO2_init();              -- Función de inicio del sensor de NO2
  Medir_NO2();             -- Funcion para adquirir la NO2
  
*/
 
#include "Arduino.h"
#include "NO2.h"


int 		NO2::NO2pin = A2;
float 	NO2::NO2ppb;
float 	NO2::senNO2;
float 	NO2::Vout;
int 		NO2::Ro = 811;
float 	NO2::Rs;
float 	NO2::m = 1/2.17;

/************************** Constructores ***************************************/

NO2::NO2()
{
}

/************************** Metodos publicos ***********************************/

void NO2::NO2_init(void){
  
}

float NO2::Medir_NO2(){

  senNO2 = analogRead(NO2pin);
  Vout = senNO2*5.0/1024.0;
  Rs = Ro*(5-Vout)/Vout;
  NO2ppb = 100 * pow((Rs/(35*Ro)),m);
  
  return NO2ppb;
}




