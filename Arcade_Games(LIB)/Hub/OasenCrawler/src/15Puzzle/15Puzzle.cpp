#include <iostream>
#include <chrono>
#include <time.h>
#include "Player15.h"
#include <Windows.h>
#include <vector>
#include <conio.h>

void printPuzzle(std::vector<std::vector<int>>& puzzle, Player15* p1) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    std::cout << (char)201;
    
    for (int i = 0; i < 3; i++) {
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
    
    int skip = 0; 
    for (int i = 0; i < 4; i++) {
        if (skip == 0) {

            for (int j = 0; j < 4; j++) {
                std::cout << (char)186;

                if (i == p1->GetPy() && j == p1->GetPx()) {
                    SetConsoleTextAttribute(hConsole, 2);
                    if (puzzle[i][j] == 0) {
                        SetConsoleTextAttribute(hConsole, 39);
                    }
                }

                if (puzzle[i][j] != 0) {
                    if (puzzle[i][j] > 9) {
                        std::cout << " " << puzzle[i][j] << "";
                    } else {
                        std::cout << " " << puzzle[i][j] << " ";
                    }
                } else {
                    std::cout << "   ";
                }


                SetConsoleTextAttribute(hConsole, 7);
                
            }
            std::cout << (char)186;
            std::cout << std::endl;
            skip = 1;
        }

        if (i < 3) {
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

void shuffle(std::vector<std::vector<int>>& puzzle) {
    int rdm1 = 0;
    int rdm2 = 0; 
    int rdm3 = 0;
    int rdm4 = 0;
    int temp = 0; 
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
            rdm1 = rand() % 4;
            rdm2 = rand() % 4;
            rdm3 = rand() % 4;
            rdm4 = rand() % 4;

            temp = puzzle[rdm1][rdm2];
            puzzle[rdm1][rdm2] = puzzle[rdm3][rdm4];
            puzzle[rdm3][rdm4] = temp;
            
        }
    }

    int nuller = 0; 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (puzzle[i][j] == 0) {
                temp = puzzle[i][j];
                puzzle[i][j] = puzzle[3][3];
                puzzle[3][3] = temp; 
            }
        }
    }



    /*
    for (int i = 0; i < 90; i++) {
        rdm1 = rand() % 15;
        temp = singlevec[rdm1];
        singlevec[rdm1] = singlevec[rdm1 + 1];
        singlevec[rdm1 + 1] = temp;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            puzzle[i][j] = singlevec[(i * 4) + j];
        }
    }
    */
    
    
    //Parity fix: 
    int valid = 0; 

    while (valid == 0) {
        int row = 0;
        int inversions = 0;
        int prev = -1;

        std::vector<int> singlevec; 

        while (singlevec.size() > 0) {
            singlevec.erase(singlevec.begin());
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (puzzle[i][j] == 0) {
                    row = i;     
                }
                if (puzzle[i][j] == 0) {
                    singlevec.push_back(16);
                }
                else {
                    singlevec.push_back(puzzle[i][j]);
                } 
            }
        }

        for (int i = 0; i < singlevec.size() - 1; i++) {
            for (int j = i + 1; j < singlevec.size(); j++) {
                if (singlevec[i] > singlevec[j]) {
                    inversions++;
                }           
            }
        }

        if (inversions % 2 == 0) {
            valid = 1;
        }
        else {
            temp = puzzle[0][0];
            puzzle[0][0] = puzzle[0][1];
            puzzle[0][1] = temp;
        }

        /*
        if ((row == 0 || row == 2) && inversions % 2 == 1) {
            valid = 1;
            std::cout << "passt1" << std::endl; 
            std::cout << inversions << std::endl; 
        }
        else if ((row == 1 || row == 3) && inversions % 2 == 0) {
            valid = 1;
            std::cout << "passt2" << std::endl;
            std::cout << inversions << std::endl;
        }
        else {
            std::cout << "passt NICHT" << std::endl;

            temp = puzzle[0][0];
            puzzle[0][0] = puzzle[0][1];
            puzzle[0][1] = temp;
        }
        */
    }
}

namespace Puzzle15 
{


    std::vector<int> Play15Puzzle()
    {
        srand(time(NULL));

    
        int swapper = 0; 

        Player15* p1 = new Player15(); 

        std::vector<std::vector<int>> puzzle = { {0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15} };
        shuffle(puzzle);

        system("CLS");
        std::cout << "[W] [A] [S] [D] zum bewegen. [L] um einen Stein zu verschieben. [X] um das Spiel abzubrechen" << std::endl; 
        std::cout << "Beliebige Taste druecken um das Spiel zu starten" << std::endl; 
        _getch(); 
        auto start = std::chrono::high_resolution_clock::now();

        while (1) {
            system("CLS");

            printPuzzle(puzzle, p1);

            swapper = p1->move(puzzle);

            if (swapper == 5) {
                system("CLS");
                std::cout << "Spiel abgebrochen" << std::endl; 
                break; 
            }

            if (swapper != 0) {
                p1->swap(puzzle, swapper); 
            }

            int p = 0; 
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i == 3 && j == 3 && puzzle[3][3] == 0) {
                        p++;
                    }
                
                    if (puzzle[i][j] == (i * 4) + j + 1) {
                        p++;
                    }
                }
            }

            if (p == 16) {
                system("CLS");
                break; 
            }

        }



        auto end = std::chrono::high_resolution_clock::now();
        float time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        float seconds = time / 1000;
        if (swapper != 5) {
            std::cout << "Das Puzzle wurde in " << seconds << " Sekunden geloest!" << std::endl;
        }

        int points = 100 - seconds;

        if (points < 0)
            points = 0;

        std::vector<int> vector;
        vector.push_back(points);
        vector.push_back(points);
        if (vector[1] > 100)
            vector[1] = 100;

        return vector;
    }
}
