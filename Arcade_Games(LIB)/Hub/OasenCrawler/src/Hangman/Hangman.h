#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream> 
class hangman
{
public:
	hangman();
	~hangman();
	void gameLoop();
protected:

private:
	std::vector<std::string> dictionary;
};


