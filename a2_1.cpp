/*
Cortez Phenix
The 26th of January, 2021
CS10B, Mr. Harden
Assignment 2.1

This program uses do-while loops, variables, if-then statements, and randomly generated numbers, allowing the user to play a blackjack-like game.
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

int main() {

  //Get a different sequence of random numbers each time they need to be generated.
  //Initialize two string variables, later used to allow the user to draw another card or stop playing the game.
  srand(static_cast < unsigned > (time(nullptr)));
  string card_choice;
  string repeat_choice;

  //Main do-while loop that controls game.
  do {
    //Initialize and assign int variables of randomly generated numbers, 1-10. Store the total.
    int num_1 = rand() % 10 + 1;
    int num_2 = rand() % 10 + 1;
    int total = num_1 + num_2;

    //Display the initially-generated first cards and the total.
    do {
      cout << "\nFirst Cards: " << num_1 << ", " << num_2;
      cout << "\nTotal: " << total << "\n\n";

      //Choose new card or not. If yes, generate new number, then update and display the total, provided the total is not equal to or greater than 21.
      do {
        cout << "Do you want another card? (y/n) ";
        cin >> card_choice;
      }
      while (card_choice == "y" && (total += rand() % 10 + 1) && cout << "Total: " << total << "\n\n" && (total != 21) && total < 21);

      //If user does not want another card, prompt for a replay, and exit the loop.
      if (card_choice == "n") {
        cout << "\nDo you want to play again? (y/n) ";
        cin >> repeat_choice;
        break;
      }

      //If the total equals 21, the user wins. Prompt for a replay, and exit the loop.
      if (total == 21) {
        cout << "Congratulations!\n\n";
        cout << "Do you want to play again? (y/n) ";
        cin >> repeat_choice;
        break;
      }

      //If the total is greater than 21, the user loses. Prompt for a replay, and exit the loop.
      if (total > 21) {
        cout << "Bust!\n\n";
        cout << "Do you want to play again? (y/n) ";
        cin >> repeat_choice;
        break;
      }

    }
    //Repeat the game, if the user chooses to.
    while (repeat_choice == "y");

    //Exit the game, if the user chooses to.
    if (repeat_choice == "n") {
      break;
    }

  }
  //Repeat the game, if the user chooses to.
  while (repeat_choice == "y");

  return 0;
}

/*
Sample Run:

First Cards: 4, 10
Total: 14

Do you want another card? (y/n) y
Total: 21

Congratulations!

Do you want to play again? (y/n) y

First Cards: 6, 1
Total: 7

Do you want another card? (y/n) y
Total: 9

Do you want another card? (y/n) y
Total: 19

Do you want another card? (y/n) y
Total: 22

Bust!

Do you want to play again? (y/n) n
*/
