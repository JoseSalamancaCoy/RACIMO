#ifndef GPS_h
#define GPS_h
#include "Arduino.h"
#include <SoftwareSerial.h>

class GPS{

  private:
    
    static char sentence[80];
    static float Longitud;
    static float Latitud;
    static float GPSTime;
    static int sentenceSize;
    static int b;
    
    void displayGPS();
    void getField(char* buffer, int index);
    void Medir_GPS();
    
  public:
    GPS();
    void GPS_init();
    float Medir_Latitud();
    float Medir_Longitud();
    float Medir_GPSTime();

		
};

#endif
