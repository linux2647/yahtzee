/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include "numeric.h"

const std::string CARDINAL_NUMBERS[SIDES_PER_DIE] = {
  "Aces",
  "Twos",
  "Threes",
  "Fours",
  "Fives",
  "Sixes"
};

int Numeric::score(std::vector<Die> dice)
{
  // Check to see if the slot has already been scored.
  if (!_filled)
  {
    // Iterate over the dice, summing the value of all dice that match this slot
    for (auto &die : dice)
    {
      // Check that the current die is equal to the value that is being scored
      // for
      if (die.getValue() == _value)
      {
        _score += _value;
      }
    }

    // Ensure the slot cannot be used in the future.
    _filled = true;
  }

  return getScore();
}

bool Numeric::isFilled()
{
  return _filled;
}


const std::string Numeric::getName()
{
  return CARDINAL_NUMBERS[_value - 1];
}


int Numeric::getScore()
{
  return _score;
}
