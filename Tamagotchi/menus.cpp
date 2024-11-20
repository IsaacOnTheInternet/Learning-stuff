void loadFoodMenu(class tamagochiFunct *tama, class tamagochiInventoryFood *food){

std::cout << "---------------------------\n";
std::cout << "You've got\n";
std::cout << "(1) Apples: " << food->apple << "\n";
std::cout << "(2) Steaks: " << food->steak << "\n";
std::cout << "(3) Bag of Chips: " << food->chips << "\n";

std::cout << "Tip: The numbers in '()' are the items you feed " << tama->getName() << " with\n";
std::cout << "---------------------------\n";

};

void loadToysMenu(class tamagochiFunct *tama, class tamagochiInventoryToys *toys){

std::cout << "---------------------------\n";
std::cout << "You've got\n";
std::cout << "(1) Toy car: " << toys->car << " uses left\n";
std::cout << "(2) Ball: " << toys->ball << " uses left\n";
std::cout << "(3) Gameboy: " << toys->gameboy << " uses left\n";

std::cout << "Tip: The numbers in '()' are the times " << tama->getName() << " can play with\n";
std::cout << "---------------------------\n";

};

void mainMenu () {

    std::cout << "---------------------------\n";
    std::cout << "1 - Food\n";
    std::cout << "2 - Toys\n";
    std::cout << "3 - Skip time\n";
    std::cout << "4 - Settings\n";
    std::cout << "5 - Quit\n";
    std::cout << "---------------------------\n";

};

void displayMenu(){

    std::cout << "---------------------------\n";
    std::cout << "(1) Display all Stats\n";
    std::cout << "(2) Change Pet name\n";
    std::cout << "(3) Save Save\n";
    std::cout << "(4) Load Save\n";
    std::cout << "(5) Leave Settings\n";
    std::cout << "---------------------------\n";

};

void displayEverything(class tamagochiInventoryFood *food, class tamagochiInventoryToys *toys, class tamagochiFunct *tamagochi){

    std::cout << "---------------------------\n";
    std::cout << "Name: " << tamagochi->getName() << "\n";
    std::cout << "Happiness: " << tamagochi->getHappiness() << "\n";
    std::cout << "Hunger: " << tamagochi->getHunger() << "\n";
    std::cout << "Age: " << tamagochi->getAge() << "\n";

    loadFoodMenu(tamagochi, food);
    loadToysMenu(tamagochi, toys);

};