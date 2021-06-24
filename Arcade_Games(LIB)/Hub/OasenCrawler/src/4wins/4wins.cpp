#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>

void printBoard(int gb[6][7]) {
    
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int skip = 0; 
 
    std::cout << (char)201;
    for (int i = 0; i < 6; i++) {
        std::cout << (char)205;
        std::cout << (char)205;
        std::cout << (char)205;
        std::cout << (char)203;
    }
    std::cout << (char)205;
    std::cout << (char)205;
    std::cout << (char)205;
    std::cout << (char)187;
    std::cout << std::endl;

    for (int i = 0; i < 6; i++) {

        if (skip == 0) {
            
            for (int j = 0; j < 7; j++) {
                std::cout << (char)186;

                if (gb[i][j] == 0) {
                    std::cout << "   ";
                }
                else if (gb[i][j] == 1) {
                    SetConsoleTextAttribute(hConsole, 4);
                    std::cout << " O ";
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else if (gb[i][j] == 3) {
                    SetConsoleTextAttribute(hConsole, 10);
                    std::cout << " O ";
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else {
                    SetConsoleTextAttribute(hConsole, 1);
                    std::cout << " O ";
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            std::cout << (char)186;
            std::cout << std::endl; 
            skip = 1;
        }
        
        if (i < 5) {
            std::cout << (char)204;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)206;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)206;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)206;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)206;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)206;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)206;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)185;
        }
        else {
            std::cout << (char)200;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)202;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)202;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)202;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)202;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)202;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)202;

            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)205;
            std::cout << (char)188;
        }



        if (skip == 0) {
            std::cout << (char)186;
            std::cout << "   ";
            std::cout << (char)186;
            std::cout << std::endl;
            skip = 1;
        }
        else {
            skip = 0; 
        }

        std::cout << std::endl;
    }
}

void test(int gb[6][7]) {
    gb[0][1] = 1;
}

void resetBoard(int gb[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            gb[i][j] = 0;
        }
    }
}

void placePiece(int pos, int gb[6][7], int* player) {

    for (int i = 5; i >= 0; i--) {
        if (gb[i][pos] == 0) {
            if (*player == 1) {
                gb[i][pos] = 1;
            }
            else {
                gb[i][pos] = 2;
            }
            break;
        }
    }
    if (*player == 1) {
        *player = 2;
    }
    else {
        *player = 1;
    }

}

int move(int pos, int gb[6][7], int* p) {
    char direction = ' '; 
    int valid = 0; 

    while (valid == 0) {
        direction = _getch();
        switch (direction) {
        case 'a':
            if (pos == 0) {
                std::cout << "Du kannst nicht weiter nach links gehen" << std::endl; 
            }
            else {
                pos--;
                valid = 1; 
            }
            break;
        case 'd':
            if (pos == 6) {
                std::cout << "Du kannst nicht weiter nach rechts gehen" << std::endl;
            }
            else {
                pos++;
                valid = 1; 
            }
            break;
        case '\r':
            if (gb[0][pos] == 0) {
                placePiece(pos, gb, p); 
                valid = 1; 
            }
            else {
                std::cout << "Hier ist bereits alles voll!" << std::endl; 
            }
            break;
        default:
            continue;
        }
    }
    return pos; 
}

void printArrow(int pos) {

    switch (pos) {
    case 0:
        std::cout << "  |" << std::endl;
        std::cout << "  V" << std::endl;
        break;
    case 1:
        std::cout << "      |" << std::endl;
        std::cout << "      V" << std::endl;
        break;
    case 2:
        std::cout << "          |" << std::endl;
        std::cout << "          V" << std::endl;
        break;
    case 3:
        std::cout << "              |" << std::endl;
        std::cout << "              V" << std::endl;
        break;
    case 4:
        std::cout << "                  |" << std::endl;
        std::cout << "                  V" << std::endl;
        break;
    case 5:
        std::cout << "                      |" << std::endl;
        std::cout << "                      V" << std::endl;
        break;
    case 6:
        std::cout << "                          |" << std::endl;
        std::cout << "                          V" << std::endl;
        break;
    default:
        break; 
    }
}


