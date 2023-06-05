
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include<fstream>
#include <time.h>
#include <string>

using namespace std;
#define NULL

void igrica(char answer)
{
	if (answer == 'n' || answer != 'y')
		return;
	
	cout << "Good, good luck, you'll need it..." << endl;
}

void Random()
{
	rand(NULL); //initialize the random seed


	const string  randColor[9] = { "black", "white", "red", "orange", "yellow", "pink", "blue", "green", "empty"};
}

void diff(string diffans)
{
	if (diffans == "easy")
	{
		Random;
		int RandIndex = rand() % 3;

	}

	else if (diffans == "medium")
	{
		Random;
		int RandIndex = rand() % 5;
	}

	else if (diffans == "hard")
	{
		Random;
		int RandIndex = rand() % 8;
	}

}


int main()
{
	char answer;
	string diffans;
	string black, white, red, orange, yellow, pink, blue, green, empty;
	fstream datoteka;
	cout << "Do you have what it takes to crack the code?" << endl;
	cout << "press y/n" << endl;
	cin >> answer;
	igrica(answer);
	system("cls");
	datoteka.open("naslov.txt", ios::app | ios::in);
	string naslov;
	while (getline(datoteka, naslov))
		cout << naslov << endl;
	datoteka.close();
	cout << "Choose a difficulty" << endl;
	cout << "easy\nmedium\nhard" << endl;
	cin >> diffans;
	diff(diffans);    
	return 0;
	

}

