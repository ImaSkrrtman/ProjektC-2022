#ifndef _SOKOBAN_H
#define _SOKOBAN_H

class Sokoban
{
private:
public:
    Sokoban();
    ~Sokoban();

    void menuEntryPoint();

    void startGame();

    void settingsEntryPoint();
    void appearanceSettings();
    void movementSettings();
};

#endif /* _SOKOBAN_H */