/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef LOWERSECTION_H
#define LOWERSECTION_H

#include "score_section.h"
#include "score_slot.h"

/**
 * Lower Section set of scoring slots.
 *
 * This section includes 3- and 4-of-a-kind, full house, small and large
 * straights, Yahtzee, and chance.
 */
class LowerSection : public ScoreSection
{
    std::vector<ScoreSlot*> _denominations;
    int _score;

  public:
    /**
     * Constructs a LowerSection object.
     */
    LowerSection();

    /**
     * Deconstructor for LowerSection object.
     */
    ~LowerSection();

    /**
     * Score a set of dice for a given slot.
     *
     * @param index Slot to score.
     * @param dice Dice to score.
     * @return Resultant score.
     */
    int score(int index, std::vector<Die>);

    /**
     * Returns the current score of the section, i.e. the sum of the scores of
     * all of the scored slots.
     */
    int getScore();

    /**
     * Returns the score of a particular score slot.
     *
     * If getFilled(index) returns false, then the result is undefined behavior.
     *
     * @param index Slot to get the score from.
     * @return Score of the particular slot.
     */
    int getScore(int denomination);

    /**
     * Returns the name of a score slot.
     *
     * @param index Slot to retrieve the name of.
     * @return The name of the score slot.
     */
    const std::string getName(int denomination);

    /**
     * Returns whether or not a slot has already been scored.
     *
     * @param index Slot to score.
     * @return True if the slot has already been scored.
     */
    bool getFilled(int denomination);

    /**
     * Returns the number of slots in the section.
     */
    int getSize();
};

#endif // LOWERSECTION_H
