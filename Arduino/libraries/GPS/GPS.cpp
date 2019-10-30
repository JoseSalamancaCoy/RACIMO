#include "Arduino.h"
#include "GPS.h"
#include "stdlib.h"

char  GPS::sentence[80];
float GPS::Longitud;
float GPS::Latitud;
float GPS::GPSTime;
int   GPS::sentenceSize = 80;
int   GPS::b = 0;

SoftwareSerial gpsSerial(4, 2);

/************************** Constructores ***************************************/

GPS::GPS()
{
}

void GPS::GPS_init(){
	
 pinMode(4, INPUT);
 pinMode(2, OUTPUT);


}

void GPS::Medir_GPS(){
  
  static int i = 0;
  gpsSerial.begin(9600);

  while (b == 0){

  	if (gpsSerial.available())
  	{
    	char ch = gpsSerial.read();

    		if (ch != '\n' && i < sentenceSize)
    		{
      		sentence[i] = ch;
      		i++;
    		}
    		else
    		{
     			sentence[i] = '\0';
     			i = 0;
     			displayGPS();
    	}
    }
    
  }

gpsSerial.end();

}

void GPS::displayGPS()
{
  char field[20];
  getField(field, 0);
  if (strcmp(field, "$GPRMC") == 0)
  {
    
    getField(field, 1);  // dddmm.mmmm
    GPSTime = atof(field);
    
    getField(field, 3);  // ddmm.mmmm   d = decima, m = milésima
    Latitud = atof(field);
    
    getField(field, 5);  // dddmm.mmmm
    Longitud = atof(field);
    
    b = 1;
  }
}


void GPS::getField(char* buffer, int index)
{	
  int sentencePos = 0;
  int fieldPos = 0;
  int commaCount = 0;
  while (sentencePos < sentenceSize)
  {
    if (sentence[sentencePos] == ',')
    {
      commaCount ++;
      sentencePos ++;
    }
    if (commaCount == index)
    {
      buffer[fieldPos] = sentence[sentencePos];
      fieldPos ++;

    }
    sentencePos ++;
  }
  buffer[fieldPos] = '\0';
  
}

float GPS::Medir_Latitud(){
    Medir_GPS();
    return (Latitud);

} 

float GPS::Medir_Longitud(){
    Medir_GPS();
    return (Longitud);

} 

float GPS::Medir_GPSTime(){
    Medir_GPS();
    return (GPSTime);    
}
