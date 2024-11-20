#include "inventory.hpp"
#include "menus.cpp"

#define MAX_HUNGER 100
#define MAX_FUN 100


void displayEverything(class tamagochiInventoryFood *food, class tamagochiInventoryToys *toys, class tamagochiFunct *tamagochi);

//Feeding related functions
void loadFoodMenu(class tamagochiFunct *tama, class tamagochiInventoryFood *food);
void consumeFood(class tamagochiFunct *tama, class tamagochiInventoryFood *food);
bool checkIfFoodEmpty(class tamagochiInventoryFood *food, int input);
bool checkIfFoodIsFull(class tamagochiFunct *tama);
void useFood(class tamagochiFunct * tama, class tamagochiInventoryFood * food);

//Toys related functions
void loadToysMenu(class tamagochiFunct *tama, class tamagochiInventoryToys *toys);
void useToy(class tamagochiFunct *tama, class tamagochiInventoryToys *toys);
void playWithToy(class tamagochiFunct *tama, class tamagochiInventoryToys *toys);
bool checkIfToysEmpty(class tamagochiInventoryToys *toys, int input);
bool checkIfHappyIsFull(class tamagochiFunct *tama);

//Skip day functions
void skipDay(class tamagochiFunct *tama);
void changeStats(class tamagochiFunct *tama);

//To-do Settings functions
void displayMenu();
void configMenu(class tamagochiFunct *tama, class tamagochiInventoryFood *food, class tamagochiInventoryToys *toys);
void configChangePetName(class tamagochiFunct *tama);
bool verifyName(std::string name);
void configSaveGame(class tamagochiFunct *tama, class tamagochiInventoryFood * food, class tamagochiInventoryToys *toys);
void configLoadGame(class tamagochiFunct *tama, class tamagochiInventoryFood * food, class tamagochiInventoryToys *toys);


void mainMenu();

//main event
bool eventLoop (class tamagochiFunct *tamagochi){
tamagochiInventoryFood *food = new tamagochiInventoryFood;
tamagochiInventoryToys *toys = new tamagochiInventoryToys;


int input = 0;

tamagochi->loadDefaults(tamagochi);
food->loadDefaults(food);
toys->loadDefaults(toys);



while(1){

    mainMenu();

//If i really feel like being able to use words as input
//I can probably do this with an overloaded function
//or try out an stringstream, probably idk

std::cin >> input;
    if(std::cin.fail()){
        std::cin.clear();
            std::cin.ignore(10000, '\n');
    }

        switch(input){
            case 1:
                useFood(tamagochi, food);
                break;

            case 2:
                useToy(tamagochi, toys);
                break;

            case 3:
                skipDay(tamagochi);
                break;

            case 4:
                configMenu(tamagochi, food, toys);
                break;

            case 5:
                delete(food);
                delete(toys);
                return(0);
            default:
                std::cout << "That's not a function in this program\n";
        }
    }
};

/*************************************** 

All definitions of "Food" are past here

****************************************/

void useFood(class tamagochiFunct *tama, class tamagochiInventoryFood *food){

    loadFoodMenu(tama, food);

    consumeFood(tama, food);

};

void consumeFood(class tamagochiFunct *tama, class tamagochiInventoryFood *food){
int input = 0;
int buffer = 0;

    std::cout << "Tip: Type 4 to not feed " << tama->getName() << "\n";
    std::cout << "What do you wanna feed " << tama->getName() << " with?\n";

    while (input != 4){

    std::cin >> input;
        if(std::cin.fail()){
            std::cin.clear();
                std::cin.ignore(10000, '\n');
        }

        switch(input){

            case 1:
                if(!checkIfFoodEmpty(food, input) && !checkIfFoodIsFull(tama)){
                std::cout << "You gave " << tama->getName() << " 1 Apple\n";
                food->apple -= 1;
                buffer = tama->getHunger() + 15;
                tama->setHunger(buffer); 
                }else{
                    std::cout << tama->getName() << " is full!\n";
                }
                break;

            case 2:
                if(!checkIfFoodEmpty(food, input) && !checkIfFoodIsFull(tama)){
                std::cout << "You gave " << tama->getName() << " 1 Steak\n";
                food->steak -= 1;
                buffer = tama->getHunger() + 35;
                tama->setHunger(buffer); 
                }else{
                    std::cout << tama->getName() << " is full!\n";    
                }
                break;
            
            case 3:
                if(!checkIfFoodEmpty(food, input) && !checkIfFoodIsFull(tama)){
                std::cout << "You gave " << tama->getName() << " 1 Bag of chips\n";
                food->chips -= 1;
                buffer = tama->getHunger() + 25;
                tama->setHunger(buffer); 
                }else{
                    std::cout << tama->getName() << " is full!\n";
                }
                break;
            case 4:
            //Quit feed menu
                break;
            
            default:
                std::cout << "That's not a function in this program\n";
                    break;

            }

    if(MAX_HUNGER <= tama->getHunger()){
        tama->setHunger(MAX_HUNGER);
            std::cout << tama->getName() << "'s current hunger is: " << tama->getHunger() << "/ " << MAX_HUNGER << "\n";
        }else{
            std::cout << tama->getName() << "'s current hunger is: " << tama->getHunger() << "/ " << MAX_HUNGER << "\n";
        }

        std::cout << "What else do you wanna feed " << tama->getName() << " with?\n";
        loadFoodMenu(tama, food);
    }
};

