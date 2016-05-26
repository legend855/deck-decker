/*
* Author: Patrick Kyoyetera
*/

#include "cards.h"
#include "hands.h"
#include "play.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	srand(time(NULL));
	
	string ans;
		
	do{
		play();
		cout << "\n\n";
		cout<<"Continue?"<<endl;
		cin>>ans;
	}while(ans=="yes" or ans=="y" or ans=="Y" or ans=="Yes" or ans=="YES");
//	player(p2_hand)
	
	
	
	/*
	for(vCard::iterator it=p1_hand.begin(); it!=p1_hand.end(); ++it)
		cout << (*it).toString() << "\t"  << endl;
		cout << "Hand 1 strength: " << evaluateHand(p1_hand) << endl;
	cout << "\n\n";
	for(vCard::iterator it=p2_hand.begin(); it!=p2_hand.end(); ++it)
		cout << (*it).toString() << "\t"  << endl;
		cout << "Hand 2 strength: " << evaluateHand(p2_hand) << endl;
	cout << "\n\n";
	betterHand(p1_hand, p2_hand);

	*/

}
