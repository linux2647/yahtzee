/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef NUMERIC_H
#define NUMERIC_H

#include "score_slot.h"

/**
 * Generic numeric scoring object.
 *
 * Dice are scored based on the number of dice with the same value as the
 * scoring object.  The exact score is the number of dice with the value
 * multiplied by the value.
 */
class Numeric : public ScoreSlot
{
    int _value;
    bool _filled;
    int _score;

  public:
    /**
     * Constructs a generic numeric scoring object
     *
     * @param value The value that dice should be scored against.
     */
    Numeric(int value) : _value(value), _filled(false), _score(0) {};

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

#endif // NUMERIC_H
