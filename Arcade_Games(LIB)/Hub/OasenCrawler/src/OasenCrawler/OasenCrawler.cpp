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
        std::cout << "Du bist auf einen Gegner getroffen aber warst zu schwach." << std::endl;
        break;
    case 2:
        std::cout << "Du bist auf einen Gegner getroffen und warst stärker, als er." << std::endl;
        break;
    case 3:
        std::cout << "Du wurdest angegriffen, jedoch konntest du dich nicht verteidigen." << std::endl;
        break;
    case 4:
        std::cout << "Du wurdest angegriffen und hast den Angriff erfolgreich abgewehrt." << std::endl;
        break;
    case 5:
        std::cout << "Du wurdest bei der Flucht von einem Feind eingeholt." << std::endl;
        break;
    case 6:
        std::cout << "Du konntest erfolgreich vor einem Feind fliehen." << std::endl;
        break;
    default:
        std::cout << "Unknown Error" << std::endl;
        break;
    }

}

int checkInteraction(player* p, gameboard* gb) {

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
        std::cout << "Schade, du hast alle Leben verloren!" << std::endl;
        return 1;
    }
    else if (gb->GetRelics() == 0) {
        system("CLS");
        std::cout << "Glückwunsch, du hast alle Relikte gefunden!" << std::endl;
        return 2;
    }
    else if (m->GetHp() == 0) {
        system("CLS");
        std::cout << "Wie Schade, das Monster hat dich gefangen!" << std::endl;
        return 1;
    }
    else if (turn == 40) {
        system("CLS");
        std::cout << "Du hast mehr als 40 Züge gebraucht, um alle Relikte zu finden..." << std::endl;
        return 1;
    }
    else {
        return 0;
    }
}


namespace oasenCrawler {


    std::vector<int> PlayOasenCrawler()
    {
        int fmsg = 0;
        char cont = 'a';
        int points = 0;
        int level = 0;
        

        srand(time(NULL));
        system("CLS");
        std::cout << "Nutze [W][A][S][D] um dich zu bewegen.\nFinde alle Relikte, um das Spiel zu gewinnen.\nDu verlierst:\n-wenn deine Leben auf 0 sinken\n-nach 40 Zuegen\n-wenn dich das Monster faengt" << std::endl; 
        std::cout << "Drücke eine beliebige Taste, um das Spiel zu starten!";
        _getch(); 
        do {
            int turn = 0;
            int checkstatus = 0;
            level++;
            std::string msg = "";
            player* p = new player(5);

            int mx = rand() % 2 + 3;
            int my = rand() % 2 + 3;
            monster* m = new monster(mx, my);


            gameboard* gb = new gameboard(p, m);

            gb->generateBoard();


            while (true) {
                system("CLS");

                gb->printBoard();

                p->printStats();
                std::cout << "Level: " << level << std::endl;

                printFightMessage(fmsg);
                fmsg = 0;

                std::cout << "uebrige Relikte: " << gb->GetRelics() << std::endl;

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
                        msg = "Du kannst dich nicht weiter nach oben bewegen!";
                    }
                    break;
                case 's':
                    if (p->GetPy() != 4) {
                        p->SetPy(p->GetPy() + 1);
                        turn++;
                        m->MoveMonster(p->GetPx(), p->GetPy());
                    }
                    else {
                        msg = "Du kannst dich nicht weiter nach unten bewegen!";
                    }
                    break;
                case 'a':
                    if (p->GetPx() != 0) {
                        p->SetPx(p->GetPx() - 1);
                        turn++;
                        m->MoveMonster(p->GetPx(), p->GetPy());
                    }
                    else {
                        msg = "Du kannst dich nicht weiter nach links bewegen!";
                    }
                    break;
                case 'd':
                    if (p->GetPx() != 4) {
                        p->SetPx(p->GetPx() + 1);
                        turn++;
                        m->MoveMonster(p->GetPx(), p->GetPy());
                    }
                    else {
                        msg = "Du kannst dich nicht weiter nach rechts bewegen!";
                    }
                    break;
                default:
                    msg = "Ungültige Eingabe!";
                    continue;
                }

                fmsg = checkInteraction(p, gb);
                checkstatus = terminate(p, gb, m, turn);
                if (checkstatus == 0) {

                }
                else if (checkstatus == 1) {
                      break;
                }
                else if (checkstatus == 2) {
                    std::cout << "Möchtest du weiter spielen? [y] [n]" << std::endl;

                    while (cont != 'y' || cont != 'n') {
                        cont = _getch();
                        if (cont == 'y') {
                            break;
                        }
                        else if (cont == 'n') {
                            break;
                        }
                        else {
                            std::cout << "invalid input" << std::endl;
                        }
                    }
                    break;
                }
            }
            points += p->GetRelics();
            delete p;
            delete m;
            delete gb;
            if (checkstatus == 1) {
                break;
            }
        } while (cont == 'y');

        std::cout << "Dein Punktestand: " << points << std::endl;

        //array für Übergabe //[0] = Score //[1] = Punkte für Gamble
        std::vector<int> vector;
        vector.push_back(points);
        vector.push_back(points *5);
        if (vector[1] > 100)
            vector[1] = 100;

        return vector;

    }
}