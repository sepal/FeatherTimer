
#include "Time.h"

Time::Time()
{
  this->hours = 0;
  this->minutes = 0;
  this->seconds = 0;
}

Time::Time(uint32_t epoch) {
  this->setEpoch(epoch);
}

Time::Time(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
  this->hours = hours;
  this->minutes = minutes;
  this->seconds = seconds;
}


uint8_t Time::getHours()
{
  return this->hours;
}

uint8_t Time::getMinutes()
{
  return this->minutes;
}

uint8_t Time::getSeconds()
{
  return this->seconds;
}

void Time::setHours(uint8_t hours)
{
  this->hours = hours;
}

void Time::setMinutes(uint8_t minutes)
{
  this->minutes = minutes;
}

void Time::setSeconds(uint8_t seconds)
{
  this->seconds = seconds;
}



Time& Time::operator+=(const Time &right)
{
  this->hours += right.hours;
  this->minutes += right.minutes;
  this->seconds += right.seconds;

  return *this;
}

Time& Time::operator-=(const Time &right)
{
  this->hours -= right.hours;
  this->minutes -= right.minutes;
  this->seconds -= right.seconds;

  return *this;
}


inline bool Time::operator< (const Time &right)
{
  return this->getEpoch() < right.getEpoch();
}

inline bool Time::operator> (const Time &right)
{
  return this->getEpoch() > right.getEpoch();
}

inline bool Time::operator<= (const Time &right)
{
  return this->getEpoch() <= right.getEpoch();
}

inline bool Time::operator>= (const Time &right)
{
  return this->getEpoch() >= right.getEpoch();
}



uint32_t Time::getEpoch() const
{
  return this->hours * 3600 + this->minutes * 60 + this->seconds;
}

void Time::setEpoch(uint32_t epoch)
{
  this->hours = epoch / 3600;
  this->minutes = epoch / 60 - this->hours;
  this->seconds = epoch - this->hours - this->minutes;
}
