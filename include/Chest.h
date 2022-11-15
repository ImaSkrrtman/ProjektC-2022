#ifndef _CHEST_H
#define _CHEST_H

class Chest
{
private:
    typedef struct
    {
        char left;
        char middle;
        char right;
    } ChestAppearance;

    ChestAppearance _chestAppearance;

public:
    Chest(); // Konstruktor
    ~Chest(); // Destruktor

    void setChestAppearance(char='[', char='#', char=']');

    ChestAppearance getChestAppearance();
};

#endif /* _CHEST_H */