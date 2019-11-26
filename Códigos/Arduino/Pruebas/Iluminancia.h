#ifndef Iluminancia_h
#define Iluminancia_h

#include "Arduino.h"

class Iluminancia{

  private:
    uint8_t m_sensorPin;                                            // Entrada analoga
    uint8_t m_intervalo;                                          // Intervalo de adquisicion
    uint16_t m_sensorValue;
    float m_voltaje;
    float m_R;
    float m_ilum;
    float m_gamma = 0.86;;
    float m_C = 2121823.75;

  public:
    Iluminancia(uint8_t sensorPin = A0 );
    float Get_Iluminancia();
    void Set_gamma(float gamma);
    void Set_C(float C);
    
};

#endif
