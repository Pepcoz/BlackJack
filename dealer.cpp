#include <iostream>
#include <stdlib.h>
#include "player.h"
#include "card.h"
#include "dealer.h"
#include <string>

using namespace std;

dealer::dealer(){
}

void dealer::dealerhit(card *deck){
    while(getScore()<17){
        //int integer = rand() % 52;
        //hand[2+counter]=deck[integer];
        //counter=counter+1;
        player::hit(deck);
    }
}

dealer::~dealer(){
    delete[] hand;
    hand = NULL;
}