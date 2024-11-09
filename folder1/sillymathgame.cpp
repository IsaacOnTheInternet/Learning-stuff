#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

#define MAX_TIME 60
#define MAX_LEVEL 255
#define MAX_SCORE UINT_MAX

class max_parameters {

public:

    unsigned int clock= MAX_TIME;
    unsigned short level = MAX_LEVEL;
    unsigned int score = UINT_MAX;

};

class timer {
    public:
        double time_taken;
        int time1;
        int time2;
    };


class difficulty{
    public:
        short level = 0;
        short exponent = 1;
};

int get_current_time(){
        time_t current_time;
        time(&current_time);
            if (current_time == -1){
                return (-1);
            }else {
                return (current_time);
    }
};

int random_math (){

difficulty dif; 
max_parameters max;
    srand(get_current_time());
        int buffer = 0;
            if (dif.level % 4 == 1) {
                dif.exponent += 1;
                    if (dif.exponent > 8 ){
                        dif.exponent =- 1;
                    }
            }else{
            buffer +=  (rand() % 10) ^ dif.exponent / 4 ;
        }
return(buffer);    
};

void game_function (){
timer t;
int buffer = 0;
    // cazar el buffer, enviarlo a otra funcion, struct o array de ints alocado dinamicamente <- fun(not) 
    t.time1 = get_current_time();
        buffer = random_math();
    t.time2 = get_current_time();

};


int main (){
short input;

do{

cout << "1 to progress\n2 to quit\n Or else I'll sue you :3" << endl;
cin >> input;
    if(cin.fail()){
        cin.clear();
            cin.ignore(10000, '\n');
    }

switch (input){

    case (1):

        game_function();//game logic

            break;

}

}while (input != 2);

return (0);
}
