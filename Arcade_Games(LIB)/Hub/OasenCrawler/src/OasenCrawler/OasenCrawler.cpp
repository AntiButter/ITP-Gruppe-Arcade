#include <iostream>
#include "playerOC.h"
#include "gameboard.h"
#include "monster.h"
#include <time.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include "OasenCrawler.h"

//todo match history

void printFightMessage(int fmsg) {

    switch (fmsg) {
    case 0:
        //std::cout << "Nothing happened" << std::endl;
        break;
    case 1:
        std::cout << "You were too weak" << std::endl;
        break;
    case 2:
        std::cout << "You were stronger" << std::endl;
        break;
    case 3:
        std::cout << "Defending yourself failed" << std::endl;
        break;
    case 4:
        std::cout << "Successfully defended" << std::endl;
        break;
    case 5:
        std::cout << "You were too slow" << std::endl;
        break;
    case 6:
        std::cout << "Successfully escaped" << std::endl;
        break;
    default:
        std::cout << "errorpfm" << std::endl;
        break;
    }

}

int checkInteraction(player* p, gameboard* gb) {

    std::cout << "moin" << std::endl;

    if (gb->GetValue(p->GetPy(), p->GetPx()) == 1) {
        return 0;
    }
    else if (gb->GetValue(p->GetPy(), p->GetPx()) == 2) {
        int rnum = rand() % 3;

        if (rnum == 0) {
            rnum = rand() % 10;
            if (rnum > p->GetStrength()) {
                p->SetHp(p->GetHp() - 1);
                gb->SetValue(p->GetPy(), p->GetPx(), gameboard::leer);
                return 1;
            }
            else {
                gb->SetValue(p->GetPy(), p->GetPx(), gameboard::leer);
                return 2;
            }
        }
        else if (rnum == 1) {
            rnum = rand() % 10;
            if (rnum > p->GetDefense()) {
                p->SetHp(p->GetHp() - 1);
                gb->SetValue(p->GetPy(), p->GetPx(), gameboard::leer);
                return 3;
            }
            else {
                gb->SetValue(p->GetPy(), p->GetPx(), gameboard::leer);
                return 4;
            }
        }
        else if (rnum == 2) {
            rnum = rand() % 10;
            if (rnum > p->GetAgility()) {
                p->SetHp(p->GetHp() - 1);
                gb->SetValue(p->GetPy(), p->GetPx(), gameboard::leer);
                return 5;
            }
            else {
                gb->SetValue(p->GetPy(), p->GetPx(), gameboard::leer);
                return 6;
            }
        }

    }
    else if (gb->GetValue(p->GetPy(), p->GetPx()) == 3) {
        p->SetHp(p->GetHp() + 1);
        gb->SetValue(p->GetPy(), p->GetPx(), gameboard::leer);
        return 0;
    }
    else if (gb->GetValue(p->GetPy(), p->GetPx()) == 4) {
        gb->SetRelics(gb->GetRelics() - 1);
        p->SetRelics(p->GetRelics() + 1);
        gb->SetValue(p->GetPy(), p->GetPx(), gameboard::leer);
        return 0;
    }

}

int terminate(player* p, gameboard* gb, monster* m, int turn) {


    if (p->GetHp() == 0) {
        system("CLS");
        std::cout << "Too bad, you lost all HP!" << std::endl;
        return 1;
    }
    else if (gb->GetRelics() == 0) {
        system("CLS");
        std::cout << "Congratulations, you found all relics!" << std::endl;
        return 2;
    }
    else if (m->GetHp() == 0) {
        system("CLS");
        std::cout << "Too bad, the monster has caught you!" << std::endl;
        return 1;
    }
    else if (turn == 40) {
        system("CLS");
        std::cout << "You took too long to win the game!" << std::endl;
        return 1;
    }
    else {
        return 0;
    }
}


namespace oasenCrawler {


    int PlayOasenCrawler()
    {
        int fmsg = 0;
        char cont = 'a';
        int level = 0;

        srand(time(NULL));

        do {
            int turn = 0;
            int checkstatus = 0;
            level++;

            player* p = new player(5);

            int mx = rand() % 2 + 3;
            int my = rand() % 2 + 3;
            monster* m = new monster(mx, my);


            gameboard* gb = new gameboard(p, m);

            std::string msg = "Use W,A,S,D to move around\nFind all Relics to win the game\nYou lose:\n-if your HP drops to 0\n-after 40 turns\n-if the monster catches you";


            gb->generateBoard();


            while (true) {
                system("CLS");

                gb->printBoard();

                p->printStats();
                std::cout << "Level: " << level << std::endl;

                printFightMessage(fmsg);
                fmsg = 0;

                std::cout << "Relics left: " << gb->GetRelics() << std::endl;

                if (msg != "") {
                    std::cout << msg << std::endl;
                    msg = "";
                }
                char direction;
                direction = _getch();

                //Aktion je nach Eingabe
                switch (direction) {
                case 'w':
                    if (p->GetPy() != 0) {
                        p->SetPy(p->GetPy() - 1);
                        turn++;
                        m->MoveMonster(p->GetPx(), p->GetPy());
                    }
                    else {
                        msg = "Moving up is not possible";
                    }
                    break;
                case 's':
                    if (p->GetPy() != 4) {
                        p->SetPy(p->GetPy() + 1);
                        turn++;
                        m->MoveMonster(p->GetPx(), p->GetPy());
                    }
                    else {
                        msg = "Moving down is not possible";
                    }
                    break;
                case 'a':
                    if (p->GetPx() != 0) {
                        p->SetPx(p->GetPx() - 1);
                        turn++;
                        m->MoveMonster(p->GetPx(), p->GetPy());
                    }
                    else {
                        msg = "Moving left is not possible";
                    }
                    break;
                case 'd':
                    if (p->GetPx() != 4) {
                        p->SetPx(p->GetPx() + 1);
                        turn++;
                        m->MoveMonster(p->GetPx(), p->GetPy());
                    }
                    else {
                        msg = "Moving right is not possible";
                    }
                    break;
                default:
                    msg = "Invalid input";
                    continue;
                }

                fmsg = checkInteraction(p, gb);
                checkstatus = terminate(p, gb, m, turn);
                if (checkstatus == 0) {

                }
                else if (checkstatus == 1) {
                    std::cout << "Your Score: " << level << std::endl;
                    break;
                }
                else if (checkstatus == 2) {
                    std::cout << "Do you want to continue playing? [y] [n]" << std::endl;

                    while (cont != 'y' || cont != 'n') {
                        cont = _getch();
                        if (cont == 'y') {
                            std::cout << "yeeee" << std::endl;
                            break;
                        }
                        else if (cont == 'n') {
                            std::cout << "noo" << std::endl;
                            break;
                        }
                        else {
                            std::cout << "invalid input" << std::endl;
                        }
                    }
                    break;
                }
            }
            delete p;
            delete m;
            delete gb;
            if (checkstatus == 1) {
                break;
            }
        } while (cont == 'y');



        std::cout << "Stats here" << std::endl;

        return level;

    }
}