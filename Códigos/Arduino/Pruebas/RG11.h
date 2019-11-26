#ifndef RG11_h
#define RG11_h

#include "Arduino.h"

#define RG11_Pin 3 // digital pin RG11 connected to 

class RG11{

  private:
    unsigned long m_tipCount; // bucket tip counter used in interrupt routine 
    float m_totalRainfall; // total amount of rainfall detected 
    float m_bucket_Size;
  public:
    RG11(float Bucket_Size = 0.01);
    void addCount();
    
    void Set_bucket_Size(float Bucket_Size);
    void Set_Count(unsigned long tipCount);
    void Set_RainFall(float Rainfall);
    void RST_RainFall();
    float Get_RainFall();
    unsigned long Get_Count();
    float Get_bucket_Size();
};


#endif
