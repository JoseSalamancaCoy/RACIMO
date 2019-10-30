#ifndef Iluminancia_h
#define Iluminancia_h

#include "Arduino.h"

class Iluminancia{

  private:
    static int sensorPin;                                            // Entrada analoga
    static int intervalo;                                          // Intervalo de adquisicion
    static int sensorValue;
    static float voltaje;
    static float R;
    static float ilum;
    static float gamma;
    static float C;

  public:
    Iluminancia();
    void Iluminancia_init();
    float Medir_Iluminancia();
		
};

#endif
