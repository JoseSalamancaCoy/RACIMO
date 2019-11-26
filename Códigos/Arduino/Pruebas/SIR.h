#ifndef SIR_h
#define SIR_h

#include "Arduino.h"


class SIR{  
  
  private:
    uint16_t m_sensorPin;              // Entrada analoga
    uint16_t m_sensorValue;
    float m_Voltaje;
    float m_V;
    float m_Voc;                   // Voltaje en circuito abierto
    float m_Isc;                 // Corriente en corto circuito          
    float m_n;                  // Eficiencia
    float m_e;
    float m_m;                     // Constante = 1
    float m_K;             // Electron voltios
    float m_T;                // Kelvin (25 C)
    float m_I;
    float m_G;
    float m_S;              // Area en m2 (9.8 cm x 5.7 cm)
    float m_R;                   // Resistencia del conversor corriente voltaje
    
  public:
    SIR(uint8_t sensorPin = A1);
    float Get_Irradiancia();
    
};
#endif
