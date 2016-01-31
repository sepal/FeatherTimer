#ifndef _TIME_H_
#define _TIME_H_

#include "Arduino.h"

class Time
{
public:
  Time();
  Time(uint32_t epoch);
  Time(uint8_t hours, uint8_t minutes, uint8_t seconds);

  uint8_t getHours();
  uint8_t getMinutes();
  uint8_t getSeconds();

  void setHours(uint8_t);
  void setMinutes(uint8_t);
  void setSeconds(uint8_t);

  Time& operator+=(const Time &right);
  Time& operator-=(const Time &right);

  inline bool operator< (const Time &right);
  inline bool operator> (const Time &right);
  inline bool operator<= (const Time &right);
  inline bool operator>= (const Time &right);


  uint32_t getEpoch() const;
  void setEpoch(uint32_t);
private:
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
};

#endif
