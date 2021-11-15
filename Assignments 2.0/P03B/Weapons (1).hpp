#include <iostream>
#include <vector>
#include <string>

#include "dice.hpp"
#include "helpers.hpp"

using namespace std;
#pragma once

/**
 * Weapon
 * 
 * Description:
 *      Sets up our default code and settings for weapons
 * 
 * Public Methods:
 *                    Weapon()
                      Weapon(vector<string>choices)
            double    use()
            friend ostream* operator<<(ostream os, const Weapon& w)

 *               
 * Private Methods:
 *        none
 * 
 */
class Weapon {
public:
    string name;    // name of weapon
    string damage;  // damage per roll or "use"
    Dice*  die;

    
    Weapon() {
        name = "Fists&Feet";
        damage = "1.d.4";
        die = new Dice(damage);
    }
    /**
     * @brief Overloaded Constructor for a new Base Weapon object
     *  Also invokes the Dice class constructor with the "die" type
     * @param choices-vector of string "die" choices like {"2.d.8","2.d.10","3.d.4"}
     */
    Weapon(vector< string > choices) {
        name = "Fists&Feet";
        damage = randomChoice(choices);
        die = new Dice(damage);
    }

    double use() {
        return die->roll();
    }

    friend ostream& operator<<(ostream& os, const Weapon& w) {
        return os << "[" << w.name << " , " << w.damage << "]";
    }
};

/**
 * Sword
 * 
 * Description:
 *      Sets up our default code and settings for swords whcih are used by warriors and elves
 * 
 * Public Methods:
 *                    Sword()
 *               
 * Private Methods:
 *        none
 * 
 */
class Sword: public Weapon{
  public:
  Sword(){
    name = "Sword";     //type of weapon
    vector<string> diceroll = {"1.d.12", "2.d.6", "3.d.4"};   //the type of die that is rolled
    damage = randomChoice(diceroll);        //the damage taken by the character
    die = new Dice(damage);
  }
};

/**
 * Magic
 * 
 * Description:
 *      Sets up our default code and settings for magic whcih are used by wizards
 * 
 * Public Methods:
 *                    magic()
 *               
 * Private Methods:
 *        none
 * 
 */
class Magic: public Weapon{
  public:
  Magic(){
    name = "Magic";
    vector<string> diceroll = {"1.d.20", "2.d.10", "3.d.6", "5.d.4"};
    damage = randomChoice(diceroll);
    die = new Dice(damage);
  }
};

/**
 * Bow
 * 
 * Description:
 *      Sets up our default code and settings for bow whcih are used by archers
 * 
 * Public Methods:
 *                    Bow()
 *               
 * Private Methods:
 *        none
 * 
 */
class Bow: public Weapon{
public:
  Bow(){
    name = "Bow";
    vector<string> diceroll = {"1.d.8", "2.d.4", "1.d.10"};
    damage = randomChoice(diceroll);
    die = new Dice(damage);
  }
};

/**
 * Axe
 * 
 * Description:
 *      Sets up our default code and settings for axe whcih are used by Dragonborns
 * 
 * Public Methods:
 *                    Axe()
 *               
 * Private Methods:
 *        none
 * 
 */
class Axe: public Weapon{
public:
    Axe(){
    name = "Axe";
    vector<string> diceroll = {"1.d.20","2.d.12"};
    damage = randomChoice(diceroll);
    die = new Dice(damage);
  }
};