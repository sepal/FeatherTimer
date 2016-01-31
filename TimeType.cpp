
#include "TimeType.h"

TimeType::TimeType()
{
  this->hours = 0;
  this->minutes = 0;
  this->seconds = 0;
}

TimeType::TimeType(uint32_t epoch) {
  this->setEpoch(epoch);
}

TimeType::TimeType(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
  this->hours = hours;
  this->minutes = minutes;
  this->seconds = seconds;
}


uint8_t TimeType::getHours()
{
  return this->hours;
}

uint8_t TimeType::getMinutes()
{
  return this->minutes;
}

uint8_t TimeType::getSeconds()
{
  return this->seconds;
}

void TimeType::setHours(uint8_t hours)
{
  this->hours = hours;
}

void TimeType::setMinutes(uint8_t minutes)
{
  this->minutes = minutes;
}

void TimeType::setSeconds(uint8_t seconds)
{
  this->seconds = seconds;
}



TimeType& TimeType::operator+=(const TimeType &right)
{
  this->hours += right.hours;
  this->minutes += right.minutes;
  this->seconds += right.seconds;

  return *this;
}

TimeType& TimeType::operator-=(const TimeType &right)
{
  this->hours -= right.hours;
  this->minutes -= right.minutes;
  this->seconds -= right.seconds;

  return *this;
}


inline bool TimeType::operator< (const TimeType &right)
{
  return this->getEpoch() < right.getEpoch();
}

inline bool TimeType::operator> (const TimeType &right)
{
  return this->getEpoch() > right.getEpoch();
}

inline bool TimeType::operator<= (const TimeType &right)
{
  return this->getEpoch() <= right.getEpoch();
}

inline bool TimeType::operator>= (const TimeType &right)
{
  return this->getEpoch() >= right.getEpoch();
}



uint32_t TimeType::getEpoch() const
{
  return this->hours * 3600 + this->minutes * 60 + this->seconds;
}

void TimeType::setEpoch(uint32_t epoch)
{
  this->hours = epoch / 3600;
  this->minutes = epoch / 60 - this->hours;
  this->seconds = epoch - this->hours - this->minutes;
}
