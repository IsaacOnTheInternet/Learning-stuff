#include <iostream>
#include <string>

class tamagochi{
protected:
    std::string name;
    unsigned int hunger;
    unsigned int happiness;
    unsigned int age;

};


class tamagochiFunct : public tamagochi{
public:

    void loadDefaults(class tamagochiFunct *tamagochi);

    std::string getName();
    void setName(std::string rename);

    int getHunger();
    void setHunger(int appetite);

    int getHappiness();
    void setHappiness(int happy);

    int getAge();
    void setAge(int older);
};

void tamagochiFunct::loadDefaults(class tamagochiFunct *tamagochi){

    tamagochi->name = "Poniko";
    tamagochi->hunger = 35;
    tamagochi->happiness = 35;
    tamagochi->age = 0;

};

std::string tamagochiFunct::getName(){
    return(name);
};

void tamagochiFunct::setName(std::string rename){
    name = rename;
};

int tamagochiFunct::getHunger(){
    return(hunger);
};

void tamagochiFunct::setHunger(int appetite){
    hunger = appetite;
};

int tamagochiFunct::getHappiness(){
    return(happiness);
};

void tamagochiFunct::setHappiness(int happy){
    happiness = happy;
};

int tamagochiFunct::getAge(){
    return(age);
};

void tamagochiFunct::setAge(int older){
    age = older;
};