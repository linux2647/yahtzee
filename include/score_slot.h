/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef SCORE_SLOT_H
#define SCORE_SLOT_H

#include <string>
#include <vector>
#include "die.h"
#include "yahtzee.h"

/**
 * Score slot ADT.
 *
 * Used for scoring a set of dice.
 */
class ScoreSlot
{
  public:
    virtual ~ScoreSlot() = 0;

    /**
     * Scores a set of dice.
     * 
     * @param dice Dice used for scoring.
     * @return Resultant score.
     */
    virtual int score(std::vector<Die>) = 0;

    /**
     * Returns the name for the scoring slot.
     */
    virtual const std::string getName() = 0;

    /**
     * Returns whether or not the slot has been used.
     */
    virtual bool isFilled() = 0;

    /**
     * Returns the score of the slot.
     *
     * Calling this when isFilled() returns false results in undefined behavior.
     */
    virtual int getScore() = 0;
};

inline ScoreSlot::~ScoreSlot() {};

#endif // SCORE_SLOT_H
