/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef FULL_HOUSE_H
#define FULL_HOUSE_H

#include "score_slot.h"

/**
 * Full House scoring slot.
 *
 * If the there are three dice of one value and two of a different value then
 * the resultant score is 25 points.
 */
class FullHouse : public ScoreSlot
{
    bool _filled;
    int _score;

  public:
    /**
     * Constructs a Full House scoring object.
     */
    FullHouse() : _filled(false), _score(0) {};

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

#endif // FULL_HOUSE_H
