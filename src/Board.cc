#include <iostream>
#include <iterator>
#include <list>
#include <math.h>
#include <stdio.h>
#include "../include/Board.h"
#include "../include/Wrappers.h"
#include "../include/Types.h"
#include "../include/__Logs.h"


//Konstruktor
Board::Board()
{
    ZeroMemory(&this->_charBoard, sizeof(this->_charBoard));
    ZeroMemory(&this->_board, sizeof(this->_board));
    this->_positionX = NULL;
    this->_positionY = NULL;
}


// Destruktor
Board::~Board()
{
    ZeroMemory(&this->_charBoard, sizeof(this->_charBoard));
    ZeroMemory(&this->_board, sizeof(this->_board));
    this->_positionX = NULL;
    this->_positionY = NULL;
}


void Board::renderBoard()
{
    srand(time(NULL));

    std::list<u_short> points;
    
    logging.writeLog("Rozpoczynanie tworzenia planszy");

    for (auto row = 0; row < ROWS; row++) {
        for (auto column = 0; column < COLUMNS; column++) {
            if (column == 79)
                this->_charBoard[row][column] = '\n';
            else if (column == 0 || column == 75)
                this->_charBoard[row][column] = '[';
            else if (column == 3 || column == 78)
                this->_charBoard[row][column] = ']';
            else if (column == 1 || column == 2 || column == 76 || column == 77)
                this->_charBoard[row][column] = '-';
            else {
                if (((rand()%80)-45) == column) {
                    logging.writeLog("Tworzenie punktu na planszy");

                    this->_charBoard[row][column] = 'o';
                    points.push_back(row);
                    points.push_back(column);
                } else {
                    this->_charBoard[row][column] = ' ';
                }
            }
        }
    }
    
    logging.writeLog("Plansza zostala stworzona");
    logging.writeLog("Kopiowanie planszy");

    memcpy(&this->_board, &this->_charBoard, sizeof(this->_board));

    logging.writeLog("Plansza zostala skopiowana");

    int pointIndex = 0;

    /* std::cout << "points = { ";
    for (auto pt : points) {
        if (pointIndex % 2 == 0)
            std::cout << '\n';

        if (pointIndex % 2 == 0)
            std::cout << "\t" << "x = " << pt << ", ";
        else
            std::cout << "y = " << pt;

        pointIndex++;
    }
    std::cout << "\n};";

    int pointsCount = 0;
    for (auto pt : points) {
        pointsCount++;
    }

    std::clog << "\n\nWszystkie punkty = " << pointsCount/2 << '\n'; */
}


void Board::printBoard()
{
    std::cout << "\t\t       " << "[--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--]\n" << std::flush;
    for (auto row = 0; row < ROWS; row++) {
        if (row < 10)
            std::cout << "\t\t" << row << "  ";
        else if (row >= 10)
            std::cout << "\t\t" << row << " ";
        
        for (auto column = 0; column < COLUMNS; column++) {
            std::cout << this->_board[row][column];
        }
    }
    std::cout << "\t\t       " << "[--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--]\n\n" << std::flush;
}