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

}
