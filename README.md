# deck-decker
A simple poker game 

Author: Patrick Kyoyetera
Description: A program that imitates the gameplay of casino poker. 
Date: Sunday, May 1, 2016
***************************************************************

/**************/
/   Compiling  /
/**************/

To run the program, you'll need all 7 files included in the folder. All source and header 
files are dependent on one another. 
Compile the code with the Makefile included in the folder with the source code. 
Run the resulting executable called 'main' by entering ./main in your terminal.

/***************/
/  Description  /
/***************/

The files required to run this program include 3 header files: hands.h, play.h and cards.h 
each with their corresponding implmentations with identical names: hands.cc, play.cc and 
cards.cc plus one driver program driver.cc.

The Cards.h and cards.cc files include the implementation of a poker card and the deck of 
cards used in a poker game. This is accomplished in the Card and DeckOfCrds classes respectively. 

The implementation of a hand dealt in a poker game and how it is evaluated are accomplished 
in the hands interface and implementation files. The files include the implementation of how
a Pair, Two Pair, Three of a kind, Four of a kind, Flush and a straight are evaluated. 
This file also includes the implementation of the funciton betterHand that decides the winner 
of each poker game played.

The play header and implmentation files implement the way the game is played. 
The implmentation file also has the code required for the dealer to evaluate their hand
and choose whether to swap 1, 2 or 3 cards from their hand. 
The implementation of a similar algorithm for the player is also included in theis file. 

This program isn't totally complete I'm still working on parts involving how the computer 
evaluates a winning hand. It's still a work in progress.
