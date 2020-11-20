#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class card{
private:
  string suit;
  int face;
  int value;

public:
  card();
  card(int,string,int);
  
  //Setting each card with a face and suit
  string getSuit();

  //Gets the face of the card
  int getFace();
  int getValue();
  void displayCard();

  //Want to randomise the cards dealt
  ~card();
};
#endif
