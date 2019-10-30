/*
  MLP115A2.h - Libreria para el uso del sensor de presion y temperatura MLP115A2.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  mlp115a2_init();              -- Función de inicio del sensor de T y P
  mlp115a2_Medir_Presion();     -- Funcion para adquirir la presion
  mlp115a2_Medir_Temperatura(); -- Funcion para adquirir la temperatura
  
*/
 
#include <Wire.h>
#include "Arduino.h"
#include "SIR.h"

int   SIR::sensorValue;
float SIR::Voltaje;
float SIR::V;

float SIR::Voc = 6.5;                   // Voltaje en circuito abierto
float SIR::Isc = 150e-3;                 // Corriente en corto circuito          
float SIR::n = 0.1;                  // Eficiencia
float SIR::e = 1.6021e-19;
float SIR::m = 1;                     // Constante = 1
float SIR::K = 1.381e-23;             // Electron voltios
float SIR::T = 298.15;                // Kelvin (25 C)
float SIR::I = 0;
float SIR::G;
float SIR::S = 0.01;              // Area en m2 (9.8 cm x 5.7 cm)
float SIR::R = 11;
int   SIR::sensorPin = A1;              // Entrada analoga



/************************** Constructores ***************************************/

SIR::SIR()
{
}

/************************** Metodos publicos ***********************************/

void SIR::SIR_init(void){
  
}

float SIR::Medir_Irradiancia(){

  sensorValue = analogRead(sensorPin);  
  Voltaje = sensorValue * 5.0 / 1024.0;
  I = Voltaje/R;
  V = Voc + (K*m*T/e)* log((Isc - I)/Isc);
  G = (I*V/(n*S))*1.02;
  
  return G;
}





