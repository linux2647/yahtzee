/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include <algorithm>
#include "yahtzee.h"
#include "straight.h"

#define SCORE(x) (((x) - 1) * 10)

int Straight::score(std::vector<Die> dice)
{
  int streak = 1;
  int lastValue = -1;

  // Check to see if the slot has already been scored.
  if (!_filled)
  {
    // Sort the dice so that they are easier to score
    std::vector<Die> sortedDice = dice;
    std::sort(sortedDice.begin(), sortedDice.end());

    // Iterate over the dice, and look for the longest sequence (streak) 
    // of values
    for (auto &die : sortedDice)
    {
      // Check that the current die is one greater than the previous die
      if (die.getValue() - 1 == lastValue)
      {
        streak++;
      }
      // If we are aiming for (say) a small straight, then there will probably
      // be one duplicate die.  If this not the case (say it jumps from 4 to 6)
      // then we definietly don't have a straight at this point and time, thus,
      // reset the streak
      else if (die.getValue() != lastValue)
      {
        streak = 1;
      }
      // Else, the previous die matches the last die.  The streak is not reset
      // nor is it incremented.  Carry on.

      lastValue = die.getValue();
    }

    // Check to see if the streak was long enough to match the score slot
    if (streak >= _length)
    {
      _score = SCORE(_length);
    }

    // Ensure the slot cannot be used in the future.
    _filled = true;
  }

  return getScore();
}

const std::string Straight::getName()
{
  // TODO Generalize this
  if (_length == 4)
  {
    return std::string("Small Straight");
  }
  else if (_length == 5)
  {
    return std::string("Large Straight");
  }
  
  return std::string("Unknown Straight");
}

bool Straight::isFilled()
{
  return _filled;
}

int Straight::getScore()
{
  return _score;
}
