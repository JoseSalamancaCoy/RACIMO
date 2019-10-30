/*
  CO2.h - Libreria para el uso del sensor de humedad.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  CO2_init();              -- Función de inicio del sensor de CO2
  Medir_CO2();             -- Funcion para adquirir la humedad
  
*/

#ifndef CO2_h
#define CO2_h

#include "Arduino.h"


class CO2{  
  
  private:

	static int CO2pin;
	static float EMF1 ;  
	static float CO2ppm;
	static float senCO2;
	static float EMF2;
    
  public:
    CO2();
    float Medir_CO2();
    void CO2_init();
    
};
#endif
