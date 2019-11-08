                                              

#include <math.h>
#include "Arduino.h"
#include "Iluminancia.h"


int   Iluminancia::sensorValue;
float Iluminancia::voltaje;
float Iluminancia::R;
float Iluminancia::ilum;

int   Iluminancia::sensorPin = A0;
float Iluminancia::gamma = 0.86;
float Iluminancia::C = 2121823.75;


/************************** Constructores ***************************************/

Iluminancia::Iluminancia()
{
}

void Iluminancia::Iluminancia_init(){
}

float Iluminancia::Medir_Iluminancia(){
  
  sensorValue = analogRead(sensorPin);                          // Lee el valor del sensor  
  voltaje = sensorValue * 5.0 / 1024.0;  
  R = voltaje * 1000 / (5 - voltaje);
  ilum = C * pow(R, (-1/gamma));                       // Calculo de la intesidad de luz en lux
 return ilum;
}

