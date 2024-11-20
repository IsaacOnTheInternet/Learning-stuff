#include "main.hpp"
#include "logic.cpp"

int main (){
tamagochiFunct *func = new tamagochiFunct;

//Compile this compile the game 

while (1){
    if(!eventLoop(func)){
        break;
    }
}

delete func;
return(0);
}