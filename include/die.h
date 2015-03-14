/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef DIE_H
#define DIE_H

#include <random>

#define NORMAL_DIE 6

/**
 * Die class for representing an n-sided die.
 */
class Die
{
    int _sides;
    int _currentValue;
    std::default_random_engine _randomGenerator;
    std::uniform_int_distribution<int> _distribution;

  public:
    /**
     * Constructs a standard die object (6-sided).
     */
    Die();

    /**
     * Constructs a die object.
     * 
     * @param sides Number of sides for the die.
     */
    Die(int sides);

    /**
     * Copy constructor for Die object.
     *
     * @param die Die to copy-construct.
     */
    Die(const Die&);

    /**
     * Copy assignment operator overload for Die object.
     *
     * @param die Die to copy.
     * @return Reference to current Die.
     */
    Die& operator=(const Die&);

    /**
     * Rolls the die.
     *
     * @return Result of the roll.
     */
    int roll();

    /**
     * Returns the current value of the die (of the last role)
     */
    int getValue();

    friend bool operator==(const Die&, const Die&);
    friend bool operator!=(const Die&, const Die&);
    friend bool operator<(const Die&, const Die&);
    friend bool operator<=(const Die&, const Die&);
    friend bool operator>(const Die&, const Die&);
    friend bool operator>=(const Die&, const Die&);
};

#endif // DIE_H
