/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#ifndef YAHTZEE_H
#define YAHTZEE_H

// Standard number of dice is 5
#define NUMBER_OF_DICE 5

// Standard dice have 6 sides
#define SIDES_PER_DIE 6

// The number of rolls in a Yahtzee game per turn is 3
#define NUMBER_OF_ROLLS 3

// Debug info macro
#define DEBUG_INFO(x) std::string((x)) +  __func__ + ": " + \
  std::to_string(__LINE__)

#endif // YAHTZEE_H
