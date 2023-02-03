/* 
 * File:   Project1.cpp
 * Author: Ryan Ramos
 * Created on January 31, 2023, 2:04 PM
 * Purpose:  Project 1
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>
#include <random>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants not Variables 
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand(time(0));
    
    //Declare Variables
    const int deckSz = 52;
    //WILL BE REPLACED WITH ARRAYS IN PROJECT 2
    int deckRem = deckSz;
    
    //PLAYERS VALUES
    int numCrd1, suitCrd1,//PLAYERS CARD 1 VALUE AND SUIT
        numCrd2, suitCrd2,// PLAYERS CARD 2 VALUE AND SUIT
        cardVal1, cardVal2, //VALUE OF PLAYERS CARD 
        total, //TOTAL VALUE OF PLAYERS CARDS
            crdCnt; //AMOUNT OF CARDS PLAYER HAS IN DECK
    
    string suit1, suit2, //USED TO COMPARE AND FIND WHAT SUIT PLAYERS CARDS HAS
           card1, card2; //USED TO COMPARE AND FIND WHAT CARDS PLAYER HAS
            
    
    //ENEMY BOT VALUES
    int enCrd1, enemSt1,//ENEMY CARD 1 VALUE AND SUIT
        enCrd2, enemSt2, // ENEMY CARD 2 VALUE AND SUIT
        enemV1, enemV2, //VALUE OF ENEMYS CARD 
        enTotal, //TOTAL VALUE OF ENEMIES CARDS
            crdCntE; //AMOUNT OF CARDS ENEMY HAS IN DECK
    
    string eSuit1, eSuit2, //USED TO COMPARE AND FIND WHAT SUIT ENEMYS CARDS HAS
           eCard1, eCard2, //USED TO COMPARE AND FIND WHAT CARDS ENEMY HAS
            eChoice; //WHEN THE ENEMY RECIEVES AN ACE
    
    //OTHER
    char choiceM, continu;
    int maxVal = 21, //HIGHEST VALUE BEFORE YOU LOSE
    pile = 4; //STANDARD SIZE OF PILE
    string oneOrNo; //WHEN THE PLAYER RECIEVES AN ACE//HOW MANY CARDS ARE ON THE LINE? (WILL BE USED IN A FUNCTION & CALL FROM ARRAY IN P2) WILL BE STATIC
    bool gameOvr = false; //BOOL TO CHECK IF GAME IS OVER
    
    //Initialize Variables
    crdCnt = 0;
    crdCntE = 0;
    //WELCOME MESSAGE & MENU (WILL BE REPLACED WITH A FUNCTION IN PROJECT 2)
    cout << "Welcome to 21: The Card Game\n----------------------------\n" <<
            "Enter '1' to PLAY\n" <<
            "Enter '2' for HELP\n" <<
            "Enter '3' to EXIT\n";
    cin >> choiceM;
    
    //Map/Process the Inputs -> Outputs
    
    //MENU SWITCH CASE (FUNCTION IN P2)
    bool isValid = false;
    while(isValid == false){
    switch(choiceM){
        case '0': //WELCOME MESSAGE & MENU (WILL BE REPLACED WITH A FUNCTION IN PROJECT 2)
            isValid = true;
            cout <<
            "Welcome to 21: The Card Game\n----------------------------\n" <<
            "Enter '1' to PLAY\n" <<
            "Enter '2' for HELP\n" <<
            "Enter '3' to EXIT\n";
            cin >> choiceM; 
            if(choiceM != '1' || choiceM != '2' || choiceM != '3' || choiceM != '0') 
                isValid = false; break;
        case '1': /* GAME */ isValid = true; break; // EVENTUAL FUNCTION IN P2
        case '2': /* INSTRUCTIONS */ isValid = true;
                cout << "------------\nINSTRUCTIONS\n------------\n\n\n" <<
                "21 is a card game where you are given two cards every round. Each card has a value." <<
                "Number cards retain the value of their number. EX: The 3 of Spades has a value of 3." <<
                "Face cards retain a value of 10. EX: The Queen of Hearts has a value of 10." << 
                "An Ace leaves you with the decision to choose its value of 1 or 11." <<
                "The goal of this game is to win as many rounds as possible. Winning a round grants you with the cards in the pile, and at play that round." <<
                "If you tie, the cards you just played with will be added to the pile and you will continue rounds until somebody wins." <<
                "The game is over when there are no more remaining cards in the deck." << 
                "The player with the highest amount of cards collected at the end of the game wins.\n" <<
                "TO RETURN TO MENU ENTER 0, TO PLAY ENTER 1, TO EXIT ENTER 3.\n";
                cin >> choiceM; 
                if(choiceM != '1' || choiceM != '2' || choiceM != '3' || choiceM != '0') 
                    isValid = false; break;
        case '3': cout << "Exiting game."; exit(0); break;
        default: cout << "Invalid input please enter 0 to return to the Main Menu, " <<
                              "enter 1 to play the game, enter 2 for help, or enter 3 to exit.\n";
                isValid = false;
                cin >> choiceM;
        }
    }
    
    
    //Display Inputs/Outputs
    
                             //TITLE
    cout << "               GAME STARTED                \n" <<
            "The cards will now be shuffled & distributed.\n\n";
    
    //CREATING/DISTRIBUTING CARDS (FUNCTION IN P2 USING ARRAYS
    
                            //THE GAME
    while(gameOvr == false){
        
                                    //PLAYER
    for(int i = 0; i < 2; i++){
        numCrd1 = rand()%13+1; //ASSIGNS THE CARD A RANDOM VALUE, 1-13, ABOVE 10 IS JACK, QUEEN, KING
        suitCrd1 = rand()%4+1; //ASSIGNS THE CARD A RANDOM SUIT, 1 = SPADES, 2 = HEARTS, 3 = DIAMONDS, 4 = CLUBS
        
        numCrd2 = rand()%13+1; //ASSIGNS THE CARD A RANDOM VALUE, 1-13, ABOVE 10 IS JACK, QUEEN, KING
        suitCrd2 = rand()%4+1; //ASSIGNS THE CARD A RANDOM SUIT, 1 = SPADES, 2 = HEARTS, 3 = DIAMONDS, 4 = CLUBS
        
    //DECIDES WHAT THE FIRST CARD IS BASED ON THE RANDOM (FUNCTION IN P2)
    switch(numCrd1){
        case 13: card1 = "King"; break;
        case 12: card1 = "Queen"; break;
        case 11: card1 = "Jack";  break;
        case 10: card1 = "10"; break;
        case 9: card1 = "9"; break;
        case 8: card1 = "8"; break;
        case 7: card1 = "7"; break;
        case 6: card1 = "6"; break; //ADD A COUNTER FOR EACH CARD
        case 5: card1 = "5"; break;
        case 4: card1 = "4"; break;
        case 3: card1 = "3"; break;
        case 2: card1 = "2"; break;
        case 1: card1 = "Ace"; break;
    }
    
    //DECIDES WHAT THE FIRST CARD'S SUIT IS BASED ON THE RANDOM (FUNCTION IN P2)
    switch(suitCrd1){
        case 4: suit1 = "of Spades"; break;
        case 3: suit1 = "of Hearts"; break;
        case 2: suit1 = "of Diamonds"; break;
        case 1: suit1 = "of Clubs"; break;
    }
    
    //MAKES SURE THE CARDS ARE NOT THE SAME, IF THEY AREM RE-ASIGN VALUES
    if(numCrd1 == numCrd2 && suitCrd1 == suitCrd2){
        numCrd2 = rand()%13+1; //ASSIGNS THE CARD A RANDOM VALUE, 1-13, ABOVE 10 IS JACK, QUEEN, KING
        suitCrd2 = rand()%4+1; //ASSIGNS THE CARD A RANDOM SUIT, 1 = SPADES, 2 = HEARTS, 3 = DIAMONDS, 4 = CLUBS
    }
    
    //DECIDES WHAT THE SECOND CARD IS BASED ON THE RANDOM (FUNCTION IN P2)
    switch(numCrd2){
        case 13: card2 = "King";  break;
        case 12: card2 = "Queen"; break;
        case 11: card2 = "Jack";  break;
        case 10: card2 = "10"; break;
        case 9: card2 = "9"; break;
        case 8: card2 = "8"; break;
        case 7: card2 = "7"; break;
        case 6: card2 = "6"; break; //ADD A COUNTER FOR EACH CARD
        case 5: card2 = "5"; break;
        case 4: card2 = "4"; break;
        case 3: card2 = "3"; break;
        case 2: card2 = "2"; break;
        case 1: card2 = "Ace"; break;
    }
    
    //DECIDES WHAT THE SECOND CARD'S SUIT IS BASED ON THE RANDOM (FUNCTION IN P2)
    switch(suitCrd2){
        case 4: suit2 = "of Spades"; break;
        case 3: suit2 = "of Hearts"; break;
        case 2: suit2 = "of Diamonds"; break;
        case 1: suit2 = "of Clubs"; break;
    }
    }
    
    //KEEPS CARD VALUES TO GAME RULES
    if(numCrd1 >= 10)
        cardVal1 = 10;
    else
        cardVal1 = numCrd1;
    
    if(numCrd2 >= 10)
        cardVal2 = 10;
    else
        cardVal2 = numCrd2;
    
                                    //ENEMY
    //CREATING/DISTRIBUTING CARDS (FUNCTION IN P2 USING ARRAYS
    for(int i = 0; i < 2; i++){
        enCrd1 = rand()%13+1; //ASSIGNS THE CARD A RANDOM VALUE, 1-13, ABOVE 10 IS JACK, QUEEN, KING
        enemSt1 = rand()%4+1; //ASSIGNS THE CARD A RANDOM SUIT, 1 = SPADES, 2 = HEARTS, 3 = DIAMONDS, 4 = CLUBS
        
        enCrd2 = rand()%13+1; //ASSIGNS THE CARD A RANDOM VALUE, 1-13, ABOVE 10 IS JACK, QUEEN, KING
        enemSt2 = rand()%4+1; //ASSIGNS THE CARD A RANDOM SUIT, 1 = SPADES, 2 = HEARTS, 3 = DIAMONDS, 4 = CLUBS
        
    //DECIDES WHAT THE FIRST CARD IS BASED ON THE RANDOM (FUNCTION IN P2)
    switch(enCrd1){
        case 13: eCard1 = "King"; break;
        case 12: eCard1 = "Queen"; break;
        case 11: eCard1 = "Jack";  break;
        case 10: eCard1 = "10"; break;
        case 9: eCard1 = "9"; break;
        case 8: eCard1 = "8"; break;
        case 7: eCard1 = "7"; break;
        case 6: eCard1 = "6"; break; //ADD A COUNTER FOR EACH CARD
        case 5: eCard1 = "5"; break;
        case 4: eCard1 = "4"; break;
        case 3: eCard1 = "3"; break;
        case 2: eCard1 = "2"; break;
        case 1: eCard1 = "Ace"; break;
    }
    
    //DECIDES WHAT THE FIRST CARD'S SUIT IS BASED ON THE RANDOM (FUNCTION IN P2)
    switch(enemSt1){
        case 4: eSuit1 = "of Spades"; break;
        case 3: eSuit1 = "of Hearts"; break;
        case 2: eSuit1 = "of Diamonds"; break;
        case 1: eSuit1 = "of Clubs"; break;
    }
    
    //MAKES SURE THE CARDS ARE NOT THE SAME, IF THEY AREM RE-ASIGN VALUES
        if(numCrd1 == enCrd1 && suitCrd1 == enemSt1){
            int num1 = rand()%13+1;
            int num2 = rand()%4+1;
            
            numCrd2 = num1; //ASSIGNS THE CARD A RANDOM VALUE, 1-13, ABOVE 10 IS JACK, QUEEN, KING
            suitCrd2 = num2; //ASSIGNS THE CARD A RANDOM SUIT, 1 = SPADES, 2 = HEARTS, 3 = DIAMONDS, 4 = CLUBS
        }
        
        if(numCrd2 == enCrd2 && suitCrd2 == enemSt2){
            int num1 = rand()%13+1;
            int num2 = rand()%4+1;
            
            numCrd2 = rand()%13+1; //ASSIGNS THE CARD A RANDOM VALUE, 1-13, ABOVE 10 IS JACK, QUEEN, KING
            suitCrd2 = rand()%4+1; //ASSIGNS THE CARD A RANDOM SUIT, 1 = SPADES, 2 = HEARTS, 3 = DIAMONDS, 4 = CLUBS
        }
        if(enCrd1 == enCrd2 && enemSt1 == enemSt2){
            int num1 = rand()%13+1;
            int num2 = rand()%4+1;
            
            numCrd2 = rand()%13+1; //ASSIGNS THE CARD A RANDOM VALUE, 1-13, ABOVE 10 IS JACK, QUEEN, KING
            suitCrd2 = rand()%4+1; //ASSIGNS THE CARD A RANDOM SUIT, 1 = SPADES, 2 = HEARTS, 3 = DIAMONDS, 4 = CLUBS
        }
    
    //DECIDES WHAT THE SECOND CARD IS BASED ON THE RANDOM (FUNCTION IN P2)
    switch(enCrd2){
        case 13: eCard2 = "King";  break;
        case 12: eCard2 = "Queen"; break;
        case 11: eCard2 = "Jack";  break;
        case 10: eCard2 = "10"; break;
        case 9: eCard2 = "9"; break;
        case 8: eCard2 = "8"; break;
        case 7: eCard2 = "7"; break;
        case 6: eCard2 = "6"; break; //ADD A COUNTER FOR EACH CARD
        case 5: eCard2 = "5"; break;
        case 4: eCard2 = "4"; break;
        case 3: eCard2 = "3"; break;
        case 2: eCard2 = "2"; break;
        case 1: eCard2 = "Ace"; break;
    }
    
    //DECIDES WHAT THE SECOND CARD'S SUIT IS BASED ON THE RANDOM (FUNCTION IN P2)
    switch(enemSt2){
        case 4: eSuit2 = "of Spades"; break;
        case 3: eSuit2 = "of Hearts"; break;
        case 2: eSuit2 = "of Diamonds"; break;
        case 1: eSuit2 = "of Clubs"; break;
    }
    }
    
    //KEEPS CARD VALUES TO GAME RULES
    if(enCrd1 >= 10)
        enemV1 = 10;
    else
        enemV1 = enCrd1;
    
    if(enCrd1 >= 10)
        enemV2 = 10;
    else
        enemV2 = enCrd2;
    
    //OUTPUT WHAT THE USER AND ENEMY GOT (FOR LOOP OR FUNCTION IN P2)
    cout << "Your cards are " << fixed << setw(82) << "The enemy's cards are\n--------------             ---------------------" 
            << endl << card1 << " " << suit1 << fixed << setw(21) << eCard1 << " " << eSuit1//CARD 1 OF PLAYER AND ENEMY
            << endl << card2 << " " << suit2 << fixed << setw(21) << eCard2 << " " << eSuit2 << endl; //CARD 2 OF PLAYER AND ENEMY
    
    /* //IF THE ENEMY GETS AN ACE, THEY GET TO PICK BETWEEN 1 OR 11 (FUNCTION IN P2, CARD1 & CARD2 WILL BE AN ARRAY)
    if(eCard1 == "Ace"){
        cout << "The enemy got an Ace, which means they will get to pick if the value of this card" <<
                " will be 1, or 11.\n";
        //RANDOM
    }
    
    if(card2 == "Ace"){
        cout << "The enemy got an Ace, which means they will get to pick if the value of this card" <<
                " will be 1, or 11.\n";
        //RANDOM
    } */
    
    enTotal = enemV1 + enemV2; //TOTAL VALUE OF ENEMIES CARDS
    
    //////////////////////////
    
    //IF THE USER GETS AN ACE, HE GETS TO PICK BETWEEN 1 OR 11 (FUNCTION IN P2, CARD1 & CARD2 WILL BE AN ARRAY)
    bool isValid = false;
    if(card1 == "Ace"){
        cout << "You got an Ace, which means you get to pick if the value of this card" <<
                " will be 1, or 11. Please input 1 or 11 to choose.\n";
        cin >> oneOrNo;
        
        //ENSURES THE USER INPUTS A VALID DECISION
        while(isValid == false){
            if(oneOrNo == "1"){
                isValid = true;
                cardVal1 = 1;
            }
            else if(oneOrNo == "11"){
                isValid = true;
                cardVal1 = 11;
            }
            else if(oneOrNo != "11" && oneOrNo != "1"){
                cout << "Invalid input. Please pick 1 or 11.\n";
                cin >> oneOrNo;
            }
       }
    }
    
    isValid = false;
    if(card2 == "Ace"){
        cout << "You got an Ace, which means you get to pick if the value of this card" <<
                " will be 1, or 11. Please input 1 or 11 to choose.\n";
        cin >> oneOrNo;
        
        //ENSURES THE USER INPUTS A VALID DECISION
        while(!isValid){
            if(oneOrNo == "1"){
                isValid = true;
                cardVal2 = 1;
            }
            else if(oneOrNo == "11"){
                isValid = true;
                cardVal2 = 11;
            }
            else if(oneOrNo != "11" && oneOrNo != "1"){
                cout << "Invalid input. Please pick 1 or 11.\n";
                cin >> oneOrNo;
            }
        }
    }
    
    total = cardVal1 + cardVal2; //TOTAL VALUE OF PLAYERS CARDS
    
    //OUTPUT CARD TOTALS
    cout << "\n     TOTALS\n----------------" << endl;
    
    if(total > 21)
        cout << "Your total was " << total << " . Which was greater than 21.\n" <<
                "The enemy's total was " << enTotal << endl;
    else if(total == 21)
        cout << "Your total was equal to 21. A perfect score!\n"  <<
                "The enemy's total was " << enTotal << endl;
    else{
        cout << "Your total was " << total << ".\n" <<
                "The enemy's total was " << enTotal << "." << endl;;
    }
    
    //WHO WON THIS ROUND
    if(total > enTotal && total <= maxVal){ //PLAYER WON
        cout << "You won this round. " << pile << " cards have been added to your deck.\n\n";
        crdCnt += pile;
        deckRem -= pile;
    }else if(enTotal > total && enTotal <= maxVal){ //ENEMY WON
        cout << "You have lost this round. " << pile << " cards have been added to the enemy's deck.\n\n";
        crdCntE += pile;
        deckRem -= pile;
    }else if(enTotal == total){ // TIE
        cout << "You have tied with the enemy. The stakes will now be doubled.\n\n";
        pile = pile + pile;
        deckRem -= pile;
    }
    else if(enTotal > maxVal && total > maxVal){ //BOTH WENT ABOVE MAX VALUE
        cout << "Your totals both went above the 21 and therefore you have tied with the enemy. The stakes will now be doubled.\n\n";
        pile = pile + pile;
        deckRem -= pile;
    }else if(enTotal > total && enTotal > maxVal && total < maxVal){ //IF ENEMY WENT OVER VALUE AND YOU DIDNT
        cout << "You won this round. " << pile << " cards have been added to your deck.\n\n";
        crdCnt += pile;
        deckRem -= pile;
    }else if(total > enTotal && total > maxVal && enTotal < maxVal){ //IF YOU WENT OVER VALUE AND ENEMY DIDNT
        cout << "You have lost this round. " << pile << " cards have been added to the enemy's deck.\n\n";
        crdCntE += pile;
        deckRem -= pile;
    }
    //PRINT HOW MUCH CARDS ARE IN BOTH PILES AND HOW MUCH ARE REMAINING IN THE MAIN DECK
    cout << "Your Deck: " << crdCnt << "     "
            "Enemy Deck: " << crdCntE << "     "
            "Remaining Cards: " << deckRem << endl;
    
    //WILL BE FOR LOOPED WITH ROUND COUNTERS IN P2
    if(deckRem > 0){
        cout << "Enter R when you are ready for the next round.\nEnter N to stop playing.\n";
        cin >> continu;
        bool valid = false; //
    
        while(valid == false){
        if(continu == 'R'){
            cout << "\n\n\n\n NEXT ROUND\n";
            valid = true;
        }else if(continu == 'N'){
            valid = true;
            cout << "Exiting game.";
            exit(0);
        }else{
            cout << "Invalid input. Please enter R to keep playing, or N to stop playing.\n";
            cin >> continu;
            }
        }
        
    }else if(deckRem <= 0){
            cout << "The deck is empty and the game is now over.\n\n";
            gameOvr = true;
        }
    }
    
                            //POST GAME
    
    if(crdCnt > crdCntE) //PLAYER WON
        cout << "               YOU WIN!\n           CONGRATULATIONS!";
    else if(crdCntE > crdCnt) // ENEMY WON
        cout << "               YOU LOST!\n          BETTER LUCK NEXT TIME!";
    else if(crdCnt == crdCntE)
        cout << "               YOU TIED!\n          WHAT ARE THE CHANCES!";

    
    
    //Clean up memory and files
    
    //Exit the Program
    return 0;
    }
