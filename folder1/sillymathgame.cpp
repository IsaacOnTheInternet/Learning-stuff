#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;

struct game_data { // The default game data/start
    long double next_gain = 1;
    int multiplier = 1; 
    long day_counter = 0;
    long double money_counter = 0;
};

void game_shop_menu (){
    cout << "-------------------------------------" << endl;
    cout << "(0)    To exit the shop" << endl;
    cout << "(1)    2x Multiplier   Price: " << pow(5000, 1)<< endl;
    cout << "(2)    4x Multiplier   Price: " << pow(5000, 2)<< endl;
    cout << "(3)    8x Multiplier   Price: " << pow(5000, 3) << endl;
    cout << "(4)    16x Multiplier  Price: " << pow(5000, 4) << endl;
    cout << "(5)    32x Multiplier  Price: " << pow(5000, 5) << endl;
    cout << "(6)    64x Multiplier  Price: " << pow(5000, 6) << endl;
    cout << "(7)    Custom Multiplier   Price = (5000^[Multipliyer you want])" << endl;
    cout << "-------------------------------------" << endl;
};
void main_menu (){
    cout << "-------------------------------------" << endl;
    cout << "Press 1 to skip to the next day" << endl;
    cout << "Press 2 to show your stats" << endl;
    cout << "Press 3 to open the shop" << endl;
    cout << "Press 4 to open this menu again" << endl;
    cout << "Press 5 to quit game" << endl; 
    cout << "-------------------------------------" << endl;

};
void stats_menu (struct game_data *dat){
    cout << "-------------------------------------" << endl;
    cout << "Your next gain is: " << dat->next_gain << "\t" << endl;
    cout << "Your current money multiplier is: " << dat->multiplier << "\t" << endl;
    cout << "Your current money is: " << dat->money_counter << "\t" << endl;
    cout << "The current in-game day is: " << dat->day_counter << "\t" << endl;
    cout << "Press 4 to access the main menu" << endl;
    cout << "-------------------------------------" << endl;
};
void game_day (struct game_data *day){
    day->money_counter = (day->money_counter + day->next_gain) * day->multiplier;
    day->next_gain = (day->next_gain + (day->day_counter++)) * day->multiplier;

        cout << "-------------------------------------" << endl;
        cout << "Current day: " << day->day_counter << endl;
        cout << "Current money: " << day->money_counter << endl;
        cout << "-------------------------------------" << endl;

};
void game_shop_logic (struct game_data *buy){

    unsigned int input = 0;

        do{
            game_shop_menu ();
                cin >> input;
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }

                    if (input > 0 && input < 7){
                        if (buy->money_counter >= pow(5000, input)){

                            buy->money_counter = buy->money_counter - pow(5000, input);
                            buy->multiplier = pow(2, input);

                            cout << "Purchace succesful!" << endl;
                            sleep(1);                            
                        }
                            }else if (input == 7){

                                cout << "Pick your multiplier" << endl;
                                cin >> input;
                                    if (cin.fail()){

                                        cin.clear();
                                        cin.ignore(10000, '\n');
                                        cout << "Only whole numbers go in here!" << endl;
                                        break;
                                    };
                                    
                                    if (buy->money_counter >= pow(5000, input)){

                                    buy->money_counter = (buy->money_counter - pow(5000, input));
                                    buy->multiplier = pow(2, input);
                                        cout << "Purchace succesful!" << endl;                               
                                    };                            
                            }else{
                                cout << "You don't have enough money!" << endl;
                                sleep(1);

                    }
                        if (input == 0){
                            cout << "-------------------------------------" << endl;
                            cout << "Exiting shop!" << endl;
                            cout << "Your current multiplier is: " << buy->multiplier << endl;
                            cout << "Press 4 to access the main menu" << endl;
                            cout << "-------------------------------------" << endl;
                    };
                
        }while(input!=0);
};



int main () {
struct game_data gminfo;
short input = 0;
    main_menu ();
do{    
// Read input from the user.
cin >> input;

    if (cin.fail()){// Check if the input operation failed

        cin.clear();// Clear the error flags on the input stream.

        cin.ignore(10000, '\n');// leave the rest of the line so it doesnt make error in the future
    }
    
    if (input > 0 && input < 6){
            switch (input){
                case 1 :
                        game_day(&gminfo); // updates the day and the money
                    break; 
                case 2 :
                        stats_menu (&gminfo); // shows the stats menu
                    break; 
                case 3 :
                        game_shop_logic (&gminfo); // Opens the shop menu
                    break; 
                case 4 :
                        main_menu (); // shows the main menu again
                    break; 
                case 5: 
                    cout << "Quitting now!" << endl;
                    break;
            }
        } else {
                cout << "Something went wrong! Try again\nPress 4 to access the menu" << endl;
            } 
}while(input != 5);


}
