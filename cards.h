/*
* Author: Patrick Kyoyetera
* Title: Project #2
* Description: A program that imitates the game play of poker 
* Date: Sunday, May 1, 2016
*/

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#define MAX_CARD 51

using namespace std;

class Card {
protected:
	int suit;
	int face;
	static string suits[4];
	static string faces[13];
public:
	Card();
	Card(int suit_, int face_);
	int getFace()const;
	int getSuit()const;
	void setSuit(int suit_);
	void setFace(int face_);
	Card(const Card& arg);
	friend bool operator==(const Card& arg1, const Card& arg2);
	friend bool operator!=(const Card& arg1, const Card& arg2);
	string toString();
};

typedef std::vector<Card> vCard;

class DeckOfCards {
//protected:
public:
	vCard deck;
	int currentCard;
//public:
	DeckOfCards();
	static int randGen();
	//DeckOfCards(vCard deck_, int cCard);
	void shuffleCards();
	vCard dealHand();
	Card dealCard();
	bool moreCards();
};

#endif
