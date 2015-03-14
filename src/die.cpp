/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include <chrono>
#include "die.h"

Die::Die() : _sides(NORMAL_DIE), _currentValue(0), 
  _randomGenerator(std::chrono::system_clock::now().time_since_epoch().count()),
  _distribution(1, NORMAL_DIE)
{
}

Die::Die(int sides) : _sides(sides), _currentValue(0), 
  _randomGenerator(std::chrono::system_clock::now().time_since_epoch().count()),
  _distribution(1, sides)
{
}

Die::Die(const Die& o) : _sides(o._sides), _currentValue(o._currentValue),
  _randomGenerator(std::chrono::system_clock::now().time_since_epoch().count()),
  _distribution(1, o._sides)
{
  // Prime the random number generator.  For some reason, omitting this line
  // causes all of the dice to have the same initial value.
  _distribution(_randomGenerator);
}

Die& Die::operator=(const Die& o)
{
  if (this != &o)
  {
    _sides = o._sides;
    _currentValue = o._currentValue;
    _randomGenerator = o._randomGenerator;
    _distribution = o._distribution;
  }

  return *this;
}

int Die::roll()
{
  // Roll the die, set the current value to it, and return it
  return _currentValue = _distribution(_randomGenerator);
}

int Die::getValue()
{
  return _currentValue;
}

bool operator==(const Die &a, const Die &b)
{
  return a._currentValue == b._currentValue;
}

bool operator!=(const Die &a, const Die &b)
{
  return !(a == b);
}

bool operator<(const Die &a, const Die &b)
{
  return a._currentValue < b._currentValue;
}

bool operator>(const Die &a, const Die &b)
{
  return a._currentValue > b._currentValue;
}

bool operator<=(const Die &a, const Die &b)
{
  return (a < b || a == b);
}

bool operator>=(const Die &a, const Die &b)
{
  return (a > b || a == b);
}

