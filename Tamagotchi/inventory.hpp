#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class tamagochiInventoryFood {

public:
    unsigned int apple;
    unsigned int steak;
    unsigned int chips;

public:
    void loadDefaults(class tamagochiInventoryFood * food);
};

class tamagochiInventoryToys{
public:
    unsigned int car;
    unsigned int ball;
    unsigned int gameboy;

    void loadDefaults(class tamagochiInventoryToys *toys);
};

void tamagochiInventoryFood::loadDefaults(class tamagochiInventoryFood *food){
    food->apple = 5;
    food->steak = 5;
    food->chips = 5;
};

void tamagochiInventoryToys::loadDefaults(class tamagochiInventoryToys *toys){
    toys->car = 5;
    toys->ball = 5;
    toys->gameboy = 5;
}