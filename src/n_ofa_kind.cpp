/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include "n_ofa_kind.h"
#include <algorithm>

int NOfAKind::score(std::vector<Die> dice)
{
  int streak = 1;
  int maxStreak = 0;
  int lastValue = 0;
  int score = 0;

  // Check to see if the slot has already been scored.
  if (!_filled)
  {
    // Sort the dice so it is easier to score
    std::vector<Die> sortedDice = dice;
    std::sort(sortedDice.begin(), sortedDice.end());

    // Iterate through the dice, finding the longest streak of same-value dice
    for (auto &die : sortedDice)
    {
      // Check that the last die matches this die
      if (die.getValue() == lastValue)
      {
        streak++;

        // Update the longest streak found
        if (streak >= maxStreak)
        {
          maxStreak = streak;
        }
      }
      else
      {
        // Reset the streak, but include the dice that was just looked at (thus
        // 1, not 0)
        streak = 1;
      }

      // Sum the value of all of the dice, just in case the dice result in a
      // n-of-a-kind
      score += (lastValue = die.getValue());
    }

    // If the longest streak of same-value dice is at least long as the desired
    // length (3, 4, etc.) then the score is the sum of all of the dice
    if (maxStreak >= _value)
    {
      _score = score;
    }

    // Ensure the slot cannot be used in the future.
    _filled = true;
  }

  return getScore();
}

bool NOfAKind::isFilled()
{
  return _filled;
}


const std::string NOfAKind::getName()
{
  return std::to_string(_value) + " of a Kind";
}


int NOfAKind::getScore()
{
  return _score;
}
