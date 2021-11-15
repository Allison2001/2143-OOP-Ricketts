#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Weapons.hpp"
#pragma once

/**
 * BaseFighter
 * 
 * Description:
 *      Sets up our default code and settings for our fighters
 * 
 * Public Methods:
 *                    BaseFighter()
            void      attack()
            void      takeDamage()
            int       alive()
            int       medKit()
            void      stats()
 *               
 * 
 * Private Methods:
 *        none
 * 
 */
class BaseFighter{
public:
  int hp;         //hit points
  int max;        //max hit points
  int health;     //new hit points
  string name;    //type of character

  Weapon* weapon;

  BaseFighter():hp{(rand()%20)+10}{}  //set up our hp for each character
  int attack(){
    int damage = weapon->use();   //damaged based on the weapon you are using
    return damage;
  }

  void attack(BaseFighter* &other){   
    int damage = weapon->use();
    other->takeDamage(damage);
  }
  
  void takeDamage(int damage){    //the amount of damage taken by character
    hp -= damage;
  }

  int alive(){      //if hp is greater than 0 they are still alive
    return hp > 0;
  }

  int medKit(){     //adding health to character
    if(hp < max){
      hp += health;
    } 
    return health;
  }

  void stats(){     //randomizing health
      hp = (rand()%5);
      max = hp;
      health = (rand() % 6);
    }
};

/**
 * Warrior
 * 
 * Description:
 *      Sets up our default code and settings for warriors
 * 
 * Public Methods:
 *                    Warrior()
 *               
 * Private Methods:
 *        none
 * 
 */
class Warrior: public BaseFighter{
  public:
    Warrior() {
      name = "Warrior";           //type of character
      Sword* sword = new Sword(); //their assigned weapon
      weapon = sword;
      stats();                    //their given stats
      }
};

/**
 * Wizard
 * 
 * Description:
 *      Sets up our default code and settings for wizards
 * 
 * Public Methods:
 *                    Wizards()
 *               
 * Private Methods:
 *        none
 * 
 */
class Wizard: public BaseFighter{
  public:
      Wizard() {
          name = "Wizard";
          Magic* magic = new Magic();
          weapon = magic;
          stats();
      }
 
};

/**
 * Archer
 * 
 * Description:
 *      Sets up our default code and settings for archer
 * 
 * Public Methods:
 *                    Archer()
 *               
 * Private Methods:
 *        none
 * 
 */
class Archer: public BaseFighter{
  public:
      Archer() {
          name = "Archer";
          Bow* bow = new Bow();
          weapon = bow;
          stats();
      }
};

/**
 * Elf
 * 
 * Description:
 *      Sets up our default code and settings for elves
 * 
 * Public Methods:
 *                    Elf()
 *               
 * Private Methods:
 *        none
 * 
 */
class Elf: public BaseFighter{
  public:
      Elf() {
          name = "Elf";
          Sword* sword = new Sword();
          weapon = sword;
          stats();
      }
};

/**
 * DragonBorn
 * 
 * Description:
 *      Sets up our default code and settings for dragonborns
 * 
 * Public Methods:
 *                    DragonBorn()
 *               
 * Private Methods:
 *        none
 * 
 */
class DragonBorn: public BaseFighter{
  public:
      DragonBorn() {
          name = "Dragonborn";
          Axe* axe = new Axe();
          weapon = axe;
          stats();
      }
};