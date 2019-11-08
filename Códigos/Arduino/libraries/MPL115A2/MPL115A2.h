/*
  MPL115A2.h - Libreria para el uso del sensor de presion y temperatura MLP115A2.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  mpl115a2_init();              -- Función de inicio del sensor de T y P
  mpl115a2_Medir_Presion();     -- Funcion para adquirir la presion
  mpl115a2_Medir_Temperatura(); -- Funcion para adquirir la temperatura
  
*/

#ifndef MPL115A2_h
#define MPL115A2_h

#include "Arduino.h"

#define chipAdr (0x60)

class MPL115A2{  
  
  private:
    void mpl115a2_coeficientes();
    void mpl115a2_P_T();
    
    static uint16_t Padc; 
    static uint16_t Tadc;
    static int16_t A_0; 
    static int16_t B_1;
    static int16_t B_2;
    static int16_t C_12;    
    static float A_0F;
    static float B_1F;
    static float B_2F;
    static float C_12F;
    static float PresComp;
    static float P;
    static float T;
    
  public:
    MPL115A2();
    float mpl115a2_Medir_Presion();
    float mpl115a2_Medir_Temperatura();
    void mpl115a2_init();
    
};
#endif
