/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include <algorithm>
#include "yahtzee.h"
#include "full_house.h"

#define FULL_HOUSE_SCORE 25
#define VAL(x) sortedDice[(x)].getValue()

int FullHouse::score(std::vector<Die> dice)
{
  // Check to see if the slot has already been scored.
  if (!_filled)
  {
    // Sorting the dice makes it easier to determine if the dice make a 
    // full house
    std::vector<Die> sortedDice = dice;
    std::sort(sortedDice.begin(), sortedDice.end());

#if NUMBER_OF_DICE != 5
  #error FullHouse fixed at using 5 dice.  Rules with using other quantities of\
    dice are unknown.
#endif
    // Check for a full house, where two dice are of one value and the other
    // three are of a different value.  Additionally, ensure that the two sets
    // of dice are not the same value (which would imply a Yahtzee but is not a
    // legal full house).
    if (((VAL(0) == VAL(1) && VAL(2) == VAL(4)) ||
          (VAL(0) == VAL(2) && VAL(3) == VAL(4))) &&
        (VAL(0) != VAL(4)))
    {
      _score = FULL_HOUSE_SCORE;
    }

    // Ensure the slot cannot be used in the future.
    _filled = true;
  }

  return getScore();
}


const std::string FullHouse::getName()
{
  return std::string("Full House");
}


bool FullHouse::isFilled()
{
  return _filled;
}

int FullHouse::getScore()
{
  return _score;
}
