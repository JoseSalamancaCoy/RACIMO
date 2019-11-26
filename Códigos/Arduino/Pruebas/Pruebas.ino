
#include <Wire.h>
#include <math.h>
#include <SoftwareSerial.h>
#include "Adafruit_MPL115A2.h"
#include "Iluminancia.h"  
#include "Ruido.h"
#include "RG11.h"
#include "SIR.h"

Adafruit_MPL115A2 mpl115a2;
Iluminancia Ilumin;
Ruido SensorRuido;
RG11 SensorLluvia;
SIR SensorIrradiancia;
void setup() {
  Serial.begin(9600);
  Ilumin = Iluminancia(A0); //Inicializa Clase para medicion de Iluminancia, ademas se define el pin Analogico al cual esta conectado el sensor
  SensorRuido = Ruido(A2); //Inicializa Clase para medicion de Ruido conectado al A2 y Parametros por defecto
  SensorLluvia = RG11(); //Inicializa Clase para medicion de lluvia con sensor RG11
  SensorIrradiancia = SIR();
  mpl115a2.begin();
  Serial.print("Pressure (kPa): "); 
  Serial.print("Temp (*C): ");
  Serial.print("Iluminancia: ");
  Serial.print("Ruido: ");
  Serial.print("LLuvia: ");
  attachInterrupt(1, isr_rg, FALLING); 

}

void loop() {
  // put your main code here, to run repeatedly:
 float pressureKPA = 0, temperatureC = 0,   iluminancia = 0,  ruido =0, lluvia=0, Irradiancia=0;

  pressureKPA = mpl115a2.getPressure();  
  temperatureC = mpl115a2.getTemperature();  
  iluminancia = Ilumin.Get_Iluminancia();
  ruido = SensorRuido.Get_Ruido();
  lluvia = SensorLluvia.Get_RainFall();
  Irradiancia = SensorIrradiancia.Get_Irradiancia();
  
  Serial.print(pressureKPA, 4);Serial.print("  "); 
  Serial.print(temperatureC, 1);Serial.print("  "); 
  Serial.print(iluminancia, 4); Serial.print("  "); 
  Serial.print(ruido); Serial.print("  "); 
  Serial.print(lluvia); Serial.print("  "); 
  Serial.print(Irradiancia); Serial.println("  "); 
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  

}

void isr_rg()
{ 
  SensorLluvia.addCount();
} 
