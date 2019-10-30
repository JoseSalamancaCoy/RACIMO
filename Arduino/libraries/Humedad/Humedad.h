/*
  Humedad.h - Libreria para el uso del sensor de humedad.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  Humedad_init();              -- Función de inicio del sensor de humedad
  Medir_Humedad();             -- Funcion para adquirir la humedad
  
*/

#ifndef Humedad_h
#define Humedad_h

#include "Arduino.h"


class Humedad{  
  
  private:
    static int sensorPin;
    static int sensorValue;  
    static float RH;
    static int intervalo;
    
  public:
    Humedad();
    float Medir_Humedad();
    void Humedad_init();
    
};
#endif
