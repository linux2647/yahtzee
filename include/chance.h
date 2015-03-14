/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef CHANCE_H
#define CHANCE_H

#include "score_slot.h"

/**
 * Chance scoring slot.
 *
 * Chance sums the all dice.
 */
class Chance : public ScoreSlot
{
    bool _filled;
    int _score;

  public:
    /**
     * Constructs a Chance scoring object.
     */
    Chance() : _filled(false), _score(0) {};

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

#endif // CHANCE_H
