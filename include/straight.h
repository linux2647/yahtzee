/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "score_slot.h"

#define SMALL_STRAIGHT 4
#define LARGE_STRAIGHT 5

/**
 * Small or Large Straight scoring slot.
 *
 * If the dice are in a sequence of 4 or 5 in length, then the resultant score
 * is 30 or 40, respectively.
 */
class Straight : public ScoreSlot
{
    int _length;
    bool _filled;
    int _score;

  public:
    /**
     * Constructs an n Straight scoring slot.
     *
     * @param length Length of sequence.
     */
    Straight(int length) : _length(length), _filled(false), _score(0) {};

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

#endif // STRAIGHT_H
