#include <math.h>
#include "Arduino.h"
#include "RG11.h"

/************************** Constructores ***************************************/

RG11::RG11(float Bucket_Size)
{
  m_tipCount = 0; 
  m_totalRainfall = 0; 
  m_bucket_Size = Bucket_Size;
  pinMode(RG11_Pin, INPUT); 
}

void RG11::addCount()
{
  m_tipCount++;
}
    


    
void RG11::Set_bucket_Size(float Bucket_Size)
{
  m_bucket_Size = Bucket_Size;
}

void RG11::Set_Count(unsigned long tipCount)
{
  m_tipCount = tipCount; 
}
void RG11::Set_RainFall(float Rainfall)
{
  m_totalRainfall = Rainfall; 
  if(Rainfall >0 ) m_tipCount = int(Rainfall / m_bucket_Size);
  else m_tipCount=0;
}
   
void RG11::RST_RainFall()
{
  m_totalRainfall = 0;
  m_tipCount = 0;
}


float RG11::Get_RainFall()
{
  return m_totalRainfall = m_tipCount * m_bucket_Size; 
}
unsigned long RG11::Get_Count()
{
  return m_tipCount;
}

float RG11::Get_bucket_Size()
{
  return m_bucket_Size;
}
