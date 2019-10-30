/*
  NO2.h - Libreria para el uso del sensor de humedad.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  NO2_init();              -- Función de inicio del sensor de NO2
  Medir_NO2();             -- Funcion para adquirir la humedad
  
*/

#ifndef NO2_h
#define NO2_h

#include "Arduino.h"


class NO2{  
  
  private:

	static int NO2pin;
	static float NO2ppb;
	static float senNO2;
	static float Vout;
	static int Ro;
	static float Rs;
	static float m;
    
  public:
    NO2();
    float Medir_NO2();
    void NO2_init();
    
};
#endif
