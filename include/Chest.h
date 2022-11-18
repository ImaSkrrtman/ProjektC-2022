#ifndef _CHEST_H
#define _CHEST_H

typedef struct
{
    char left;
    char middle;
    char right;
} ChestAppearance;

class Chest
{
private:
    ChestAppearance _chestAppearance;

public:
    Chest(); // Konstruktor
    ~Chest(); // Destruktor

    void setChestAppearance(char, char, char);
    void setDefaultChestAppearance();

    ChestAppearance getChestAppearance();
};

#endif /* _CHEST_H */