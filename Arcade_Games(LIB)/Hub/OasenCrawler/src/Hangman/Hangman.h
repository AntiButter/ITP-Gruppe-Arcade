#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
class hangman
{
public:
	hangman();
	~hangman();
	int gameLoop();
protected:

private:
	std::vector<std::string> dictionary;
};


