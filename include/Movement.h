#ifndef _MOVEMENT_H
#define _MOVEMENT_H

#define UP_ARROW 72 // 0x48
#define DOWN_ARROW 80 // 0x50
#define LEFT_ARROW 75 // 0x4b
#define RIGHT_ARROW 77 // 0x4d

extern bool settingsChanged;

typedef struct
{
    char goUP;
    char goDOWN;
    char goLEFT;
    char goRIGHT;
    char undo; // stale
    char redo; // stale
} UserSettings;

class Movement
{
private:
    typedef struct
    {
        char up; // w albo 72 -> kod do strzalki
        char down; // s albo 80
        char left; // a albo 75
        char right; // d albo 77
        char redo; // r
        char undo; // u
    } MovementKeys;

    MovementKeys _movementKeys;

public:
    UserSettings userSettings;

    Movement(); // Konstruktor
    ~Movement(); // Destruktor

    void reset(); // reset ustawien, przypisanie w-a-s-d

    char getMovementSettingsUP();
    char getMovementSettingsDOWN();
    char getMovementSettingsLEFT();
    char getMovementSettingsRIGHT();

    void changeMovementToArrows(); // Zmiana z wasd na strzalki
};

#endif /* _MOVEMENT_H */