bool checkIfFoodEmpty(class tamagochiInventoryFood *food, int input){

    switch(input){
        case 1:
                if (food->apple == 0){
                std::cout << "You don't have enough Apples!\n";
                    return(1);
                }break;
        case 2: 
                if (food->steak == 0){
                std::cout << "You don't have enough Steak!\n";

                    return(1);
                }break;
        case 3: 
                if(food->chips == 0){
                std::cout << "You don't have enough Bags of Chips!\n";
                    return(1);
                }break;
    }
    return(0);
};

bool checkIfFoodIsFull(class tamagochiFunct *tama){
    if(tama->getHunger() < MAX_HUNGER){
        return(0);
    }else{
        return(1);
    }
};

/*************************************** 

All definitions of "Toys" are past here

****************************************/

void useToy(class tamagochiFunct *tama, class tamagochiInventoryToys *toys){

    loadToysMenu(tama, toys);

    playWithToy(tama, toys);

};

void playWithToy(class tamagochiFunct *tama, class tamagochiInventoryToys *toys)
{
    int input = 0;
int buffer = 0;

    std::cout << "Tip: Type 4 to not give " << tama->getName() << " a toy\n";
    std::cout << "What do wanna let " << tama->getName() << " play with?\n";

    while (input != 4){

    std::cin >> input;
        if(std::cin.fail()){
            std::cin.clear();
                std::cin.ignore(10000, '\n');
        }

        switch(input){

            case 1:
                if(!checkIfToysEmpty(toys, input) && !checkIfHappyIsFull(tama)){
                std::cout << "You let " << tama->getName() << " play with the Toy Car\n";
                toys->car -= 1;
                buffer = tama->getHappiness() + 5;
                tama->setHappiness(buffer); 
                }else if(toys->car == 0){
                std::cout << tama->getName() << " is tired of playing with the Toy Car!\n";
                }
                break;

            case 2:
                if(!checkIfToysEmpty(toys, input) && !checkIfHappyIsFull(tama)){
                std::cout << "You let " << tama->getName() << " play with the Ball\n";
                toys->ball -= 1;
                buffer = tama->getHappiness() + 10;
                tama->setHappiness(buffer); 
                }else if(toys->ball == 0){
                std::cout << tama->getName() << " is tired of playing with the Ball!\n";
                }
                break;
            
            case 3:
                if(!checkIfToysEmpty(toys, input) && !checkIfHappyIsFull(tama)){
                std::cout << "You let " << tama->getName() << " play with the Gameboy\n";
                toys->gameboy -= 1;
                buffer = tama->getHappiness() + 10;
                tama->setHappiness(buffer); 
                }else if (toys->gameboy == 0){
                std::cout << tama->getName() << " is tired of playing with the GameBoy!\n";
                }
                break;
            case 4:
            //Quit toy menu
                break;
            
            default:
                std::cout << "That's not a function in this program\n";
                    break;

            }

    if(MAX_FUN <= tama->getHappiness()){
        tama->setHappiness(MAX_FUN);
            std::cout << tama->getName() << "'s current happiness is: " << tama->getHappiness() << "/ " << MAX_FUN << "\n";
        }else{
            std::cout << tama->getName() << "'s current happiness is: " << tama->getHappiness() << "/ " << MAX_FUN << "\n";
        }

        loadToysMenu(tama, toys);
        std::cout << "What else do you wanna let " << tama->getName() << " play with?\n";
    }
};


bool checkIfToysEmpty(class tamagochiInventoryToys *toys, int input){

    switch(input){
        case 1:
                if (toys->car == 0){
                    return(1);
                }break;
        case 2: 
                if (toys->ball == 0){
                    return(1);
                }break;
        case 3: 
                if(toys->gameboy == 0){
                    return(1);
                }break;
    }
    return(0);
};

bool checkIfHappyIsFull(class tamagochiFunct *tama){
    if(tama->getHappiness() < MAX_FUN){
        return(0);
    }else{
        std::cout << tama->getName() << " is done playing today\n";
        return(1);
    }
};


/*************************************** 

All definitions of "Day" are past here

****************************************/

