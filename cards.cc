/*
* Author: Patrick Kyoyetera
* Title: Project #2
* Description: A program that imitates the game play of poker 
* Date: Sunday, May 1, 2016
*/

#include "cards.h"
#include <cassert>

//default constructor 
Card::Card() = default;

//two param constructor
Card::Card(int suit_, int face_) : suit(suit_), face(face_) { }

Card::Card(const Card& arg) {
	suit = arg.suit;
	face = arg.face;
	for(int i=0; i<13; i++)
		faces[i] = arg.faces[i];
	for(int i=0; i<4; i++)
		suits[i] = arg.suits[i];
}

/*bool Card::operator=(const Card& arg) {
	return (suit == arg.suit && face == arg.face);
}
*/
int Card::getFace() const {
	return face;
}
int Card::getSuit() const {
	return suit;
}
void Card::setSuit(int suit_) {
	assert(suit_ >= 0 && suit_ < 4);
		suit = suit_;
	//cout << "Invalid suit value" << endl;
}
void Card::setFace(int face_) {
	assert(face_ >1 && face_ < 15);
		face = face_;
	//cout << "Inval`id face value!" << endl;
}

string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
string Card::faces[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King", "Ace"};
//return the string name of the card

string Card::toString() {
	string suit_, face_;
	//std::string result;
	switch(getSuit()) {
		case 0: suit_ = suits[0];
			break;
		case 1: suit_ = suits[1];
			break;
		case 2: suit_ = suits[2];
			break;
		case 3: suit_ = suits[3];
			break;
		default: cout << "Invalid suit number" << endl;
			break;
	}
	switch (getFace()) {
		case 1: face_ = faces[0];
			break;
		case 2: face_ = faces[1];
			break;
		case 3: face_ = faces[2];
			break;
		case 4: face_ = faces[3];
			break;
		case 5: face_ = faces[4];
			break;
		case 6: face_ = faces[5];
			break;
		case 7: face_ = faces[6];
			break;
		case 8: face_ = faces[7];
			break;
		case 9: face_ = faces[8];
			break;
		case 10: face_ = faces[9];
			break;
		case 11: face_ = faces[10];
			break;
		case 12: face_ = faces[11];
			break;
		case 0: face_ = faces[12];
			break;
		default: cout << "Invalid face number" << endl;
			break;
	}
	return face_ + " of " + suit_;
}

//default deck constructor
DeckOfCards::DeckOfCards() {
	currentCard = -1;
	cout << "Default deck constructor called" << endl;
	for(int i=0; i<13; ++i)
		for(int j=0; j<4; ++j) {
			deck.push_back(Card(j, i));
			currentCard++;
		}
}

static int randGen() {
	return (rand() % (MAX_CARD +1));	
}
//overloaded comparison operator
bool operator==(const Card& arg1, const Card& arg2) {
	return(arg1.getSuit() == arg2.getSuit() && arg1.getFace()==arg2.getFace());
}
//overloaded not equal operator
bool operator!=(const Card& arg1, const Card& arg2) {
	return (arg1.getSuit() != arg2.getSuit() or arg1.getFace()!=arg2.getFace());
}

auto engine = std::default_random_engine{};
//shuffle card function
void DeckOfCards::shuffleCards() {
	for(vCard::iterator it = deck.begin(); it!=deck.end(); ++it )
		std::swap((*it), deck[(rand()%MAX_CARD+1)]);
}
//deal a single card
Card DeckOfCards::dealCard() {
	Card card = deck[currentCard];
	deck.pop_back();
	currentCard--;
	return card;
}
//deal hand function 
vCard DeckOfCards::dealHand() {
	//Confirm value of current card to be dealt 
	//if valid, return object at currentCard
	assert(currentCard >0 && currentCard <=MAX_CARD);
	vCard hand;
	this->shuffleCards();
	for(int i=0; i<5; i++) {
		hand.push_back(deck[currentCard]); 
		deck.pop_back();
		currentCard--;
		//cout <<"Current Card = "<< currentCard << endl;
	}
	return hand;
}
bool DeckOfCards::moreCards() {
	if(currentCard > 0)
		return true;
	return false;
}
