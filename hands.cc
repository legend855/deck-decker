/*
* Author: Patrick Kyoyetera
* Title: Project #2
* Description: A program that imitates the game play of poker 
* Date: Sunday, May 1, 2016
*/
#include "hands.h"

int evaluateHand(vCard& hHand){
	int handStrength=0;
	if(hasPair(hHand))	
		handStrength=1;
	if(hasTwoPairs(hHand))
		handStrength=2;
	if(hasThreeofaKind(hHand))
		handStrength=3;
	if(hasStraight(hHand))
		handStrength=4;
	if(hasFlush(hHand))
		handStrength=5;
	if(hasFourofaKind(hHand))
		handStrength=6;
	return handStrength;
}

string handType_to_String (int strength) {
	string type;
	switch(strength) {
		case 0: type="Nothing!";
			break;
		case 1: type="Pair!";
			break;
		case 2: type="Two Pairs!";
			break;
		case 3: type="Three of a Kind!";
			break;
		case 4: type="Straight!";
			break;
		case 5: type="Flush!";
			break;
		case 6: type="Four of a Kind!";
			break;
		default: type="\0";
			break;
	}
	return type;
}

bool sortF(Card& _card1, Card& _card2) {
	return(_card1.getFace()<_card2.getFace());	
}
bool sortS(Card& _card1, Card& _card2) {
	return (_card1.getSuit()<_card2.getSuit());
}

void sortByFace(vCard& _hand) {
	std::sort(_hand.begin(), _hand.end(), sortF);
}
void sortBySuit(vCard& _hand) {
	std::sort(_hand.begin(), _hand.end(), sortS);
}

bool sameFace(Card& arg1, Card& arg2) {
	return (arg1.getFace() == arg2.getFace());
}
bool sameFace(Card& arg1, Card& arg2, Card& arg3) {
	return (arg1.getFace() == arg2.getFace() == arg3.getFace());
}

//check if hand contains a pair of similar cards
bool hasPair(vCard& hand) {	
	for(vCard::iterator it1=hand.begin(); it1!=hand.end(); ++it1) {
		vCard::iterator it2=hand.begin();
			while(it1!=it2 and it2!=hand.end()) {
				if(sameFace((*it1), (*it2)))
					return true;
				else
					++it2;
			}
	}
	return false;
}

//check for pair in hand 
bool hasTwoPairs(vCard& argH) {
	bool a1, a2, a3;
	sortByFace(argH);
	a1 = argH[0].getFace() == argH[1].getFace() and 
			argH[2].getFace() == argH[3].getFace();
	a2 = argH[0].getFace() == argH[1].getFace() and 
			argH[3].getFace() == argH[4].getFace();
	a3 = argH[1].getFace() == argH[2].getFace() and 
			argH[3].getFace() == argH[4].getFace();
	return (a1 or a2 or a3);
}

//check is hand contains three of a kind
bool hasThreeofaKind(vCard& hand) {
	bool a1, a2,a3;
	sortByFace(hand);
	/* ------------------------------------------------------
	Check for: x x x a b
	------------------------------------------------------- */
	a1 = hand[0].getFace() == hand[1].getFace() and
		  hand[1].getFace() == hand[2].getFace() and
		  hand[3].getFace() != hand[0].getFace() and
		  hand[4].getFace() != hand[0].getFace() and
		  hand[3].getFace() != hand[4].getFace();
	/* ------------------------------------------------------
	Chandeck for: a x x x b
	------------------------------------------------------- */
	a2 = hand[1].getFace() == hand[2].getFace() and
		  hand[2].getFace() == hand[3].getFace() and
		  hand[0].getFace() != hand[1].getFace() and
		  hand[4].getFace() != hand[1].getFace() and
		  hand[0].getFace() != hand[4].getFace();
	/* ------------------------------------------------------
	Check for: a b x x x
	------------------------------------------------------- */
	a3 = hand[2].getFace() == hand[3].getFace() and
		  hand[3].getFace() == hand[4].getFace() and
	     hand[0].getFace() != hand[2].getFace() and
  	     hand[1].getFace() != hand[2].getFace() and
  	     hand[0].getFace() != hand[1].getFace();
	return( a1 or a2 or a3 );
}
//check if hand contains four of a kind 
bool hasFourofaKind(vCard& hand) { 
	/*int k;
	for(int i=0;i<2;i++){
		k = i;
		while(k<i+3 and hand[k].getFace()==hand[k+1].getFace())
			k++;
		if(k==i+3)
			return true;
	}
	return false;*/
	bool a1, a2;
	sortByFace(hand);
	a1 = hand[0].getFace() == hand[1].getFace() and
			hand[1].getFace() == hand[2].getFace() and
			hand[2].getFace() == hand[3].getFace();
	a2 = hand[1].getFace() == hand[2].getFace() and
			hand[2].getFace() == hand[3].getFace() and
			hand[3].getFace() == hand[4].getFace();
	return (a1 or a2);
}

//check if hand contains a flush 
//five cards of the same suit
bool hasFlush(vCard& hand) {
	int k=0;
	while(k<4 and (hand[k].getSuit() == hand[k+1].getSuit()))
		++k;
	if(k==4)
		return true;
	return false;	
}

//check if a hand contains straight cards
//five cards of consecutive face value
bool hasStraight(vCard& hand) {
	sortByFace(hand);
	int k=0;
	while(k<4 and (hand[k].getFace() == hand[k+1].getFace()-1))
		++k;
	if(k==4)
		return true;
	return false;
}

void betterHand(vCard& _hand1, vCard& _hand2) {
	int hand1_strength = evaluateHand(_hand1);
	int hand2_strength = evaluateHand(_hand2);
	string hand1_type = handType_to_String (hand1_strength);
	string hand2_type = handType_to_String (hand2_strength);
	if(hand1_strength > hand2_strength)
		//return 1;
		cout << "Hand 1 has " << hand1_type << " Hand 1 is better!" << endl;
	else if(hand1_strength < hand2_strength)
		//return 2;
		cout << "Hand 2 has " << hand2_type << " Hand 2 is better!" << endl;
	else {
		cout<<"Hand 1 has "<<hand1_type<<"\n"<<"Hand 2 has "<<hand2_type<<endl;
		cout << "Both hands have equal hand strength" << endl;
	}
}




