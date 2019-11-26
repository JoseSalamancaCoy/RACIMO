                                              

#include <math.h>
#include "Arduino.h"
#include "Iluminancia.h"

/************************** Constructores ***************************************/

Iluminancia::Iluminancia(const uint8_t sensorPin)
{
  m_sensorPin = sensorPin;
}


float Iluminancia::Get_Iluminancia(){
  
  m_sensorValue = analogRead(m_sensorPin);                          // Lee el valor del sensor  
  m_voltaje = m_sensorValue * 5.0 / 1024.0;  
  m_R = m_voltaje * 1000 / (5 - m_voltaje);
  m_ilum = m_C * pow(m_R, (-1/m_gamma));                       // Calculo de la intesidad de luz en lux
 return m_ilum;
}

void Iluminancia::Set_gamma(float gamma){
  m_gamma = gamma;  
}
void Iluminancia::Set_C(float C){    
  m_C = C;
}