int wincondition(int gb[6][7], int player) {
    int count = 0; 

    //Horizontal Check
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 4; x++) {
            if (x + 3 < 7) {
                if (gb[y][x] == player && gb[y][x + 1] == player && gb[y][x + 2] == player && gb[y][x + 3] == player) {
                    gb[y][x] = 3;
                    gb[y][x + 1] = 3; 
                    gb[y][x + 2] = 3;
                    gb[y][x + 3] = 3;
                    return player;
                }
            }
        }
    }

    //Vertikal Check
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 3; y++) {
            if (y + 3 < 6) {
                if (gb[y][x] == player && gb[y + 1][x] == player && gb[y + 2][x] == player && gb[y + 3][x] == player) {
                    gb[y][x] = 3;
                    gb[y + 1][x] = 3;
                    gb[y + 2][x] = 3;
                    gb[y + 3][x] = 3;
                    return player;
                }
            }
        }
    }

    //Diagonal Check
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 7; x++) {
            if (x + 3 < 7 && y + 3 < 6) {
                if (gb[y][x] == player && gb[y + 1][x + 1] == player && gb[y + 2][x + 2] == player && gb[y + 3][x + 3] == player) {
                    gb[y][x] = 3;
                    gb[y + 1][x + 1] = 3;
                    gb[y + 2][x + 2] = 3;
                    gb[y + 3][x + 3] = 3;
                    return player;
                }
            }
            if (x + 3 < 7 && y - 3 > 0) {
                if (gb[y][x] == player && gb[y - 1][x + 1] == player && gb[y - 2][x + 2] == player && gb[y - 3][x + 3] == player) {
                    gb[y][x] = 3;
                    gb[y - 1][x + 1] = 3;
                    gb[y - 2][x + 2] = 3;
                    gb[y - 3][x + 3] = 3;
                    return player;
                }
            }
        }
    }

    return 0;
}

int fullBoard(int gb[6][7]) {
    int check = 0; 

    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 7; x++) {
            if (gb[y][x] == 0) {
                check = 1; 
            }
        }
    }

    if (check == 1) {
        return 0;
    }
    else {
        return 1; 
    }

}
namespace FourWins
{
    void PlayFourWins()
    {
        int player = 1;
        int* p = &player;
        int gb[6][7];
        int pos = 0;
        int p1points = 0;
        int p2points = 0;
        int stop = 0;
        char input;
        char val = 0;
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        system("CLS");
        std::cout << "[A][D] druecken, um durch die Spalten zu navigieren. [Enter] druecken, um einen Stein hineinzuwerfen." << std::endl; 
        std::wcout << "Beliebige Taste druecken, um das Spiel zu starten!" << std::endl; 
        _getch(); 

        do {
            resetBoard(gb);
            while (1) {
                system("CLS");
                printArrow(pos);
                printBoard(gb);

                if (player == 1) {
                    SetConsoleTextAttribute(hConsole, 4);
                    std::cout << "Spieler " << player;
                    SetConsoleTextAttribute(hConsole, 7);
                    std::cout << " ist am Zug" << std::endl; 
                }
                else {
                    SetConsoleTextAttribute(hConsole, 1);
                    std::cout << "Spieler " << player;
                    SetConsoleTextAttribute(hConsole, 7);
                    std::cout << " ist am Zug" << std::endl;
                }

                if (wincondition(gb, 1) == 1) {
                    system("CLS");
                    printBoard(gb);
                    SetConsoleTextAttribute(hConsole, 4);
                    std::cout << "Spieler 1 hat gewonnen!" << std::endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    p1points++;
                    break;
                }
                if (wincondition(gb, 2) == 2) {
                    system("CLS");
                    printBoard(gb);
                    SetConsoleTextAttribute(hConsole, 1);
                    std::cout << "Spieler 2 hat gewonnen!" << std::endl;
                    SetConsoleTextAttribute(hConsole, 7);
                    p2points++;
                    break;
                }
                pos = move(pos, gb, p);
                if (fullBoard(gb) == 1) {
                    system("CLS");
                    printBoard(gb);
                    std::cout << "Unentschieden!" << std::endl;
                    break;
                }
            }

            std::cout << "Willst du erneut spielen? [Enter] [n]" << std::endl;

            while (val == 0) {
                //std::cin >> input; 
                input = _getch();
                switch (input) {
                case '\r':
                    val = 1;
                    break;
                case 'n':
                    stop = 1;
                    val = 1;
                    break;
                default:
                    std::cout << "Ungueltige Eingabe" << std::endl;
                    continue;
                }
            }
            val = 0;
            input = ' ';
            player = 1;
        } while (stop == 0);
    }
}

