
#ifndef Ruido_h
#define Ruido_h

#include "Arduino.h"


class Ruido {

  private:
    uint8_t m_sensorPin;
    uint8_t m_muestras;

    float m_VRef;
    float m_voltaje;
    float m_G;

  public:
    Ruido(uint8_t sensorPin = A2, float VRef = 5.0, uint8_t muestras = 10, float G = 101);
    float Get_Ruido();
    void Set_VRef(float VRef);
    void Set_G(float G);
    float Get_VRef();
    float Get_voltaje();

};
#endif
