#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;
const int TRIES = 5;

int letterFill(char, string, string&);

int main() {
	string name;
	char letter;
	int num_of_wrong_guesses = 0;
	string line;

	ifstream myfile("words.txt");
	vector<string> words;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			words.push_back(line);
		}

		myfile.close();
	}
	else cout << "Unable to open file";

	size_t n = rand() % words.size();
	string word = words[n];
	//choose and copy a word from array of words randomly
	//  secret word with the * character.
	string unknown(word.length(), '*');
	//  user in game
	cout << "\n\nWelcome to hangman!! Guess the word";
	cout << "\n\nYou have to type only one letter in one try.";
	cout << "\n\nYou have " << TRIES << " tries to try and guess the word.";
	cout << "\n*****************************************";
	// Loop until the guesses are used up
	while (num_of_wrong_guesses < TRIES) {
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		if (letterFill(letter, word, unknown) == 0) {
			cout << endl << "NO! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else {
			cout << endl << "You found a letter!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// user guessed the word.
		if (word == unknown) {
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}

	if (num_of_wrong_guesses == TRIES) {
		cout << "\nSorry, you lose." << endl;
		cout << "The word was : " << word << endl;
	}

	cin.ignore();
	cin.get();

	return 0;
}

int letterFill(char guess, string secretword, string &guessword) {
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i < len; i++) {
		if (guess == guessword[i])
			return 0;
		if (guess == secretword[i]) {
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}