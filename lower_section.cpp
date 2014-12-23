/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include <stdexcept>
#include "lower_section.h"
#include "n_ofa_kind.h"
#include "full_house.h"
#include "straight.h"
#include "yahtzee_slot.h"
#include "chance.h"

LowerSection::LowerSection() : _denominations(), _score(0)
{
  // The lower section is comprised of a 3-of-a-kind, 4-of-a-kind, full house,
  // small straight, large straight, Yahtzee, and chance.  Because the parent
  // type of the score slots is an abstract type and the vector is declared to
  // use the abstract parent type, we must use pointers here.
  _denominations.push_back(new NOfAKind(3));
  _denominations.push_back(new NOfAKind(4));
  _denominations.push_back(new FullHouse());
  _denominations.push_back(new Straight(SMALL_STRAIGHT));
  _denominations.push_back(new Straight(LARGE_STRAIGHT));
  _denominations.push_back(new Yahtzee());
  _denominations.push_back(new Chance());
}


LowerSection::~LowerSection()
{
  // Free all of the score slots because they were created by using `new', since
  // pointers have to be used with the vector.
  for (auto &slot: _denominations)
  {
    delete slot;
  }
}


int LowerSection::score(int index, std::vector<Die> dice)
{
  int score = 0;

  // Bounds check the index and that the score is not already filled in that
  // index
  if (index >= 0 && index < _denominations.size() && 
      !_denominations[index]->isFilled())
  {
    // Take the score given by the slot, store it, and add it to the overall
    // total
    _score += (score = _denominations[index]->score(dice));
  }
  else
  {
    // An index was passed that was outside the range
    throw std::out_of_range(DEBUG_INFO("Invalid slot"));
  }

  // Return the score of the dice that was just scored, NOT the overall score
  return score;
}


int LowerSection::getScore()
{
  return _score;
}


const std::string LowerSection::getName(int index)
{
  // Bounds check the index
  if (index < 0 || index >= _denominations.size())
  {
    throw std::out_of_range(DEBUG_INFO("Invalid slot"));
  }
  return _denominations[index]->getName();
}


int LowerSection::getScore(int index)
{
  // Bounds check the index
  if (index < 0 || index >= _denominations.size())
  {
    throw std::out_of_range(DEBUG_INFO("Invalid slot"));
  }
  return _denominations[index]->getScore();
}

bool LowerSection::getFilled(int index)
{
  // Bounds check the index
  if (index < 0 || index >= _denominations.size())
  {
    throw std::out_of_range(DEBUG_INFO("Invalid slot"));
  }
  return _denominations[index]->isFilled();
}

int LowerSection::getSize()
{
  return _denominations.size();
}
