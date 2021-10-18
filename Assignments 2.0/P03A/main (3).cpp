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
 * Description:
 *      This assigns our emoji values to proper variables and also generates a randomizing hands function.
 * 
 * Public Methods:
 *        static string RandHand();
          static string rock();
          static string paper();
          static string scissors();
          static string lizard();
          static string spock();
 * 
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
 * Description:
 *      This struct assigns weapons to players and also sets the rules of winning the game, so the assignment of weapons and who wins or loses.
 * 
 * Public Methods:
 *      Player();
        auto ifWin();
        Player operatir>();
 * 
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
    
/**
     * Public : ifWin
     * 
     * Description:
     *      Assigns weapons and weapons to players; also gives rules on who wins
     * 
     * Params:
     *       Player _p1
             Player _p2
     * 
     * Returns:
     *       true and false
     */
  auto ifWin(Player _p1, Player _p2){
    string p1 = _p1.weapon1;    //assigning a player to a weapon
    string p2 = _p2.weapon1;

    string rock = Hands::Rock();    //assigning emojis to strings for easy use
    string scissors= Hands::Scissors();
    string paper = Hands::Paper();
    string lizard = Hands::Lizard();
    string spock = Hands::Spock();

    if(p1==p2){
      p1=_p1.weapon2;   //if p1 and p2 have same weapon then they are given
      p2=_p1.weapon2;   //their back up weapon
    } 
    if(p1==p2){
      return false;     //If backup weapon is also the same it is a tie.
    }

    if((p1 == rock && p2 == lizard) ||    //bunch of statments giving guidelines of the rules
      (p1 == rock && p2 == scissors) ||   //determines winners
      (p1 == paper && p2 == rock) ||
      (p1 == paper && p2 == spock) ||
      (p1 == scissors && p2 == paper) ||
      (p1 == scissors && p2 == lizard) ||
      (p1 == lizard && p2 == spock) ||
      (p1 == lizard && p2 == paper) ||
      (p1 == spock && p2 == scissors) ||
      (p1 == spock && p2 == rock)){
        return true;
      } else{
        return false;       //if rules are flipped than role is switched
      }

    /**
     * Public : Player operator>()
     * 
     * Description:
     *      Overloads the > operator to dictate weather p1 or p2 wins or loses
     * 
     * Params:
     *       const Player rhs
     * 
     * Returns:
     *       winner
     */
    Player operator>(const Player rhs){
      bool winner = whoWon(*this, rhs);
      return winner;
    }

  }
};

int main() {
while (true && false) {  //infinate loop
  Player p1;
  Player p2; 
  if(p1 > p2){
    cout << "Player 1's " << p1 << "beat Player 2's " << p2 <<endl;
  }else if(p2 > p1){
    cout << "Player 2's " << p2 << "beat Player 1's " << p1 <<endl;
  }else{
    cout<<"It's a tie!"<<endl;
}}}