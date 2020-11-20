#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "card.h"
#include <iostream>

using namespace std;

class player{
private:
     //card *hand;
     bool hits;
     //int counter;
public:
    card *hand;
    int counter;
    
    player();

    void deal(card *deck);
    void getHand();
    void hit(card *deck);
    int getScore();

    ~player();
};
#endif