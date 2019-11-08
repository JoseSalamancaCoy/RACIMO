/*
  MLP115A2.h - Libreria para el uso del sensor de presion y temperatura MLP115A2.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  mlp115a2_init();              -- Función de inicio del sensor de T y P
  mlp115a2_Medir_Presion();     -- Funcion para adquirir la presion
  mlp115a2_Medir_Temperatura(); -- Funcion para adquirir la temperatura
  
*/

#ifndef SIR_h
#define SIR_h

#include "Arduino.h"


class SIR{  
  
  private:
    static int sensorPin;              // Entrada analoga
    static int sensorValue;
    static float Voltaje;
    static float V;
    static float Voc;                   // Voltaje en circuito abierto
    static float Isc;                 // Corriente en corto circuito          
    static float n;                  // Eficiencia
    static float e;
    static float m;                     // Constante = 1
    static float K;             // Electron voltios
    static float T;                // Kelvin (25 C)
    static float I;
    static float G;
    static float S;              // Area en m2 (9.8 cm x 5.7 cm)
    static float R;                   // Resistencia del conversor corriente voltaje
    
  public:
    SIR();
    float Medir_Irradiancia();
    void SIR_init();
    
};
#endif
