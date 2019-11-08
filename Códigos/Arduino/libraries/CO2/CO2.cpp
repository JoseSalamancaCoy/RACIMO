/*
  CO2.cpp - Libreria para el uso del sensor de CO2.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  CO2_init();              -- Función de inicio del sensor de CO2
  Medir_CO2();             -- Funcion para adquirir la CO2
  
*/

#include "Arduino.h"
#include "CO2.h"


int 		CO2::CO2pin = A0;
float 	CO2::EMF1 = 0.35;  // 350 mV for 350 ppm of CO2
float 	CO2::CO2ppm;
float 	CO2::senCO2;
float 	CO2::EMF2;

/************************** Constructores ***************************************/

CO2::CO2()
{
}

/************************** Metodos publicos ***********************************/

void CO2::CO2_init(void){
  
}

float CO2::Medir_CO2(){

  senCO2 = analogRead(CO2pin);
  EMF2 = senCO2*5.0/1024.0;
  CO2ppm = pow(10, ((EMF1 - EMF2 + 157.2)/61.8));
  
  return CO2ppm;
}




