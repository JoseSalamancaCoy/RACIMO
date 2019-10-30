#ifndef RG11_h
#define RG11_h
#include "Arduino.h"
#include <SoftwareSerial.h>

class RG11{

  private:
    static  char Trama[18];
    static  int  Registro[9];
    static  int i;
    static  int j;
    static  char hexadecimal[16];
    static  char var;
    static  int ind1;
    static  int ind0;
    static  int valor;
    static  int k;
    static  float rain;
    int hexa(char var);
    
  public:
    RG11();
    void RG11_init();
    float Medir_Lluvia();
		
};

#endif
