/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef SCORE_SECTION_H
#define SCORE_SECTION_H

#include <string>
#include <vector>
#include "yahtzee.h"
#include "die.h"

/**
 * An ADT for a scoring section that holds a set of scoring slots.
 *
 * See UpperSection and LowerSection.
 */
class ScoreSection
{
  public:
    /**
     * Score a set of dice for a given slot.
     *
     * @param index Slot to score.
     * @param dice Dice to score.
     * @return Resultant score.
     */
    virtual int score(int index, std::vector<Die>) = 0;

    /**
     * Returns whether or not a slot has already been scored.
     *
     * @param index Slot to score.
     * @return True if the slot has already been scored.
     */
    virtual bool getFilled(int index) = 0;

    /**
     * Returns the current score of the section, i.e. the sum of the scores of
     * all of the scored slots.
     */
    virtual int getScore() = 0;

    /**
     * Returns the score of a particular score slot.
     *
     * If getFilled(index) returns false, then the result is undefined behavior.
     *
     * @param index Slot to get the score from.
     * @return Score of the particular slot.
     */
    virtual int getScore(int index) = 0;

    /**
     * Returns the name of a score slot.
     *
     * @param index Slot to retrieve the name of.
     * @return The name of the score slot.
     */
    virtual const std::string getName(int index) = 0;

    /**
     * Returns the number of slots in the section.
     */
    virtual int getSize() = 0;
};

#endif // SCORE_SECTION_H
