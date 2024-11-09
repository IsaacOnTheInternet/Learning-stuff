#include <stdio.h>
#include <stdlib.h>

/*Figuring out how github works, this is a dynamically allocated struct
which shows what you've typed at the end*/



//Note: Add a space before %s in scanf's -> scanf(" %s", var);
struct Prices{

    unsigned int price;

};

struct Fumos{

    char name[100];

//Nested struct
    struct Prices value;

};

void writeToStruct (struct Fumos *plush);
void readFromStruct (struct Fumos *plush);

int main (){

int items = 0;
    //Struct declaration
printf("How many fumos do you wanna add to the list?\n");
scanf(" %d", &items);

struct Fumos * plushie = malloc(items * sizeof(struct Fumos));
if(plushie == NULL){

    printf("Could not allocate block of memory\n");
    exit(1);

}

    for (int i = 0;  i  < items ; i++){
        writeToStruct(plushie);
        plushie++;
    }

    for(int i = 0; i < items; i++){
        plushie--;
    }

    for (int i = 0; i < items ; i++){
        readFromStruct(plushie);
        plushie++;
    }

    for(int i = 0; i < items; i++){
        plushie--;
    }

//You can only free malloc from the begginning of the block
free(plushie);
}

void writeToStruct (struct Fumos * plush){

//     Set the name of the fumo on a string 
     printf("Type a name!\n");
     scanf(" %[^\n]", plush->name);

//     Set the price of the fumo 
     printf("Type it's price!\n");
     scanf(" %d",  &plush->value.price);
    
};

void readFromStruct (struct Fumos *plush){

     printf("The name of the fumo is: %s\n", plush->name);
     printf("The price of the fumo is: %d\n", plush->value.price);

};