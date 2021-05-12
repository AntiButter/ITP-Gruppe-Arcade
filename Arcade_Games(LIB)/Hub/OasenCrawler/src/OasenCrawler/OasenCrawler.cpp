#include "OasenCrawler.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

typedef struct player
{
    int xPosition;
    int yPosition;
    int lifePoints;
    int relicCount;
}player;

typedef struct recording
{
    int turn;
    int x;
    int y;
    int currentField;
    int xHunter;
    int yHunter;
    int lifes;
    int relics;
    int maxRelicsRecording;
    struct recording* next;
}recording;

typedef struct playField
{
    int field[5][5];
}playField;

playField oase;
player indi;

int maxRelics(playField oase)
{
    int relics = 0;
    for (int i = 0; i <= 4; ++i)
    {
        for (int j = 0; j <= 4; ++j)
        {
            if (oase.field[i][j] == 3)
            {
                relics++;
            }
        }
    }
    return relics;
}

void printStats(player indi, playField oase, int relics)
{
    cout << "Lifes: " << indi.lifePoints << "  Relics found: " << indi.relicCount << "/" << relics << endl;
    if (oase.field[indi.yPosition][indi.xPosition] == 0)
    {
        cout << "Environment: Dessert" << endl;
    }
    if (oase.field[indi.yPosition][indi.xPosition] == 1)
    {
        cout << "Environment: Danger near you" << endl;
    }
    if (oase.field[indi.yPosition][indi.xPosition] == 2)
    {
        cout << "Environment: Spring" << endl;
    }
    if (oase.field[indi.yPosition][indi.xPosition] == 3)
    {
        cout << "Environment: Secret Trapdoor discovered" << endl;
    }
}

void printRecordingStats(recording* current)
{
    cout << "Lifes: " << current->lifes << "  Relics found: " << current->relics << "/" << current->maxRelicsRecording << endl;
    if (current->currentField == 0)
    {
        cout << "Environment: Dessert" << endl;
    }
    if (current->currentField == 1)
    {
        cout << "Environment: Danger near you" << endl;
    }
    if (current->currentField == 2)
    {
        cout << "Environment: Spring" << endl;
    }
    if (current->currentField == 3)
    {
        cout << "Environment: Secret Trapdoor discovered" << endl;
    }
}

void printPlayField(int xHunter, int yHunter, int xIndi, int yIndi)
{
    for (int i = 0; i <= 4; ++i)
    {
        cout << endl;
        for (int j = 0; j <= 4; ++j)
        {
            if (j == xHunter && i == yHunter)
            {
                cout << "[H]";
            }
            else if (j == xIndi && i == yIndi)
            {
                cout << "[X]";
            }
            else
            {
                cout << "[ ]";
            }

        }
    }
    cout << endl;
}


player movehunter(player hunter, player indi)
{
    if (hunter.xPosition == indi.xPosition && hunter.yPosition == indi.yPosition)
    {
        hunter.lifePoints++;

        return hunter;
    }
    else if (hunter.xPosition < indi.xPosition)
    {
        hunter.xPosition++;
    }
    else if (hunter.xPosition > indi.xPosition)
    {
        hunter.xPosition--;
    }
    else if (hunter.yPosition > indi.yPosition)
    {
        hunter.yPosition--;
    }
    else if (hunter.yPosition < indi.yPosition)
    {
        hunter.yPosition++;
    }
    if (hunter.xPosition == indi.xPosition && hunter.yPosition == indi.yPosition)
    {
        hunter.lifePoints = 1;
    }
    return hunter;
}

playField checksurrounding(playField oase, int y, int x)
{
    if (oase.field[y][x] == 0) { return oase; }
    if (oase.field[y][x] == 1)
    {
        if (rand() % 6 == 3) //~16%
        {
            indi.lifePoints--;
            cout << "ouch! You just lost a Life" << endl;
        }
        oase.field[y][x] = 0;
    }
    if (oase.field[y][x] == 2)
    {
        if (indi.lifePoints < 5)
        {
            indi.lifePoints++;
        }
        oase.field[y][x] = 0;
    }
    if (oase.field[y][x] == 3)
    {
        indi.relicCount++;
        cout << "Congratulations you found Relic Number: " << indi.relicCount << endl;
        oase.field[y][x] = 0;
    }
    return oase;
}

playField processTurn(playField oase, int y, int x, player hunter, int relics)
{
    printPlayField(hunter.xPosition, hunter.yPosition, indi.xPosition, indi.yPosition);
    printStats(indi, oase, relics);
    oase = checksurrounding(oase, indi.yPosition, indi.xPosition);

    return oase;
}

recording* recordTurn(recording* head, playField oase, player indi, player hunter, char movement)
{
    recording* current = head;
    recording* prevoius = NULL;
    while (current != NULL)
    {
        prevoius = current;
        current = current->next;
    }
    recording* newTurn = (recording*)malloc(sizeof(recording));
    newTurn->lifes = indi.lifePoints;
    newTurn->relics = indi.relicCount;
    newTurn->x = indi.xPosition;
    newTurn->y = indi.yPosition;
    newTurn->turn += 1;
    newTurn->xHunter = hunter.xPosition;
    newTurn->yHunter = hunter.yPosition;
    newTurn->maxRelicsRecording = head->maxRelicsRecording;
    newTurn->currentField = oase.field[indi.yPosition][indi.xPosition];
    newTurn->next = NULL;
    prevoius->next = newTurn;
    return head;
}

