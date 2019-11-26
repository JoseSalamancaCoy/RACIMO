#include "Arduino.h"
#include "SIR.h"



/************************** Constructores ***************************************/

SIR::SIR(uint8_t sensorPin)
{
  m_sensorPin = sensorPin;
  m_Voc = 6.5;                   // Voltaje en circuito abierto
  m_Isc = 150e-3;                 // Corriente en corto circuito          
  m_n = 0.1;                  // Eficiencia
  m_e = 1.6021e-19;
  m_m = 1;                     // Constante = 1
  m_K = 1.381e-23;             // Electron voltios
  m_T = 298.15;                // Kelvin (25 C)
  m_I = 0;
  m_S = 0.01;              // Area en m2 (9.8 cm x 5.7 cm)
  m_R = 11;
}

/************************** Metodos publicos ***********************************/



float SIR::Get_Irradiancia(){

  m_sensorValue = analogRead(m_sensorPin);  
  m_Voltaje = m_sensorValue * 5.0 / 1024.0;
  m_I = m_Voltaje/m_R;
  m_V = m_Voc + (m_K*m_m*m_T/m_e)* log((m_Isc - m_I)/m_Isc);
  m_G = (m_I*m_V/(m_n*m_S))*1.02;
  
  return m_G;
}
