#include <iostream>
#include <iterator>
#include <math.h>
#include <stdio.h>
#include "../include/Board.h"
#include "../include/Wrappers.h"
#include "../include/Types.h"
#include "../include/__Logs.h"


//Konstruktor
Board::Board()
{
    this->_defaulltPlayersPositionOnTheBoard.headX = 1;
    this->_defaulltPlayersPositionOnTheBoard.headY = 72;

    this->_defaulltPlayersPositionOnTheBoard.rightArmX = 2;
    this->_defaulltPlayersPositionOnTheBoard.rightArmY = 73;

    this->_defaulltPlayersPositionOnTheBoard.leftArmX = 2;
    this->_defaulltPlayersPositionOnTheBoard.leftArmY = 71;

    this->_defaulltPlayersPositionOnTheBoard.bodyX = 2;
    this->_defaulltPlayersPositionOnTheBoard.bodyY = 72;

    this->_defaulltPlayersPositionOnTheBoard.legsX = 3;
    this->_defaulltPlayersPositionOnTheBoard.legsY = 72;

    ZeroMemory(&this->_charBoard, sizeof(this->_charBoard));
    ZeroMemory(&this->_board, sizeof(this->_board));

    this->_chest.setDefaultChestAppearance();
    this->_chestAppearance = this->_chest.getChestAppearance();
    this->_totalPoints = 0;
}


// Destruktor
Board::~Board()
{
    this->Clean();

    logging.writeLog("Zniszczono klase Board");
}


void Board::putAplayerOnTheBoard(char (*board)[ROWS][COLUMNS], u_int headX, u_int headY, u_int leftArmX, u_int leftArmY, 
    u_int bodyX, u_int bodyY, u_int rightArmX, u_int rightArmY, u_int legsX, u_int legsY)
{

}


void Board::renderBoard()
{
    srand(time(NULL));

    logging.writeLog("Rozpoczynanie tworzenia planszy");

    for (auto row = 0; row < ROWS; row++) 
    {
        for (auto column = 0; column < COLUMNS; column++) 
        {
            if (column == 79)
                this->_charBoard[row][column] = '\n';
            else if (column == 0 || column == 75)
                this->_charBoard[row][column] = '[';
            else if (column == 3 || column == 78)
                this->_charBoard[row][column] = ']';
            else if (column == 1 || column == 2 || column == 76 || column == 77)
                this->_charBoard[row][column] = '-';
            else 
            {
                if (((rand()%80)-45) == column) 
                {
                    logging.writeLog("Tworzenie punktu na planszy");

                    this->_charBoard[row][column] = 'o';
                    this->_points.push_back(row);
                    this->_points.push_back(column);

                    this->_totalPoints++;
                } 
                else 
                {
                    this->_charBoard[row][column] = ' ';
                }
            }
        }
    }

    // this->putAplayerOnTheBoard(&this->_charBoard, this->_defaulltPlayersPositionOnTheBoard.headX, 
    //     this->_defaulltPlayersPositionOnTheBoard.headY, this->_defaulltPlayersPositionOnTheBoard.leftArmX,
    //     this->_defaulltPlayersPositionOnTheBoard.leftArmY, this->_defaulltPlayersPositionOnTheBoard.bodyX, 
    //     this->_defaulltPlayersPositionOnTheBoard.bodyY, this->_defaulltPlayersPositionOnTheBoard.rightArmX, 
    //     this->_defaulltPlayersPositionOnTheBoard.rightArmY, this->_defaulltPlayersPositionOnTheBoard.legsX, 
    //     this->_defaulltPlayersPositionOnTheBoard.legsY);

    this->_charBoard[1][71] = ' '; // Odstep glowy od sciany
    this->_charBoard[this->_defaulltPlayersPositionOnTheBoard.headX][this->_defaulltPlayersPositionOnTheBoard.headY] = '0';
    this->_charBoard[this->_defaulltPlayersPositionOnTheBoard.leftArmX][this->_defaulltPlayersPositionOnTheBoard.leftArmY] = '|';
    this->_charBoard[this->_defaulltPlayersPositionOnTheBoard.bodyX][this->_defaulltPlayersPositionOnTheBoard.bodyY] = 'U';
    this->_charBoard[this->_defaulltPlayersPositionOnTheBoard.rightArmX][this->_defaulltPlayersPositionOnTheBoard.rightArmY] = '|';
    this->_charBoard[this->_defaulltPlayersPositionOnTheBoard.legsX][this->_defaulltPlayersPositionOnTheBoard.legsY] = 'M';

    logging.writeLog("Plansza zostala stworzona");
    logging.writeLog("Kopiowanie planszy");

    memcpy(&this->_board, &this->_charBoard, sizeof(this->_board));

    logging.writeLog("Plansza zostala skopiowana");

    int pointIndex = 0;

    /* std::cout << "points = { ";
    for (auto pt : this->_points) 
    {
        if (pointIndex % 2 == 0)
            std::cout << '\n';

        if (pointIndex % 2 == 0) 
        {
            std::cout << "\t" << "x = " << pt << ", ";
        }
        else
        {
            std::cout << "y = " << pt;
        }

        pointIndex++;
    }
    std::cout << "\n};";

    int pointsCount = 0;
    for (auto pt : this->_points) 
    {
        pointsCount++;
    }

    std::clog << "\n\nWszystkie punkty = " << pointsCount/2 << '\n'; */
}


u_int Board::getTotalPoints()
{
    return this->_totalPoints;
}


void Board::printBoard()
{
    std::cout << "\t\t       " << "[--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--]\n" << std::flush;
    for (auto row = 0; row < ROWS; row++) 
    {
        if (row < 10)
            std::cout << "\t\t" << row << "  ";
        else if (row >= 10)
            std::cout << "\t\t" << row << " ";
        
        for (auto column = 0; column < COLUMNS; column++) 
        {
            std::cout << this->_board[row][column] << std::flush;
        }
    }
    std::cout << "\t\t       " << "[--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--]\n\n" << std::flush;
}


void Board::Clean()
{
    ZeroMemory(&this->_charBoard, sizeof(this->_charBoard));
    ZeroMemory(&this->_board, sizeof(this->_board));
    ZeroMemory(&this->_defaulltPlayersPositionOnTheBoard, sizeof(this->_defaulltPlayersPositionOnTheBoard));
    
    this->_totalPoints = 0;

    logging.writeLog("Wyczyszczono plansze");
}