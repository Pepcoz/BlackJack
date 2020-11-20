#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <stdlib.h>
#include "player.h"
#include "card.h"
#include <string>

using namespace std;

class dealer:public player{
private:
    
public:
    dealer();
    virtual void dealerhit(card* deck);
    ~dealer();
};
#endif