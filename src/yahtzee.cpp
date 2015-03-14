/******************************************************************************
 *                     Copyright (c) 2014, Stephen Howell                     *
 *                            All rights reserved.                            *
 ******************************************************************************/

#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include "yahtzee.h"
#include "die.h"

#include "upper_section.h"
#include "lower_section.h"

using namespace std;

/**
 * Displays dice to the user.
 *
 * Also prints out the letters that a user may use to select which dice to
 * reroll.
 *
 * @param dice Dice to display.
 */
void displayDice(std::vector<Die> &dice);

/**
 * Gets the dice that the user wants to reroll.
 *
 * @param roll List of booleans with each indicie corresponding with each die.
 *   Used as an outparameter.
 * @return True if there is at least one die to reroll.
 */
bool getReRolls(bool*);

/**
 * Rolls all dice that the user has requested to roll.
 *
 * @param dice Dice used in the game.
 * @param roll List of which dice to reroll.
 */
void rollDice(std::vector<Die> &dice, bool*);

/**
 * Main for solitaire Yahtzee program.
 */
int main(int argc, char **argv)
{
  UpperSection us;
  LowerSection ls;
  vector<Die> dice;
  int choice = 0;

  cout << "Yahtzee!" << endl;

  // Display an about message if an argument has been passed and exit.
  if (argc > 1)
  {
    cout << "Written by Stephen Howell" << endl;
    cout << "Version 1" << endl;
    return 0;
  }


  // Construct and add the dice to the dice list
  for (int i = 0; i < NUMBER_OF_DICE; i++)
  {
    dice.push_back(Die(SIDES_PER_DIE));
  }

  // Iterate as many times as there are slots available to score
  for (int i = 0; i < (us.getSize() + ls.getSize()); i++)
  {
    bool roll[NUMBER_OF_DICE];
    bool doneRolling = false;

    // Set all of the dice ready for rolling
    for (int j = 0; j < NUMBER_OF_DICE; j++)
    {
      roll[j] = true;
    }

    // Roll the dice, display the dice, and ask the user for which dice they
    // would like to reroll.
    for (int j = 0; j < NUMBER_OF_ROLLS && !doneRolling; j++)
    {
      rollDice(dice, roll);
      displayDice(dice);

      // Only allow the user to input which dice they want to reroll up to the
      // last time they roll
      if (j + 1 < NUMBER_OF_ROLLS)
      {
        doneRolling = !(getReRolls(roll));
      }
    }

    // List all of the slots in the upper section
    choice = 0;
    for (int j = 0; j < (us.getSize()); j++, choice++)
    {
      cout << choice + 1 << ". " << us.getName(j) << ": ";
      if (us.getFilled(j))
      {
        cout << us.getScore(j);
      }
      cout << endl;
    }

    // List all of the slots in the lower section
    for (int j = 0; j < (ls.getSize()); j++, choice++)
    {
      cout << choice + 1 << ". " << ls.getName(j) << ": ";
      if (ls.getFilled(j))
      {
        cout << ls.getScore(j);
      }
      cout << endl;
    }

    // Get the slot that the user wants to use to score the dice
    choice = 0;
    while (choice < 1 || choice > (us.getSize() + ls.getSize()))
    {
      cout << "> ";
      cin >> choice;
      // munch everything through the newline
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      // Ensure that the slot is out-of-bounds or has not already been taken
      try
      {
        if (choice < 1 || choice > (us.getSize() + ls.getSize()) || 
            (choice - 1 < us.getSize() && us.getFilled(choice - 1)) ||
            (choice - 1 > us.getSize() && 
             ls.getFilled(choice - 1 - us.getSize())))
        {
          cout << "Invalid choice.  Please choose again" << endl;
          choice = 0;
        }
      }
      catch (const std::out_of_range &e)
      {
        cout << "Invalid choice.  Please choose again" << endl;
        choice = 0;
      }
    }

    // If the choice falls within the bounds of the upper section, score the
    // dice and print out the score
    if (choice - 1 < us.getSize())
    {
      cout << "Score for " << us.getName(choice - 1) << ": " <<
        us.score(choice - 1, dice);
    }
    // If the choice falls within the bounds of the lower section, score the
    // dice and print out the score
    else
    {
      cout << "Score for " << ls.getName(choice - us.getSize() - 1) << ": " <<
        ls.score(choice - us.getSize() - 1, dice);
    }
    cout << endl;
  }

  cout << endl;

  // Print out the totals
  cout << "Upper score" << (us.getBonus() > 0? " (w/ bonus)" : "") << ": " <<
    us.getScore() << endl;
  cout << "Lower score: " << ls.getScore() << endl;
  cout << "Total score: " << (us.getScore() + ls.getScore()) << endl;

  return 0;
}

void rollDice(std::vector<Die> &dice, bool *roll)
{
  // Iterate over the dice, only rolling the ones that the user has requested
  for (int i = 0; i < NUMBER_OF_DICE; i++)
  {
    if (roll[i])
    {
      dice[i].roll();
    }

    // Reset for next turn
    roll[i] = false;
  }
}

void displayDice(std::vector<Die> &dice)
{
  // Align text
  cout << endl << "     ";
  // Iterate over the dice, outputting the value of each die
  for (auto &die : dice)
  {
    cout << " " << die.getValue();
  }

  cout << endl << "Roll:";
  for (int i = 0; i < dice.size(); i++)
  {
    // Add dashes for visual organization
    cout << "--";
  }

  // Align text
  cout << endl << "     ";
  // Iterate over the dice, outputting the selection letter for each die
  for (int i = 0; i < dice.size(); i++)
  {
    // Each die is assigned a letter that is used for selecting which die/dice
    // to reroll
    cout << " " << (char) ('A' + i);
  }
  cout << endl;
}

bool getReRolls(bool *roll)
{
  int count = 0;
  string choice;

  // Get user input
  cout << "> ";
  getline(cin, choice);

  // Iterate over the input, taking each letter and marking that die as
  // requested for rerolling
  for (char &c : choice)
  {
    // The character is forced to be upper case (zero the 5th bit in ASCII) and
    // subtract 'A' from that value, where 'A' is the first letter that is used
    // for making a selection.  Example: 'c' or 'C' would result in 2 because
    // 'C' - 'A' == 2
    int index = ((c & (~0x20)) - 'A');
    if (index >= 0 && index < NUMBER_OF_DICE)
    {
      // Mark the index ready for rerolling
      roll[index] = true;
      // Increment the number of rerolls that are requested.  This does not take
      // into account that some letters could be duplicated, but this count is
      // only used at the function to determine if at least one die was
      // requested to be rerolled.
      count++;
    }
  }

  // Return true if at least one die was requested to be rerolled.
  return count > 0;
}
