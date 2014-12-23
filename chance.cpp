/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include "yahtzee.h"
#include "chance.h"

int Chance::score(std::vector<Die> dice)
{
  // Check to see if the slot has already been scored.
  if (!_filled)
  {
    // Iterate over the dice and add each value to the score.
    for (auto &die : dice)
    {
      _score += die.getValue();
    }

    // Ensure the slot cannot be used in the future.
    _filled = true;
  }

  return getScore();
}

const std::string Chance::getName()
{
  return std::string("Chance");
}

bool Chance::isFilled()
{
  return _filled;
}

int Chance::getScore()
{
  return _score;
}
