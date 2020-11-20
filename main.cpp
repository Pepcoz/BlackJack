//#include all the classes
#include "card.h"
#include "player.h"
#include "dealer.h"
#include <stdlib.h>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

int main(){
    while(1){
        int svalue=1;
        int cvalue=1;
        int dvalue=1;
        int hvalue=1;
        int snum=0;
        int cnum=0;
        int dnum=0;
        int hnum=0;
        bool bust=false;
        char userinput;
        bool hitting=true;
        bool error=true;

        //Starting random number generator
        srand(time(NULL));

        //Creating objects
        card *cards = new card[52];
        player ben;
        dealer deal;


        //Creating 52 card objects and placing them in to a 52 size array
        for(int i=0;i<13;i++){
            if(snum<10){
                snum=snum+1;
            }
            cards[i]=card(svalue,"Spades",snum);
            svalue=svalue+1;
        }

        for(int i=13;i<26;i++){
            if(cnum<10){
                cnum=cnum+1;
            }
            cards[i]=card(cvalue,"Clubs",cnum);
            cvalue=cvalue+1;
        }

        for(int i=26;i<39;i++){
            if(dnum<10){
                dnum=dnum+1;
            }
            cards[i]=card(dvalue,"Diamonds",dnum);
            dvalue=dvalue+1;
        }

        for(int i=39;i<52;i++){
            if(hnum<10){
                hnum=hnum+1;
            }
            cards[i]=card(hvalue,"Hearts",hnum);
            hvalue=hvalue+1;
        }

        //Dealing out first two cards and dispalying cards
        ben.deal(cards);
        cout << "You have" << endl;
        ben.getHand();
        cout << ben.getScore() << endl;

        //First round of hitting 
        while(error){
            cout << "Would you like to hit? y/n?" << endl;  
            cin >> userinput;
            if(userinput=='y'||userinput=='Y'){
                ben.hit(cards);
                error=false;
            }
            else if(userinput=='n'||userinput=='N'){
                hitting=false;
                error=false;
            }else{
                cout << "enter y/n"<< endl;
            }
            cout << "..................." << endl;
            cout << "You have" << endl;
            ben.getHand();
            cout << ben.getScore() << endl;
            if(ben.getScore()>21){
                bust=true;
            }
        }
        error=true;
        
        //Second round of hitting
        if(bust==false){
            if(hitting==true){
                while(error){
                    cout << "Would you like to hit again? y/n" << endl;
                    cin >> userinput;
                    if(userinput=='y'||userinput=='Y'){
                        ben.hit(cards);
                        error=false;
                    }
                    else if(userinput=='n'||userinput=='N'){
                        hitting=false;
                        error=false;
                    }else{
                        cout << "enter y/n"<< endl;
                    }
                    cout << "..................." << endl;
                    cout << "You have - " << endl;
                    ben.getHand();
                    if(ben.getScore()>21){
                        bust=true;
                    }
                    cout << ben.getScore() << endl;
                }
            }
            error=true;
        }

        //Final round of hitting
        if(bust==false){
            if(hitting==true){
                while(error){
                    cout << "Do you want to hit again? y/n ?" << endl;
                    cin >> userinput;
                    if(userinput=='n'||userinput=='N'){
                        hitting=false;
                        error=false;
                    }
                    else if(userinput=='y'||userinput=='Y'){
                    ben.hit(cards);
                    error=false;
                    }else{
                        cout << "enter y/n" << endl;

                    }
                    cout << "..................." << endl;
                    cout << "You have - " << endl;
                    ben.getHand();
                    cout << ben.getScore() << endl;
                }   
            }
        }
        

        //Initialising dealer actions
        cout << "..................." << endl;
        cout << "Dealer has - " << endl;
        deal.deal(cards);
        deal.hit(cards);
        deal.getHand();
        cout << deal.getScore() << endl;

        //setting win or lose conditions
        if((deal.getScore()>ben.getScore() && deal.getScore()<22) || ben.getScore()>21){
            cout << "Nice try,You lose" << endl;
        }else if(deal.getScore()<ben.getScore()||deal.getScore()>21){
            cout << "Congratulations, You win" << endl;
        }else{
            cout << "Draw" << endl;
        }

        //delete objects and array
        ben.~player();
        deal.~dealer();
        delete[] cards;
        cards=NULL;

        //Asking player if what to play again
        cout<<"Do you want to play again? y/n"<<endl;
        char choice;
        cin>>choice;
        if(choice=='y'){
            continue;
        }
        if(choice=='n'){
            break;
        }
    }
}
