/*
* Author: Patrick Kyoyetera
* Title: Project #2
* Description: A program that imitates the game play of poker 
* Date: Sunday, May 1, 2016
*/

#ifndef HANDS_H
#define HANDS_H
#include "cards.h"
#include <string>

int evaluateHand(vCard& hHand);
bool hasPair(vCard& hand);
bool hasTwoPairs(vCard& hand);
bool hasThreeofaKind(vCard& hand);
bool hasFourofaKind(vCard& hand);
bool hasFlush(vCard& hand);
bool hasStraight(vCard& hand);
bool sameFace(Card& arg1, Card& arg2);
bool sameFace(Card& arg1, Card& arg2, Card& arg3);
bool sortF(Card& _card1, Card& _card2);
bool sortS(Card& _card1, Card& _card2);
void sortByFace(vCard& _hand);
void sortBySuit(vCard& _hand);
void betterHand(vCard& _hand1, vCard& _hand2);
string handType_to_String(int strength);

#endif