void skipDay(class tamagochiFunct *tama){
int input = 1;


    std::cout << "How many days do you wanna skip?\n";

do{
    std::cin >> input;
        if(std::cin.fail()){
            std::cin.clear();
                std::cin.ignore(10000, '\n');
            std::cout << "Cannot accept negative numbers, letters or 0\n";
        }
}while(input == 0);

    tama->setAge(tama->getAge() + input);

    changeStats(tama);

};

void changeStats (class tamagochiFunct *tama){
    if(tama->getAge() < 15){
        tama->setHunger(tama->getHunger() - 25);
        tama->setHappiness(tama->getHappiness() - 20); 
    }

    if (tama->getAge() >= 15 && tama->getAge() <= 40){
        tama->setHunger(tama->getHunger() - 40);
        tama->setHappiness(tama->getHappiness() - 30); 
    }

    if (tama->getAge() > 40){
        tama->setHunger(tama->getHunger() - 55);
        tama->setHappiness(tama->getHappiness() - 40); 

    }

//If for some reason it underflows
    if(tama->getHunger() < 0){
        tama->setHunger(0);
    }

    if(tama->getHappiness() < 0){
        tama->setHappiness(0);
    }
};

/*************************************** 

All definitions of "Settings" are past here

****************************************/

void configMenu(class tamagochiFunct *tama, class tamagochiInventoryFood *food, class tamagochiInventoryToys *toys){
int input = 0;

    while (input != 5){
    displayMenu();
            std::cin >> input;
                if(std::cin.fail()){
                    std::cin.clear();
                        std::cin.ignore(10000, '\n');
                }
        switch(input){

            case 1 :
                displayEverything(food, toys, tama);
                break;
            case 2:
                configChangePetName(tama);
                break;
            case 3:
                configSaveGame(tama, food, toys);
                break;
            case 4:
                configLoadGame(tama, food, toys);
                break;
            case 5:
                break;
                //Leave settings menu
            default:
                std::cout << "That's not a function in this program\n";
                break;

        }
    }
};

void configChangePetName(class tamagochiFunct *tama){
std::string name;

    std::cout << "Pick a new name for your pet!\n";

        std::getline(std::cin.ignore(), name);

        if(!verifyName(name)){
            tama->setName(name);
        }

};

bool verifyName(std::string name){

        if(name.length() > 20){
            std::cout << "Name cannot be more than 20 characters\n";
            return(1);
        }
        if(name.length() < 1){
            std::cout << "Name cannot be shorter than 1 character\n";
            return(1);
        }
        if(name[0] == ' '){
            std::cout << "Name cannot be empty\n";
            return(1);
        }

    return(0);
};

void configSaveGame(class tamagochiFunct *tama, class tamagochiInventoryFood * food, class tamagochiInventoryToys *toys){

    std::fstream fin;

    fin.open("Tamagochi_Save_File.txt", std::ios::in | std::ios::out | std::ios::trunc);

    if (fin.is_open())
        {
        fin << tama->getName() << std::endl;
        fin << tama->getHunger()<< std::endl;
        fin << tama->getHappiness()<< std::endl;
        fin << tama->getAge()<< std::endl;

        fin << food->apple << std::endl;
        fin << food->steak << std::endl;
        fin << food->chips << std::endl;

        fin << toys->car << std::endl;
        fin << toys->ball << std::endl;
        fin << toys->gameboy << std::endl;

        std::cout << "Save succesfully created!\n";

        }else{
            std::cout << "File couldn't be crated\n";
        }
    fin.close();
};

void configLoadGame(class tamagochiFunct *tama, class tamagochiInventoryFood * food, class tamagochiInventoryToys *toys){
std::fstream fout;
std::string tbuffer;
int buffer = 0;
size_t loop = 0;
    

    fout.open("Tamagochi_Save_File.txt", std::ios::in | std::ios::out);

if(fout.is_open()){
    while(!fout.eof()){
        getline(fout, tbuffer);
        
        std::stringstream (tbuffer) >> buffer; 
        switch(loop){
                    case 0:
                        tama->setName(tbuffer);
                        break;
                    case 1:
                        tama->setHunger(buffer);
                        break;
                    case 2:
                        tama->setHappiness(buffer);
                        break;
                    case 3:
                        tama->setAge(buffer);
                        break;
                    case 4:
                        food->apple = buffer;
                        break;
                    case 5:
                        food->steak = buffer;
                        break;
                    case 6:
                        food->chips = buffer;
                        break;
                    case 7:
                        toys->car = buffer;
                        break;
                    case 8:
                        toys->ball = buffer;
                        break;
                    case 9:
                        toys->gameboy = buffer;
                        break;
                    default: 
                    break;
                }
    loop++;
            }
        std::cout << "Save loaded succesfully!\n";
    }else{
        std::cout << "Could not load from file\n";
    }
};