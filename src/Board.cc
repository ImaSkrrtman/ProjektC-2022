#include <ios>
#include <iostream>
#include <iterator>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "../include/Board.h"
#include "../include/Wrappers.h"
#include "../include/Types.h"
#include "../include/__Logs.h"
#include "../include/Movement.h"


#define DEBUG
#define PASS ;


//Konstruktor
Board::Board()
{
    this->_defaultPlayersPositionOnTheBoard.headX = 1;
    this->_defaultPlayersPositionOnTheBoard.headY = 72;

    this->_defaultPlayersPositionOnTheBoard.rightArmX = 2;
    this->_defaultPlayersPositionOnTheBoard.rightArmY = 73;

    this->_defaultPlayersPositionOnTheBoard.leftArmX = 2;
    this->_defaultPlayersPositionOnTheBoard.leftArmY = 71;

    this->_defaultPlayersPositionOnTheBoard.bodyX = 2;
    this->_defaultPlayersPositionOnTheBoard.bodyY = 72;

    this->_defaultPlayersPositionOnTheBoard.legsX = 3;
    this->_defaultPlayersPositionOnTheBoard.legsY = 72;

    ZeroMemory(&this->_charBoard, sizeof(this->_charBoard));
    ZeroMemory(&this->_board, sizeof(this->_board));
    ZeroMemory(&this->_playerAppearance, sizeof(this->_playerAppearance));

    memcpy(&this->_currentPlayersPositionOnTheBoard, &this->_defaultPlayersPositionOnTheBoard, sizeof(this->_currentPlayersPositionOnTheBoard));

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
    char delimiter = ' '; // Odstep glowy od sciany

    // Podstawowy wyglad
    this->_playerModel.setPlayersAppearance('0', '|', 'U', '|', 'M');
    this->_playerAppearance = this->_playerModel.getPlayersAppearance();

    (*board)[1][71] = delimiter; // Odstep glowy od sciany
    (*board)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = this->_playerAppearance.head;
    (*board)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = this->_playerAppearance.leftArm;
    (*board)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = this->_playerAppearance.body;
    (*board)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = this->_playerAppearance.rightArm;
    (*board)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = this->_playerAppearance.legs;
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
                    this->_charBoard[row][column] = ' ';
            }
        }
    }

    // Pobranie indexow X i Y miejsc gdzie sa punkty
    int pointIndex = 0;

    for (auto pt : this->_points) 
    {
        if (pointIndex % 2 == 0)
            this->_pointsX.push_back(pt); 
        else
            this->_pointsY.push_back(pt);

        pointIndex++;
    }

    logging.writeLog("Plansza zostala stworzona");
    logging.writeLog("Kopiowanie planszy");

    memcpy(&this->_board, &this->_charBoard, sizeof(this->_board));

    logging.writeLog("Plansza zostala skopiowana");
}


u_int Board::getTotalPoints()
{
    return this->_totalPoints;
}


void Board::printBoard()
{
    this->putAplayerOnTheBoard(&this->_board, this->_currentPlayersPositionOnTheBoard.headX, 
        this->_currentPlayersPositionOnTheBoard.headY, this->_currentPlayersPositionOnTheBoard.leftArmX,
        this->_currentPlayersPositionOnTheBoard.leftArmY, this->_currentPlayersPositionOnTheBoard.bodyX, 
        this->_currentPlayersPositionOnTheBoard.bodyY, this->_currentPlayersPositionOnTheBoard.rightArmX, 
        this->_currentPlayersPositionOnTheBoard.rightArmY, this->_currentPlayersPositionOnTheBoard.legsX, 
        this->_currentPlayersPositionOnTheBoard.legsY);
    
    std::cout << "\t\t       " << "[--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--]\n" << std::flush;
    for (auto row = 0; row < ROWS; row++) 
    {
        if (row < 10)
            std::cout << "\t\t" << row << "  ";
        else if (row >= 10)
            std::cout << "\t\t" << row << " ";
        
        for (auto column = 0; column < COLUMNS; column++) 
            std::cout << this->_board[row][column] << std::flush;
    }
    std::cout << "\t\t       " << "[--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--][--]\n\n" << std::flush;
}


