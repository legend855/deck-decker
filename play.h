/*
* Author: Patrick Kyoyetera
* Title: Project #2
* Description: A program that imitates the game play of poker 
* Date: Sunday, May 1, 2016
*/

#ifndef PLAY_H
#define PLAY_H

void play();
void _change(DeckOfCards& deck1, vCard& dHand, int strength);
bool playerTurn(DeckOfCards& deck1, vCard& pHand);
bool dealerTurn(DeckOfCards& deck1, vCard& dHand);

#endif
