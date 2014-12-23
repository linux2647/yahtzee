/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef N_OFA_KIND_H
#define N_OFA_KIND_H

#include "score_slot.h"

/**
 * n-of-a-Kind Scoring slot.
 *
 * If there are three or four of a particular die value, then the resultant
 * score is the sum of the all the dice.
 */
class NOfAKind : public ScoreSlot
{
    int _value;
    bool _filled;
    int _score;

  public:
    /**
     * Constructs an NOfAKind object.
     *
     * @param value 3, 4, or some n for a 3-, 4-, or n-of-a-kind.
     */
    NOfAKind(int value) : _value(value), _filled(false), _score(0) {};

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

#endif // N_OFA_KIND_H
