/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include <stdexcept>
#include "yahtzee.h"
#include "upper_section.h"

#define BONUS_MINIMUM 63
#define BONUS_SCORE 35

UpperSection::UpperSection() : _denominations(), _score(0)
{
  // The upper section is comprised of unique, numeric slots, each one
  // representing a different side of a die (which equals six using standard
  // dice).
  for (int i = 0; i < SIDES_PER_DIE; i++)
  {
    _denominations.push_back(Numeric(i + 1));
  }
}


UpperSection::~UpperSection()
{
}


int UpperSection::score(int index, std::vector<Die> dice)
{
  int score = 0;

  // Bounds check and that the slot has not already been used
  if (index >= 0 && index < SIDES_PER_DIE && !_denominations[index].isFilled())
  {
    // Take the score given by the slot, store it, and add it to the overall
    // total
    _score += (score = _denominations[index].score(dice));
  }
  else
  {
    // An index was passed that was outside the range
    throw std::out_of_range(DEBUG_INFO("Invalid slot"));
  }

  return score;
}


int UpperSection::getScore()
{
  // Return both the total score and the (possible) bonus score
  return _score + getBonus();
}


int UpperSection::getScore(int index)
{
  // Bounds check on index
  if (index < 0 || index >= _denominations.size())
  {
    throw std::out_of_range(DEBUG_INFO("Invalid slot"));
  }
  return _denominations[index].getScore();
}


const std::string UpperSection::getName(int index)
{
  // Bounds check on index
  if (index < 0 || index >= _denominations.size())
  {
    throw std::out_of_range(DEBUG_INFO("Invalid slot"));
  }
  return _denominations[index].getName();
}


int UpperSection::getBonus()
{
  // The bonus score is only given when the total score reaches a minimum
  // threshold
  return (_score >= BONUS_MINIMUM) ? BONUS_SCORE : 0;
}

bool UpperSection::getFilled(int index)
{
  // Bounds check on index
  if (index < 0 || index >= _denominations.size())
  {
    throw std::out_of_range(DEBUG_INFO("Invalid slot"));
  }
  return _denominations[index].isFilled();
}

int UpperSection::getSize()
{
  return _denominations.size();
}