void printRecording(recording* head)
{
    recording* current = head;
    char input;
    while (current != NULL)
    {
        cout << "Replay Mode" << endl;
        cout << endl;
        cout << "Enter '+' = next, 'x' = skip" << endl;
        cin >> input;
        system("CLS");
        if (input == '+')
        {
            printPlayField(current->xHunter, current->yHunter, current->x, current->y);
            printRecordingStats(current);
        }
        if (input == 'x')
        {
            break;
        }
        current = current->next;
    }
}

void freeRecording(recording* head)
{
    recording* waste = NULL;
    while (head != NULL)
    {
        waste = head;
        head = head->next;
        free(waste);
    }
}


namespace oasenCrawler
{
	void PrintMessage()
	{
		std::cout << "Hello World!" << std::endl;
	}
    using namespace std;

    void PlayOasenCrawler()
    {
        //set rand() seed
        srand(time(NULL));
        //Variables
        player hunter;
        hunter.yPosition = rand() % 5 + 6;
        hunter.xPosition = rand() % 5 + 6;
        hunter.lifePoints = 0;
        int relics = 0;
        indi.lifePoints = 5;
        indi.relicCount = 0;
        indi.xPosition = 0;
        indi.yPosition = 0;
        char movement = '-';
        int randomNumber;

        for (int i = 0; i <= 4; ++i)
        {
            for (int j = 0; j <= 4; ++j)
            {
                randomNumber = rand() % 100;
                if (randomNumber <= 40) { oase.field[i][j] = 0; }                          //Leer = 40%
                if (randomNumber >= 40 && randomNumber <= 60) { oase.field[i][j] = 1; }    //Gefahr = 40%
                if (randomNumber >= 80 && randomNumber <= 90) { oase.field[i][j] = 2; }    //Brunnen = 10%
                if (randomNumber >= 90 && randomNumber <= 100) { oase.field[i][j] = 3; }   //Relikt = 10%
            }
        }
        //start recording turns
        recording* head = (recording*)malloc(sizeof(recording));
        head->lifes = 5;
        head->relics = 0;
        head->x = 0;
        head->y = 0;
        head->turn = 1;
        head->xHunter = hunter.xPosition;
        head->yHunter = hunter.yPosition;
        head->currentField = oase.field[indi.yPosition][indi.xPosition];
        head->maxRelicsRecording = maxRelics(oase);
        head->next = NULL;
        //first time rendering game
        printPlayField(hunter.xPosition, hunter.yPosition, indi.xPosition, indi.yPosition);
        relics = maxRelics(oase);
        printStats(indi, oase, relics);
        while (movement != 'x' || indi.lifePoints == 0 || indi.relicCount == 1)
        {
            if (indi.lifePoints == 0)
            {
                cout << "====GAME=OVER====" << endl;
                break;
            }
            if (hunter.lifePoints > 0)
            {
                cout << "====GAME=OVER====" << endl;
                break;
            }
            if (indi.relicCount == relics)
            {
                cout << "====YOU=WON====" << endl;
                break;
            }
            cin >> movement;
            system("CLS");
            switch (movement)
            {
            case 'w':   if (indi.yPosition == 0)
            {
                hunter = movehunter(hunter, indi);
                oase = processTurn(oase, indi.yPosition, indi.xPosition, hunter, relics);
                head = recordTurn(head, oase, indi, hunter, movement);
                continue;
            }
                    else
            {
                indi.yPosition--;
                hunter = movehunter(hunter, indi);
                oase = processTurn(oase, indi.yPosition, indi.xPosition, hunter, relics);
                head = recordTurn(head, oase, indi, hunter, movement);
            }
                    break;
            case 's':   if (indi.yPosition == 4)
            {
                hunter = movehunter(hunter, indi);
                oase = processTurn(oase, indi.yPosition, indi.xPosition, hunter, relics);
                head = recordTurn(head, oase, indi, hunter, movement);
                continue;
            }
                    else
            {
                indi.yPosition++;
                hunter = movehunter(hunter, indi);
                oase = processTurn(oase, indi.yPosition, indi.xPosition, hunter, relics);
                head = recordTurn(head, oase, indi, hunter, movement);
            }
                    break;
            case 'a':   if (indi.xPosition == 0)
            {
                hunter = movehunter(hunter, indi);
                oase = processTurn(oase, indi.yPosition, indi.xPosition, hunter, relics);
                head = recordTurn(head, oase, indi, hunter, movement);
                continue;
            }
                    else
            {
                indi.xPosition--;
                hunter = movehunter(hunter, indi);
                oase = processTurn(oase, indi.yPosition, indi.xPosition, hunter, relics);
                head = recordTurn(head, oase, indi, hunter, movement);
            }
                    break;
            case 'd':    if (indi.xPosition == 4)
            {
                hunter = movehunter(hunter, indi);
                oase = processTurn(oase, indi.yPosition, indi.xPosition, hunter, relics);
                head = recordTurn(head, oase, indi, hunter, movement);
                continue;
            }
                    else
            {
                indi.xPosition++;
                hunter = movehunter(hunter, indi);
                oase = processTurn(oase, indi.yPosition, indi.xPosition, hunter, relics);
                head = recordTurn(head, oase, indi, hunter, movement);
            }
                    break;
            default: continue;
            }
        }
        printRecording(head);
        freeRecording(head);
    }
}