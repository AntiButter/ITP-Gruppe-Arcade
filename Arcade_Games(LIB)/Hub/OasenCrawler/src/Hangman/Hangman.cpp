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
        while (getline(Dictionary, str))
        {
            dictionary.push_back(str);
        }
    }
}

hangman::~hangman()
{
}
int hangman::gameLoop()
{
    system("CLS");
    int size = dictionary.size();
    int pos = rand() % size;
    bool playing = true;
    bool guessChecker = true;
    int failCounter = 1;
    char guess;
    int rounds = 1;
    std::string word = dictionary[pos];
    std::vector<char> Output;
    std::vector<char> Guessed;
    for (int i = 0; i < word.size(); i++)
    {
        Output.push_back('_');
    }

    while (playing)
    {
        std::cout << std::endl;
        std::cout << std::endl;
        switch (failCounter)
        {
        case 1:
            break;
        case 2:
            std::cout << "   I" << std::endl;
            break;
        case 3:
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            break;
        case 4:
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            break;
        case 5:
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            break;
        case 6:
            std::cout << "   I ===" << std::endl;
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            break;
        case 7:
            std::cout << "   I ===" << std::endl;
            std::cout << "   I   O" << std::endl;
            std::cout << "   I" << std::endl;
            std::cout << "   I" << std::endl;
            break;
        case 8:
            std::cout << "   I ===" << std::endl;
            std::cout << "   I   O" << std::endl;
            std::cout << "   I   |" << std::endl;
            std::cout << "   I" << std::endl;
            break;
        case 9:
            std::cout << "   I ===" << std::endl;
            std::cout << "   I   O" << std::endl;
            std::cout << "   I   |" << std::endl;
            std::cout << "   I  /" << std::endl;
            break;
        case 10:
            std::cout << "   I ===" << std::endl;
            std::cout << "   I   O" << std::endl;
            std::cout << "   I   |" << std::endl;
            std::cout << "   I  / \\" << std::endl;
            std::cout << std::endl;
            std::cout << "Alle Leben Verloren" << std::endl;
            std::cout << "Das Wort war: " << word << std::endl;
            return 0;
        }
        std::cout << std::endl;
        std::cout << "Runde: " << rounds << std::endl;
        rounds++;
        guessChecker = false;
        std::cout << std::endl;
        for (std::vector<char>::const_iterator i = Output.begin(); i != Output.end(); ++i)
        {
            std::cout << *i << ' ' << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Schon benutzt: ";
        for (std::vector<char>::const_iterator i = Guessed.begin(); i != Guessed.end(); ++i)
        {
            std::cout << *i << ' ' << ", ";
        }
        std::cout << std::endl;
        std::cout << "Buchstaben raten: ";
        while (true)
        {
            std::cin >> guess;
            if (guess >= 'a' && guess <= 'z')
            {
                break;
            }
            else
            {
                std::cout << "Bitte einen valid Buchstaben eingeben (keine Grossbuchstaben)!" << std::endl;
            }
        }
        Guessed.push_back(guess);
        for (int i = 0; i < word.size(); i++)
        {
            if (word.at(i) == guess)
            {
                guessChecker = true;
                std::cout << guess << " war korrekt an der Position " << i + 1 << std::endl;
                Output[i] = guess;
                playing = false;
                for (int i = 0; i < Output.size(); i++)
                {
                    if (Output[i] == '_')
                    {
                        playing = true;
                    }
                }
            }
        }
        if (!playing)
        {
            std::cout << "Sie haben gewonnen" << std::endl;
            for (std::vector<char>::const_iterator i = Output.begin(); i != Output.end(); ++i)
            {
                std::cout << *i << ' ' << "";
            }
            if (failCounter == 1)
            {
                return 10;
            }
            else
            {
                return 10 - failCounter;
            }

        }
        else
        {
            if (!guessChecker)
            {
                failCounter++;
                std::cout << "Falsch!" << std::endl;
            }
            Sleep(1500);
            system("CLS");
        }
    }
}
