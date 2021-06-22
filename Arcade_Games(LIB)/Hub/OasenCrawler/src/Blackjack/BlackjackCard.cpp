#include "BlackjackCard.h"

BlackjackCard::BlackjackCard()
{
    cardVal = -1;
}

BlackjackCard::BlackjackCard(int selector)
{

    cardVal = selector;
    if (cardVal > 10)
        cardVal = 10;

    if (selector == 1)
        cardSymbol = "A";
    else if (selector < 11)
        cardSymbol = std::to_string(selector);
    else
    {
        switch (selector)
        {
            case 11: cardSymbol = "J"; break;
            case 12: cardSymbol = "Q"; break;
            case 13: cardSymbol = "K"; break;
        }
    }
}

BlackjackCard::~BlackjackCard()
{

}

void BlackjackCard::printTop()
{
    std::cout << (char)218;
    for (int i = 0; i < 10;i++)
        std::cout << (char)196;
    std::cout << (char)191;
}

void BlackjackCard::printMiddle()
{
    std::cout << (char)179;
    for (int i = 0; i < 10;i++)
        std::cout << (char)177;
    std::cout << (char)179;
}

void BlackjackCard::printMiddle(int selector)
{
    int i = 0;

    switch (selector)
    {
        case 1: 
            
            std::cout << (char)179;
            std::cout << cardSymbol;

            //Makes the output 1 space shorter, to fit the 10
            if (cardSymbol.size() == 2)
                i = 1;
            else
                i = 0;

            for (i; i < 9;i++)
                std::cout << " ";
            std::cout << (char)179;
            
            break;
        case 7: 
            
            std::cout << (char)179;

            //Makes the output 1 space shorter, to fit the 10
            if (cardSymbol.size() == 2)
                i = 1;

            for (i; i < 9;i++)
                std::cout << " ";

            std::cout << cardSymbol;
            std::cout << (char)179;
            
            
            break;
        default: 

            std::cout << (char)179;
            for (int i = 0; i < 10;i++)
                std::cout << " ";
            std::cout << (char)179;

            break;
    }
}

void BlackjackCard::printBot()
{
    std::cout << (char)192;
    for (int i = 0; i < 10;i++)
        std::cout << (char)196;
    std::cout << (char)217;
}

void BlackjackCard::print(int selector)
{
    if (cardVal == -1)
    {
        switch (selector)
        {
            case 0: printTop(); break;
            case 8: printBot(); break;
            default: printMiddle(); break;
        }
    }
    else {
        switch (selector)
        {
            case 0: printTop(); break;
            case 8: printBot(); break;
            default: printMiddle(selector); break;
        }
    }


}

int BlackjackCard::getCardVal()
{
    return cardVal;
}

void BlackjackCard::setAceVal()
{
    cardVal = 11;
}
