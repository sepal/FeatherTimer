#ifndef _TIME_TYPE_H_
#define _TIME_TYPE_H_

#include "Arduino.h"

class TimeType
{
public:
  TimeType();
  TimeType(uint32_t epoch);
  TimeType(uint8_t hours, uint8_t minutes, uint8_t seconds);

  uint8_t getHours();
  uint8_t getMinutes();
  uint8_t getSeconds();

  void setHours(uint8_t);
  void setMinutes(uint8_t);
  void setSeconds(uint8_t);

  TimeType& operator+=(const TimeType &right);
  TimeType& operator-=(const TimeType &right);

  inline bool operator< (const TimeType &right);
  inline bool operator> (const TimeType &right);
  inline bool operator<= (const TimeType &right);
  inline bool operator>= (const TimeType &right);


  uint32_t getEpoch() const;
  void setEpoch(uint32_t);
private:
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
};

#endif
