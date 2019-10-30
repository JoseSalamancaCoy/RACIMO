/* Weather Station

# Metadata
# Station name
# Code version
# Location
# Sensors
# Power source
# GPS yes/not
# Time zone 

# UTCtime--GPSTime--presion--temp--humedad--irradiacnia--ilu--nubosidad--ruido--lluvia--gases--Latit--Long
# International System Units
# empty value -666

*/

#include <Wire.h>
#include <math.h>
#include <SoftwareSerial.h>
#include "MPL115A2.h"
#include "Iluminancia.h"
#include "SIR.h"
#include "Ruido.h"
//#include "RG11.h"
#include "Humedad.h"
//#include "GPS.h"
//#include "NO2.h"
//#include "CO2.h"


unsigned long const tiempo= 590000;
unsigned long previousMillis = 0;

float P = -666;
float T = -666;
float IR = -666;
float Ilu = -666;
float Ru = -666;
float Lluvia = -666;
float Hum = -666;
//float GasNO2 = -666;
//float GasCO2 = -666;
//float Lat = -666;
//float Lon = -666;
//float GPSTime = -666;
int time = 700;

MPL115A2 M = MPL115A2();
SIR S = SIR();
Iluminancia IL = Iluminancia();
Ruido R = Ruido();
//RG11 RG = RG11();
Humedad H = Humedad();
//GPS G = GPS();
//NO2 GNO2 = NO2();
//CO2 GCO2 = CO2();

void setup(){
  Serial.begin(9600);               // Configuración del puerto serial
  delay(100); 
  M.mpl115a2_init();                // Inicio del sensor de temperatura y presion
  S.SIR_init();
  IL.Iluminancia_init();
  R.Ruido_init();
  //RG.RG11_init();
  H.Humedad_init();
  //G.GPS_init();
  //GNO2.NO2_init();
  //GCO2.CO2_init();
}

void(* resetFunc)(void)=0;

void loop(){
  
  unsigned long currentMillis = millis();
  
  if ((unsigned long)(currentMillis - previousMillis >= tiempo)){
    delay(1000);
    delay(1000);
    resetFunc();
    
    previousMillis = currentMillis;
  }
  
  //Lluvia = RG.Medir_Lluvia();
  P = M.mpl115a2_Medir_Presion();
  T = M.mpl115a2_Medir_Temperatura();
  IR = S.Medir_Irradiancia();
  Ilu = IL.Medir_Iluminancia();
  Ru = R.Medir_Ruido();
  Hum = H.Medir_Humedad();
  //GasNO2 = GNO2.Medir_NO2();
  //GasCO2 = GCO2.Medir_CO2();
  //Lat = G.Medir_Latitud();
  //Lon = G.Medir_Longitud();
  //GPSTime = G.Medir_GPSTime();
  
  //Serial.print(GPSTime);
  //Serial.print("\t");
  Serial.print(P);  // + 96.13 Ajuste de Calibracio n
  Serial.print("\t");
  Serial.print(T);   // + 2.04 Ajuste de Calibracion
  Serial.print("\t");
  Serial.print(Hum);
  Serial.print("\t");
  Serial.print(IR);
  Serial.print("\t");
  Serial.print(Ilu);
  Serial.print("\t");
  Serial.print(Ru);
  Serial.print("\t");
  Serial.print(Lluvia);
  Serial.print("\t");
  Serial.println(currentMillis);
  //Serial.print(GasCO2);
  //Serial.print("\t");
  //Serial.print(GasNO2);
  //Serial.print("\t");
  //Serial.print(Lat);
  //Serial.print("\t");
  //Serial.println(Lon);
  //delay(time);
  
}
