/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef UPPER_SECTION_H
#define UPPER_SECTION_H

#include "score_section.h"
#include "numeric.h"

/**
 * Upper Section set of scoring slots.
 *
 * This section includes all generic numeric scoring (e.g. Aces, Twos, Threes,
 * etc.).
 */
class UpperSection : public ScoreSection
{
    std::vector<Numeric> _denominations;
    int _score;

  public:
    /**
     * Constructs an UpperSection object.
     */
    UpperSection();

    /**
     * Deconstructor for UpperSection object.
     */
    ~UpperSection();

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
     *
     * This includes the bonus score.
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
     * Returns whether or not a slot has already been scored.
     *
     * @param index Slot to score.
     * @return True if the slot has already been scored.
     */
    bool getFilled(int denomination);

    /**
     * Returns the name of a score slot.
     *
     * @param index Slot to retrieve the name of.
     * @return The name of the score slot.
     */
    const std::string getName(int denomination);

    /**
     * Returns the score of the bonus.
     *
     * If the total score is less than 63, then the bonus score is 0.
     * Otherwise, the bonus score is 35.
     *
     * @return The bonus score.
     */
    int getBonus();

    /**
     * Returns the number of slots in the section.
     */
    int getSize();
};

#endif // UPPER_SECTION_H
