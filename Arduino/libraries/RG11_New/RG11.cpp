#include "Arduino.h"
#include "RG11.h"

char RG11::Trama[18];
int RG11::Registro[9];
int RG11::j = 0;
int RG11::i = 0;
char RG11::hexadecimal[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
char RG11::var;
int RG11::ind1;
int RG11::ind0;
int RG11::valor;
int RG11::k;
float RG11::rain;

SoftwareSerial RGSerial(13, 12);

/************************** Constructores ***************************************/

RG11::RG11()
{
}

void RG11::RG11_init(){

  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
}


float RG11::Medir_Lluvia(){
 
  int n = 0;
  int b = 0;
  char ch;
  RGSerial.begin(1200);

while (b == 0){

  if (RGSerial.available())
  {
    ch = RGSerial.read();
    
    if (ch == 's'){
        
        i = 0;
        n = 0;

    }else{
    
    Trama[i]= ch;
    i++;

    if (i == 18){
	
	for (k=1;k<=18;k+=2){
          
          ind0 = hexa(Trama[k-1]);
          ind1 = hexa(Trama[k]);
          valor = 16*ind0 + 1*ind1;
          Registro[n] = valor;
          n++;
        }
       
	 rain = Registro[3]/0.0393;
      return rain;
      b = 1;

	}

    }
   }
  }
 RGSerial.end();
}
   

int RG11::hexa (char var){
  
  for (j=0;j<16;j++){
        if (var == hexadecimal[j]){
          return j;          
        }       
    }
}
