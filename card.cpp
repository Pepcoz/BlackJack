#include "card.h"
#include <iostream>
#include <string>

using namespace std;

card::card(){
}

card::card(int cardFace, string cardSuit, int valueFace){
  face = cardFace;
  suit = cardSuit;
  value = valueFace;
}

int card::getValue(){
    return value;
}

int card::getFace(){
  
  //Convert number to card face
  switch(face){
    case 1: cout << "A ";
    break;
    case 11: cout << "J ";
    break;
    case 12: cout << "Q ";
    break;
    case 13: cout << "K ";
    break;
  }
  return face;
}

string card::getSuit(){
  return suit;
}


//Prints out card face, card suit and card value
void card::displayCard(){
    switch(face){
      case 1: cout << "A ";
      break;
      case 11: cout << "J ";
      break;
      case 12: cout << "Q ";
      break;
      case 13: cout << "K ";
      break;
      default: cout << face;
    }
    cout << " " << getSuit() << " " << getValue() << endl;
}

card::~card(){
}
