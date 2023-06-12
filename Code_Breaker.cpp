#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include<fstream>
using namespace std;

// randomStrGen generates a random string of numbers used as the random numbers in the game. Takes length as a parameter and returns the char array  of numbers. Assumes length is a positive int.
char* randomStrGen(int length)
{
	static string charset = "0123456";
	char* charArray;
	charArray = new char[length]; //allocation for char array length
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
		charArray[i] = charset[rand() % charset.length()];

	return charArray;
}

// Main in-game method for game. 
void mastermind(istream& in, ostream& out)  //support for high level input/output operations
{

	char* number = randomStrGen(5); //call to randomStrGen method with default length 5

	//Instructions displayed at the start of the game
	//User must type "begin" to start the game
	fstream file;
	file.open("Upute.txt", ios::in);
	cout << "Upute.txt" << endl;
	file.close();

	//Inicijalizacija and deklaracija variabli
	string begin;
	string guess;
	char playagain;
	int i = 0;
	int blackPin = 0;
	int whitePin = 0;
	int tries = 0;
	int track = 0;
	int guesses = 0;
	char* ARRAY;
	ARRAY = new char[5];

	in >> begin; //gets uers input for start game
	while (begin != "begin")
	{
		cout << "Please type begin to begin the game!\n";
		cin >> begin;
	}

	//Checks if user enters begin to start the game
	if (begin == "begin")
	{
		cout << "Please enter your first guess: ";
		cin >> guess;
		strcpy(ARRAY, guess.c_str());

		//Loopa while guesses are still available
		while (!in.fail() && guesses < 9)
		{

			for (int j = 0; j < 5; j++)
			{
				track = 1;
				if (ARRAY[j] == number[j])
				{
					blackPin++;
					track = 0;
				}
				for (int k = 0; k < 5; k++)
				{
					if (ARRAY[k] == number[j] && k != j && track != 0)
					{
						whitePin++;
						track = 0;
					}
				}
			}
			if (blackPin == 5 && guesses != 9)
			{
				guesses = 10;
				whitePin = 0;
				tries++;
			}
			cout << "Correct number and position: " << blackPin << endl;
			cout << "Correct number, wrong position: " << whitePin << endl;

			if (blackPin != 5)
			{
				cout << "Please enter your next guess: ";
				cin >> guess;
				tries++;
			}

			strcpy(ARRAY, guess.c_str());
			guesses++;

			//if user guessa code
			if (blackPin == 5)
			{
				cout << "\nYou succeeded in cracking Dr Doom's code!!!" << endl;
				cout << "It took you " << tries << " tries to guess the correct combination: ";

				for (int i = 0; i < 5; i++)
				{
					cout << number[i];
				}

				//if user wants to play again...
				cout << '\n';
				cout << "To play again type y, or type n to quit: ";

				cin >> playagain;
				if (playagain == 'y' || playagain == 'Y')
				{
					//reset guesses and tries
					guesses = 0;
					tries = 0;
					//new random numbers
					number = randomStrGen(5);
					cout << "Please enter your first guess: ";
					cin >> guess;
					strcpy(ARRAY, guess.c_str());
				}
			}

			//if user does not guess code
			if (guesses == 9 && blackPin != 5)
			{
				cout << "\nGame over! You couldn't crack Dr. Doom's secret code: "; //game over messageio
				for (int i = 0; i < 5; i++)
				{
					cout << number[i];
				}

				cout << '\n';
				cout << "To play again type y, or type n to quit: ";

				cin >> playagain;
				if (playagain == 'y' || playagain == 'Y')
				{
					//reset geusses and tries
					guesses = 0;
					tries = 0;
					number = randomStrGen(5);
					cout << "Please enter your first guess: ";
					cin >> guess;
					strcpy(ARRAY, guess.c_str());
				}


			}
			blackPin = 0;
			whitePin = 0;
		}
	}
}
