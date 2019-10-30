/*
  Ruido.h - Libreria para el uso del sensor de ruido.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  mlp115a2_init();              -- Función de inicio del sensor de T y P
  mlp115a2_Medir_Presion();     -- Funcion para adquirir la presion
  mlp115a2_Medir_Temperatura(); -- Funcion para adquirir la temperatura
  
*/

#ifndef Ruido_h
#define Ruido_h

#include "Arduino.h"


class Ruido{  
  
  private:
    static int sensorPin;                                                // Entrada analoga
    static int intervalo;
    static int muestras;
    static int sensorValue;
    static float voltaje;
    static float Prms;
    static float x;
    static float G;
    static float L;
    static float Pref; 
    static int N;
    static int i;
    
  public:
    Ruido();
    float Medir_Ruido();
    void Ruido_init();
    
};
#endif
