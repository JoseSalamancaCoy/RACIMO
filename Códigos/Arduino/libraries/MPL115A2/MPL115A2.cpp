/*
  MPL115A2.h - Libreria para el uso del sensor de presion y temperatura MLP115A2.
  Copyright, Jesus Pe#a Rodriguez, Grupo Halley
  
  mpl115a2_init();              -- Función de inicio del sensor de T y P
  mpl115a2_Medir_Presion();     -- Funcion para adquirir la presion
  mpl115a2_Medir_Temperatura(); -- Funcion para adquirir la temperatura
  
*/
 
#include <Wire.h>
#include "Arduino.h"
#include "MPL115A2.h"


uint16_t MPL115A2::Padc; 
uint16_t MPL115A2::Tadc;
int16_t MPL115A2::A_0; 
int16_t MPL115A2::B_1;
int16_t MPL115A2::B_2;
int16_t MPL115A2::C_12;

float MPL115A2::A_0F;
float MPL115A2::B_1F;
float MPL115A2::B_2F;
float MPL115A2::C_12F;
float MPL115A2::PresComp;
float MPL115A2::P;
float MPL115A2::T;


/************************** Constructores ***************************************/

MPL115A2::MPL115A2()
{
}

/************************** Metodos publicos ***********************************/

void MPL115A2::mpl115a2_P_T(void){
  
  Wire.beginTransmission(chipAdr);          
  Wire.write(0x12); 
  Wire.write(0x00);
  Wire.endTransmission();
  delay(5);
  Wire.beginTransmission(chipAdr);
  Wire.write(0x00);
  Wire.endTransmission();
   
  Wire.requestFrom(chipAdr, 4);            // Pide los siguientes 8 bytes desde 0x04
 
  Padc = (((uint16_t) Wire.read() << 8) | Wire.read()) >> 6;
  Tadc = (((uint16_t) Wire.read() << 8) | Wire.read()) >> 6;
  
  PresComp = A_0F + (B_1F + C_12F * Tadc)* Padc + B_2F * Tadc;
  P = (((65.0 / 1023.0)* PresComp) + 50.0)* 10;
  T = (( Tadc - 498.0)/ -5.35) + 25.0;
}


float MPL115A2::mpl115a2_Medir_Presion() {                  // Para mejorar la medici�n se hace um promedio de un n�mero determinado de mediciones
  
  mpl115a2_P_T();
  return P;
   
} 

float MPL115A2::mpl115a2_Medir_Temperatura() {                  // Para mejorar la medici�n se hace um promedio de un n�mero determinado de mediciones
     
   return T;
   
} 

void MPL115A2::mpl115a2_coeficientes(void){
  

// La direccion del primer coeficiente es 0x04 

  Wire.beginTransmission(chipAdr);            // Empieza la transmisi�n
  Wire.write(0x04);                           // Configura la direcci�n a 0x04
  Wire.endTransmission();                     // Termina la transmisi�n
   
  Wire.requestFrom(chipAdr, 8);                // Pide los siguientes 8 bytes desde 0x04


// Concatenaci�n de los bytes MSB:LSB
    A_0 = ((uint16_t) Wire.read() << 8) | Wire.read();
    B_1 = ((uint16_t) Wire.read() << 8) | Wire.read();
    B_2 = ((uint16_t) Wire.read()<< 8) | Wire.read();
    C_12 = (((uint16_t) Wire.read() << 8) | Wire.read()) >> 2;
    
    A_0F = (float)A_0/8;
    B_1F = (float)B_1/8192;
    B_2F = (float)B_2/16384;
    C_12F = (float)C_12/4194304;
}

void MPL115A2::mpl115a2_init(void){
  
  Wire.begin();                                 // Inicio del bus I2C
  delay(100);
  
  mpl115a2_coeficientes();                      // Obtencion de los coeficientes
  
}


