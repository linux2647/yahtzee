/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef YAHTZEE_SLOT_H
#define YAHTZEE_SLOT_H

#include "score_slot.h"

#define YAHTZEE_SCORE 50

/**
 * Yahtzee scoring slot.
 *
 * A Yahtzee is when all of the dice are of the same value.
 */
class Yahtzee : public ScoreSlot
{
    bool _filled;
    int _score;

  public:
    /**
     * Constructs a Yahtzee scoring object.
     */
    Yahtzee() : _filled(false), _score(0) {};

    /**
     * Scores a set of dice.
     * 
     * @param dice Dice used for scoring.
     * @return Resultant score.
     */
    int score(std::vector<Die>);

    /**
     * Returns the name for the scoring slot.
     */
    const std::string getName();

    /**
     * Returns whether or not the slot has been used.
     */
    bool isFilled();

    /**
     * Returns the score of the slot.
     *
     * Calling this when isFilled() returns false results in undefined behavior.
     */
    int getScore();
};

#endif // YAHTZEE_SLOT_H
