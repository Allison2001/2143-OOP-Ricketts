/*****************************************************************************
*
*  Author:           Allison Ricketts
*  Email:            taterrickets@gmail.com
*  Label:            P03A
*  Title:            RPSLS
*  Course:           2143 OOP
*  Semester:         Fall 2021
*
*  Description:
*       This program uses the power of vector manipulation and
        and overloaded operations to add, subtract, and ect. to vectors.
*
*  Usage:
*        Use this program by giving the main function
          instructions on combining two vectors into one.
*
*  Files: main.cpp
*****************************************************************************/
#include <fstream>
#include <iostream>
#include <map>
#include <string>
//#include "rockPaper.cpp"
using namespace std;

//Defining our emojis
#define ROCK2 u8"\U0001F5FB"
#define PAPER2 u8"\U0001F4C3"
#define SCISSORS2 u8"\U0001F52A"
#define LIZARD2 u8"\U0001F438"
#define SPOCK2 u8"\U0001F596"

/**
 * Hands
 * 
 * @description: A static class that only has references to
 *      emojis for printing out Rock Paper Scissors Lizard Spock
 * 
 * @methods:
 *      string RandHand()   : returns a random hand (emoji) 
 *      string Rock()       : returns the emoji for "rock" 
 *      string Paper()      : returns the emoji for "paper" 
 *      string Scissors()   : returns the emoji for "scissors" 
 *      string Lizard()     : returns the emoji for "lizard" 
 *      string Spock()      : returns the emoji for "spock" 
 */
struct Hands {
    const string rock = ROCK2;
    const string paper = PAPER2;
    const string scissors = SCISSORS2;
    const string lizard = LIZARD2;
    const string spock = SPOCK2;

    static map< string, string > Emojis;  // stl map
    //         name  , emoji

    static map< string, string > Names;  // stl map
    //         emoji  , name

    static string RandHand() {
        auto it = Emojis.begin();  // iterator to front of map

        std::advance(it, rand() % Emojis.size());  // advance some random amnt
                                                   //   of steps

        string random_hand = it->second;  // grab emoji from map

        return random_hand;  // return rand emoji
    }

    static string Rock() {
        return Emojis["rock"];
    }
    static string Paper() {
        return Emojis["paper"];
    }
    static string Scissors() {
        return Emojis["scissors"];
    }
    static string Lizard() {
        return Emojis["lizard"];
    }
    static string Spock() {
        return Emojis["spock"];
    }
};

/**
 * Player
 * 
 * @description: struct that gives each player their weapons and "fights"
 * 
 * @methods:
 *      Player()
 *      bool operator>()
 */
struct Player{
    string weapon1;
    string weapon2;
    // other possible stuff

    /**
     * Constructor guarantees a player has two different "weapons"
     */
    Player(){
        weapon1 = Hands::RandHand();
        weapon2 = Hands::RandHand();

        while(weapon2==weapon1){
            weapon2 = Hands::RandHand();
        }
    }
    // other possible methods

    //overrides > to compare player 1 and player 2
     bool operator>(const Player other) {
        if (this->weapon1 == ROCK2 && (other.weapon2 == LIZARD2 || other.weapon2 == SCISSORS2)) {
            return true;
        }
        else if (this->weapon1 == PAPER2 && (other.weapon2 == ROCK2 || other.weapon2 == SPOCK2)) {
            return true;
        }
        else if (this->weapon1 == SCISSORS2 && (other.weapon2 == PAPER2 || other.weapon2 == LIZARD2)) {
            return true;
        }
        else if (this->weapon1 == LIZARD2 && (other.weapon2 == SPOCK2 || other.weapon2 == PAPER2)) {
            return true;
        }
        else if (this->weapon1 == SPOCK2 && (other.weapon2 == SCISSORS2 || other.weapon2 == ROCK2)) {
            return true;
        }
        else {
            if (this->weapon2 == ROCK2 && (other.weapon2 == LIZARD2 || other.weapon2 == SCISSORS2)) {
            return true;
        }
        else if (this->weapon2 == PAPER2 && (other.weapon2 == ROCK2 || other.weapon2 == SPOCK2)) {
            return true;
        }
        else if (this->weapon2 == SCISSORS2 && (other.weapon2 == PAPER2 || other.weapon2 == LIZARD2)) {
            return true;
        }
        else if (this->weapon2 == LIZARD2 && (other.weapon2 == SPOCK2 || other.weapon2 == PAPER2)) {
            return true;
        }
        else if (this->weapon2 == SPOCK2 && (other.weapon2 == SCISSORS2 || other.weapon2 == ROCK2)) {
            return true;
        }
        else{
          return false;
        }
        }
    }
};

// initialize static data member for
// hands struct (class)
map< string, string > Hands::Emojis = {
    {"rock", ROCK2},
    {"paper", PAPER2},
    {"scissors", SCISSORS2},
    {"lizard", LIZARD2},
    {"spock", SPOCK2}};
// initialize static data member for
// hands struct (class)
map< string, string > Hands::Names = {
    {ROCK2, "rock"},
    {PAPER2, "paper"},
    {SCISSORS2, "scissors"},
    {LIZARD2, "lizard"},
    {SPOCK2, "spock"}};

  /**
     * takes the winner and prints results
     */
    void winner(Player p1, Player p2) {
        for (int i = 0; i < 25; i++) {
            if (p1 > p2) {
                cout << "Player 1 wins!" << endl;
            }
            else if (p2 > p1) {
                cout << "Player 2 wins!" << endl;
            }
            else {
                cout << "It's a tie!" << endl;
            }
        }
    }

  int main(){
    Player p1;
    Player p2;
    winner(p1,p2);
    return 0;
  }