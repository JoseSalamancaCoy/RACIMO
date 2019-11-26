
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
