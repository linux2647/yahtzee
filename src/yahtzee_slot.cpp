/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include <algorithm>
#include "yahtzee.h"
#include "yahtzee_slot.h"

int Yahtzee::score(std::vector<Die> dice)
{
  int streak = 0;
  // Take the value of the first die, because if the dice result in a Yahtzee,
  // then all of the dice will be of the same value.
  int value = dice[0].getValue();

  // Check to see if the slot has already been scored.
  if (!_filled)
  {
    // Iterate over 
    for (auto &die : dice)
    {
      // Ensure that the current die is the same value as the rest
      if (die.getValue() == value)
      {
        streak++;
      }
    }

    // Check that the number of same-value dice equal the total number of dice
    if (streak == NUMBER_OF_DICE)
    {
      // YAHTZEE!!!
      _score = YAHTZEE_SCORE;
    }

    // Ensure the slot cannot be used in the future.
    _filled = true;
  }

  return getScore();
}

const std::string Yahtzee::getName()
{
  return std::string("Yahtzee");
}

bool Yahtzee::isFilled()
{
  return _filled;
}

int Yahtzee::getScore()
{
  return _score;
}
