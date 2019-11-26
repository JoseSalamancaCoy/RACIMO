
#include <math.h>
#include "Arduino.h"
#include "Ruido.h"



/************************** Constructores ***************************************/

Ruido::Ruido(uint8_t sensorPin ,float VRef,uint8_t muestras,float G)
{
  m_sensorPin = sensorPin;
  m_muestras = muestras;
  m_VRef = VRef;
  m_G = G;
}

/************************** Metodos publicos ***********************************/

float Ruido::Get_Ruido(){
  
  float m_Ruido = 0;  
  uint16_t m_sensorValue;

  for (uint8_t i=1; i<= m_muestras ; i++){
    m_sensorValue = analogRead(m_sensorPin);                          // Lee el valor del sensor  
    m_voltaje = m_sensorValue * m_VRef / 1024.0;  
    m_Ruido =  m_Ruido + pow(m_voltaje/m_G, 2);      
  }
  return m_Ruido;
}

void Ruido::Set_VRef(float VRef)
{
    m_VRef = VRef;  
}
void Ruido::Set_G(float G)
{
    m_G = G;  
}

float Ruido::Get_VRef()
{
  return m_VRef;
}
float Ruido::Get_voltaje()
{
  m_voltaje = analogRead(m_sensorPin) * m_VRef / 1024.0;
  return m_voltaje;
}