void Board::changePlayersPosition(char userInput, bool settingsChanged)
{
    char (*boardPtr)[ROWS][COLUMNS] = &this->_board;

    if (!settingsChanged)
    {
        switch (userInput)
        {
            case 'w':
                if (this->_currentPlayersPositionOnTheBoard.headX == 0)
                {
                    PASS
                }
                else 
                {
                    memcpy(&this->_previousPlayersPositionOnTheBoard, &this->_currentPlayersPositionOnTheBoard, sizeof(this->_previousPlayersPositionOnTheBoard));

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';

                    this->_currentPlayersPositionOnTheBoard.headX--;
                    this->_currentPlayersPositionOnTheBoard.bodyX--;
                    this->_currentPlayersPositionOnTheBoard.leftArmX--;
                    this->_currentPlayersPositionOnTheBoard.rightArmX--;
                    this->_currentPlayersPositionOnTheBoard.legsX--;

                    logging.writeMovementLog("Uzytkownik nacisnal klawisz:", 'w');
                }
            break;
            case 's':
                if (this->_currentPlayersPositionOnTheBoard.legsX == 24)
                {
                    PASS
                }
                else
                {
                    memcpy(&this->_previousPlayersPositionOnTheBoard, &this->_currentPlayersPositionOnTheBoard, sizeof(this->_previousPlayersPositionOnTheBoard));

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';

                    this->_currentPlayersPositionOnTheBoard.headX++;
                    this->_currentPlayersPositionOnTheBoard.bodyX++;
                    this->_currentPlayersPositionOnTheBoard.leftArmX++;
                    this->_currentPlayersPositionOnTheBoard.rightArmX++;
                    this->_currentPlayersPositionOnTheBoard.legsX++;

                    logging.writeMovementLog("Uzytkownik nacisnal klawisz:", 's');
                }
            break;
            case 'a':
                if (this->_currentPlayersPositionOnTheBoard.leftArmY == 4)
                {
                    PASS
                }
                else
                {
                    memcpy(&this->_previousPlayersPositionOnTheBoard, &this->_currentPlayersPositionOnTheBoard, sizeof(this->_previousPlayersPositionOnTheBoard));

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';

                    this->_currentPlayersPositionOnTheBoard.headY--;
                    this->_currentPlayersPositionOnTheBoard.bodyY--;
                    this->_currentPlayersPositionOnTheBoard.leftArmY--;
                    this->_currentPlayersPositionOnTheBoard.rightArmY--;
                    this->_currentPlayersPositionOnTheBoard.legsY--;

                    logging.writeMovementLog("Uzytkownik nacisnal klawisz:", 'a');
                }
            break;
            case 'd':
                if (this->_currentPlayersPositionOnTheBoard.rightArmY == 74)
                {
                    PASS
                }
                else
                {
                    memcpy(&this->_previousPlayersPositionOnTheBoard, &this->_currentPlayersPositionOnTheBoard, sizeof(this->_previousPlayersPositionOnTheBoard));

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';

                    this->_currentPlayersPositionOnTheBoard.headY++;
                    this->_currentPlayersPositionOnTheBoard.bodyY++;
                    this->_currentPlayersPositionOnTheBoard.leftArmY++;
                    this->_currentPlayersPositionOnTheBoard.rightArmY++;
                    this->_currentPlayersPositionOnTheBoard.legsY++;

                    logging.writeMovementLog("Uzytkownik nacisnal klawisz:", 'd');
                }
            break;
            case 'u':
                //? goBackToTheBeginning()
                    logging.writeMovementLog("Uzytkownik nacisnal klawisz:", 'u');
            break;
            case 'r':
                if (memcmp(&this->_currentPlayersPositionOnTheBoard, &this->_defaultPlayersPositionOnTheBoard, sizeof(this->_currentPlayersPositionOnTheBoard)) == 0)
                {
                    PASS
                }
                else
                {
                    (*boardPtr)[this->_previousPlayersPositionOnTheBoard.headX][this->_previousPlayersPositionOnTheBoard.headY] = '0';
                    (*boardPtr)[this->_previousPlayersPositionOnTheBoard.bodyX][this->_previousPlayersPositionOnTheBoard.bodyY] = 'U';
                    (*boardPtr)[this->_previousPlayersPositionOnTheBoard.leftArmX][this->_previousPlayersPositionOnTheBoard.leftArmY] = '|';
                    (*boardPtr)[this->_previousPlayersPositionOnTheBoard.rightArmX][this->_previousPlayersPositionOnTheBoard.rightArmY] = '|';
                    (*boardPtr)[this->_previousPlayersPositionOnTheBoard.legsX][this->_previousPlayersPositionOnTheBoard.legsY] = 'M';

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';
                }

                    logging.writeMovementLog("Uzytkownik nacisnal klawisz:", 'r');
            break;
        }
    }
    else
    {
        switch (userInput)
        {
            case UP_ARROW:
                if (this->_currentPlayersPositionOnTheBoard.headX == 0)
                {
                    PASS
                }
                else 
                {
                    memcpy(&this->_previousPlayersPositionOnTheBoard, &this->_currentPlayersPositionOnTheBoard, sizeof(this->_previousPlayersPositionOnTheBoard));

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';

                    this->_currentPlayersPositionOnTheBoard.headX--;
                    this->_currentPlayersPositionOnTheBoard.bodyX--;
                    this->_currentPlayersPositionOnTheBoard.leftArmX--;
                    this->_currentPlayersPositionOnTheBoard.rightArmX--;
                    this->_currentPlayersPositionOnTheBoard.legsX--;
                }

                logging.writeLog("Uzytkownik nacisnal: strzalka w gore");
            break;
            case DOWN_ARROW:
                if (this->_currentPlayersPositionOnTheBoard.legsX == 24)
                {
                    PASS
                }
                else
                {
                    memcpy(&this->_previousPlayersPositionOnTheBoard, &this->_currentPlayersPositionOnTheBoard, sizeof(this->_previousPlayersPositionOnTheBoard));

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';

                    this->_currentPlayersPositionOnTheBoard.headX++;
                    this->_currentPlayersPositionOnTheBoard.bodyX++;
                    this->_currentPlayersPositionOnTheBoard.leftArmX++;
                    this->_currentPlayersPositionOnTheBoard.rightArmX++;
                    this->_currentPlayersPositionOnTheBoard.legsX++;
                }

                logging.writeLog("Uzytkownik nacisnal: strzalka w dol");
            break;
            case LEFT_ARROW:
                if (this->_currentPlayersPositionOnTheBoard.leftArmY == 4)
                {
                    PASS
                }
                else
                {
                    memcpy(&this->_previousPlayersPositionOnTheBoard, &this->_currentPlayersPositionOnTheBoard, sizeof(this->_previousPlayersPositionOnTheBoard));

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';

                    this->_currentPlayersPositionOnTheBoard.headY--;
                    this->_currentPlayersPositionOnTheBoard.bodyY--;
                    this->_currentPlayersPositionOnTheBoard.leftArmY--;
                    this->_currentPlayersPositionOnTheBoard.rightArmY--;
                    this->_currentPlayersPositionOnTheBoard.legsY--;
                }

                logging.writeLog("Uzytkownik nacisnal: strzalka w lewo");
            break;
            case RIGHT_ARROW:
                if (this->_currentPlayersPositionOnTheBoard.rightArmY == 74)
                {
                    PASS
                }
                else
                {
                    memcpy(&this->_previousPlayersPositionOnTheBoard, &this->_currentPlayersPositionOnTheBoard, sizeof(this->_previousPlayersPositionOnTheBoard));

                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.headX][this->_currentPlayersPositionOnTheBoard.headY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.bodyX][this->_currentPlayersPositionOnTheBoard.bodyY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.leftArmX][this->_currentPlayersPositionOnTheBoard.leftArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.rightArmX][this->_currentPlayersPositionOnTheBoard.rightArmY] = ' ';
                    (*boardPtr)[this->_currentPlayersPositionOnTheBoard.legsX][this->_currentPlayersPositionOnTheBoard.legsY] = ' ';

                    this->_currentPlayersPositionOnTheBoard.headY++;
                    this->_currentPlayersPositionOnTheBoard.bodyY++;
                    this->_currentPlayersPositionOnTheBoard.leftArmY++;
                    this->_currentPlayersPositionOnTheBoard.rightArmY++;
                    this->_currentPlayersPositionOnTheBoard.legsY++;
                }

                logging.writeLog("Uzytkownik nacisnal: strzalka w prawo");
            break;
            case 'u':
                //? goBackToTheBeginning()

                logging.writeMovementLog("Uzytkownik nacisnal klawisz:", 'u');
            break;
            case 'r':
                if (memcmp(&this->_currentPlayersPositionOnTheBoard, &this->_defaultPlayersPositionOnTheBoard, sizeof(this->_currentPlayersPositionOnTheBoard)) == 0)
                {
                    PASS
                }

                logging.writeMovementLog("Uzytkownik nacisnal klawisz:", 'u');
            break;
        }
    }
}


void Board::Clean()
{
    ZeroMemory(&this->_charBoard, sizeof(this->_charBoard));
    ZeroMemory(&this->_board, sizeof(this->_board));
    ZeroMemory(&this->_defaultPlayersPositionOnTheBoard, sizeof(this->_defaultPlayersPositionOnTheBoard));
    ZeroMemory(&this->_playerAppearance, sizeof(this->_playerAppearance));
    ZeroMemory(&this->_currentPlayersPositionOnTheBoard, sizeof(this->_currentPlayersPositionOnTheBoard));
    
    this->_totalPoints = 0;

    logging.writeLog("Wyczyszczono plansze");
}