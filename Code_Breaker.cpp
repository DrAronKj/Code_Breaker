
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include<fstream>

using namespace std;


void igrica(char answer)
{
	if (answer == 'n' || answer != 'y')
		return;
	
	cout << "Good, good luck, you'll need it..." << endl;
}


int main()
{
	char answer;
	string black, white, red, orange, yellow, pink, blue, green, empty;
	fstream datoteka;
	cout << "Do you have what it takes to crack the code?" << endl;
	cout << "press y/n" << endl;
	cin >> answer;
	igrica(answer);
	return 0;
	

}

