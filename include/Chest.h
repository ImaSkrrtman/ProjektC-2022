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
public:
    Chest(); // Konstruktor
    ~Chest(); // Destruktor

    void setChestAppearance(char, char, char);
    void setDefaultChestAppearance();

    ChestAppearance getChestAppearance();

private:
    ChestAppearance _chestAppearance;
};

#endif /* _CHEST_H */