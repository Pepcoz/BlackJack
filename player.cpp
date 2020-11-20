#include "card.h"
#include "player.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;


player::player(){
    hand=new card[5];
    counter=0;
}

void player::deal(card *deck){
    int integer = rand() % 52;
    int temp=integer;
    hand[0]=deck[integer];
    integer = rand() % 52;

    //Ensure same cards are not dealt at first
    while(temp==integer){
        integer = rand() % 52;
    }
    hand[1]=deck[integer];
}

void player::hit(card *deck){

    //Using random number generator to add card to array
    int integer = rand() % 52;
    hand[2+counter]=deck[integer];
    counter=counter+1;
}

void player::getHand(){
    for(int i=0;i<2+counter;i++){
        hand[i].displayCard();
    }
}

int player::getScore(){
    int score=0;
    for(int i=0;i<2+counter;i++){
        score=score+hand[i].getValue();
    }
    return score;
}

player::~player(){
    delete[] hand;
    hand=NULL;
}
