/*
* Author: Patrick Kyoyetera
* Title: Project #2
* Description: A program that imitates the game play of poker 
* Date: Sunday, May 1, 2016
*/

#include "cards.h"
#include "hands.h"
#include "play.h"

using namespace std;

void play() {
	DeckOfCards deck1;
	//deck1.shuffleCards();
	bool bail;
	int pStren,dStren;
	vCard dHand = deck1.dealHand();
	vCard pHand = deck1.dealHand();

	while (bail!=true) {
		
		if(deck1.deck.size()<10 or deck1.currentCard==10) {
			cout << "Exhausted cards from deck" << endl;
			bail=true;
		}
		else{
		//play on
			cout << "Computer turn..." << "\n\n" << endl;
			bail=dealerTurn(deck1, dHand);
			cout << "Computer done\n\n" ;
			cout << "\n\nYour turn...\n\n" << endl;
			bail=playerTurn(deck1, pHand);
		}
	}
	if(bail==true) {
		pStren=evaluateHand(pHand);
		dStren=evaluateHand(dHand);
	}
	if(dStren>pStren) {
		cout<<"\n\nComputer's hand:\n"<<endl;
		for(vCard::iterator it=dHand.begin(); it!=dHand.end(); ++it)
			cout << (*it).toString() << "\t"  << endl;
		cout << "\n\nComputer wins"<<endl; 
	}
	else if(pStren>dStren) {
	
		cout<<"\n\nYou win!\n"<<"\nYour hand:\n"<<endl;
		for(int i=0;i<5;i++)
			cout<<pHand[i].toString()<<", ";
		cout<< "\n\nComputer's hand: \n"<<endl;
		for(int i=0;i<5;i++)
			cout<<dHand[i].toString()<< ", ";
	}
	else {
				cout<<"\n\nThat was a draw!\n"<<"\nYour hand:\n"<<endl;
		for(int i=0;i<5;i++)
			cout<<pHand[i].toString()<<", ";
		cout<< "\n\nComputer's hand: \n"<<endl;
		for(int i=0;i<5;i++)
			cout<<dHand[i].toString()<< ", ";
	}
}

bool dealerTurn(DeckOfCards& deck1, vCard& dHand) {
	int strength=evaluateHand(dHand);
	bool trade;
	(strength>3) ? trade=false : trade=true;
	if(trade)
		_change(deck1, dHand, strength);
	return false;
}


bool playerTurn(DeckOfCards& deck1, vCard& pHand) {
	
	int strength=evaluateHand(pHand);
	string type=handType_to_String(strength);
	//sortByFace(pHand);
	for(vCard::iterator it=pHand.begin(); it!=pHand.end(); ++it)
		cout << (*it).toString() << "\t"  << endl;
	cout << "\n\n";
	
	cout << "Player hand strength: " << strength << endl;
	//cout << "\n\n";
	int count=0;
	for(vCard::iterator it=pHand.begin(); it!=pHand.end(); ++it) {
		if(count!=3) {
			cout <<"Do you wanna swap the "<< (*it).toString()<<"?"<<endl;
			string ans;	cin>>ans;
			if(ans=="yes" or ans=="Yes" or ans=="YES" or ans=="y") {
				(*it)=deck1.dealCard();
				++count;
			}
		}
	}
	cout<<"Here's what your hand looks like: \n"<<endl;
	for(vCard::iterator it=pHand.begin(); it!=pHand.end(); ++it)
		cout << (*it).toString() << "\t"  << endl;
	cout << "\n";
	return true;
}
void _change(DeckOfCards& deck1, vCard& dHand, int strength) {

	if(strength==0) {
		//swap three cards
		sortByFace(dHand);
		for(int i=2;i<5;i++)
			dHand[i]=deck1.dealCard();
	}
	else if(strength==1) {
	//swap one two or three cards
	sortByFace(dHand);
		for(int i=2;i<5;i++)
			dHand[i]=deck1.dealCard();
	}
	else if(strength==2) {
		//swap one to try and get three of a kind
		sortByFace(dHand);
		dHand.back()=deck1.dealCard();
	}
	else {
		//swap one to try to get four of a kind
		sortByFace(dHand);
		dHand.back()=deck1.dealCard();
	}
}














