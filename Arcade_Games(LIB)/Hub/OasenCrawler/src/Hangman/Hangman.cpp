#include "Hangman.h"
#include <string>       
#include <iostream>     
#include <sstream>
#include <fstream>
hangman::hangman()
{
	std::ifstream Dictionary;
	std::stringstream Temp;
	std::string str, line;
	Dictionary.open("dictionary.txt");
	if (!Dictionary.is_open())
	{
		std::cerr << "Could not open file!" << std::endl;

	}
	else
	{
		while (getline(Dictionary, str, ','))
		{
			dictionary.push_back(str);
		}
	}
	this->gameLoop();
}

hangman::~hangman()
{
}
void hangman::gameLoop()
{
	int size = dictionary.size();
	int pos = rand() % size;
	bool playing = true;
	char guess;
	std::string word = dictionary[pos];
	std::vector<char> Output;
	for (int i = 0; i < word.size(); i++)
	{
		Output.push_back('_');
	}
	
	while (playing)
	{
		for (std::vector<char>::const_iterator i = Output.begin(); i != Output.end(); ++i)
		{
			std::cout << *i << ' ' << " ";
		}
			
		std::cout << std::endl;
		std::cout << "Guess a character: ";
		std::cin >> guess;
		for (int i = 0; i < word.size(); i++)
		{
			if (word.at(i) == guess)
			{
				Output[i] = guess;
				playing = false;
				for(int i = 0; i < size; i++)
				{
					if (Output[i] == '-')
					{
						playing = true;
					}
				}
			}
		}
	}
	

}