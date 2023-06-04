
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include<fstream>
#include <time.h>
#include <string>

using namespace std;


void igrica(char answer)
{
	if (answer == 'n' || answer != 'y')
		return;
	
	cout << "Good, good luck, you'll need it..." << endl;
}

void Random()
{
	rand(time(NULL)); //initialize the random seed


	const string  randColor[9] = { "black", "white", "red", "orange", "yellow", "pink", "blue", "green", "empty"};
	int RandIndex = rand() % 5;
}

void diff(string diffasn)
{
	if (diffans == "Easy")
	{
		Random;
	}

	else if (diffans == "Medium")
	{
		Random;
	}

	else if (diffans == "Hard")
	{
		Random;
	}

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
	cout << "Choose a difficulty" << endl;
	cout << "Easy\n Medium\n Hard" << endl;
	cin >> diffans;
	diff(diffans);
	return 0;
	

}

