/*****************************************************************************
*
*  Author:           Allison Ricketts
*  Email:            taterrickets@gmail.com
*  Label:            P03B
*  Title:            FIGHT CLUB
*  Course:           2143 OOP
*  Semester:         Fall 2021
*
*  Description:
*       This program uses vectors and run time polymorphism to simulate a battle between D&D characters, deciding their fate by the roll of a die.
*
*  Files: main.cpp
          dice.hpp
          helpers.hpp
          Weapons.hpp
          Fights.hpp
*****************************************************************************/
#include <thread>
#include <cstdlib>
#include <cmath>
#include <random>
#include <fstream>

#include "dice.hpp"
#include "helpers.hpp"
#include "Fighters.hpp"
#include "Weapons.hpp"

using namespace std;
#pragma once

//This function randomizes the attackers and number of attackers
//it also desides new characters with hit points and weapons
void Attackers(vector<BaseFighter*>& attackers) {
    for(int i = 0; i < (30 + rand() % 5); i++) {
        BaseFighter* warrior = new Warrior();//so in our attacker vector we push warrior and warrior info
        attackers.push_back(warrior);       //back into the vector to use to fight the defenders
        BaseFighter* wizard = new Wizard();
        attackers.push_back(wizard);
        BaseFighter* archer = new Archer();
        attackers.push_back(archer);
        BaseFighter* elf = new Elf();
        attackers.push_back(elf);
        BaseFighter* dragonborn = new DragonBorn();
        attackers.push_back(dragonborn);
    }
}

//This function randomizes our defenders.
//Defenders are of 1% of the number of attackers.
void Defenders(int attackSize, vector<BaseFighter*>& defenders) {
    int size = round(attackSize * .01);
    for(int i = 0; i < size; i++) {
        BaseFighter* warrior = new Warrior();
        defenders.push_back(warrior);
        BaseFighter* wizard = new Wizard();
        defenders.push_back(wizard);
        BaseFighter* archer = new Archer();
        defenders.push_back(archer);
        BaseFighter* elf = new Elf();
        defenders.push_back(elf);
        BaseFighter* dragonborn = new DragonBorn();
        defenders.push_back(dragonborn);
    }
}

  //This function gets a fighter and establishes it as our defender
  BaseFighter* Defender(BaseFighter* attacker, vector<BaseFighter*>* defenders)  {
    for(BaseFighter* defender : *defenders) {
    if(defender->name == attacker->name) {
    return defender;
    }
    }
    return defenders->back();
} 

//THis function gets a new defender once the current defender gets too low in hp
BaseFighter* changeDefender(vector<BaseFighter*>* defenders, BaseFighter* currentFighter) {
    for(BaseFighter* defender : *defenders) {
      //if the next defender is not the same as the current defender than replace with new defender
    if(defender != currentFighter && defender->name == currentFighter->name) { 
    return defender;
    }
    }
    return currentFighter; //but if not, keep current defender
}

//This function adds hp to the defenders in the back of the vector
void medKitDefenders(vector<BaseFighter*>& defenders) {
    for(BaseFighter* defender : defenders) {
        int hp = defender->medKit();
        if(hp > 0) {
           cout << defender->name << " healed " << hp << " hp." << endl;
        }
    }
}


int main() {
    //open output file for our output
    ofstream outfile;
    outfile.open("output.txt");
    // Create a vector of attackers
    srand(time(0));
    vector<BaseFighter*> attackers;
    vector<BaseFighter*> defenders;

    // fill the attackers vector
    Attackers(attackers);
    Defenders(attackers.size(), defenders);

    BaseFighter* CurrentAttacker;
    BaseFighter* CurrentDefender;

    while(attackers.size() && defenders.size()) {
        CurrentAttacker = attackers.back(); //set first current attacker as first on list
        CurrentDefender = Defender(CurrentAttacker, &defenders); //set defender as the current attacker
        while(CurrentAttacker->alive() && CurrentDefender->alive()) { // while they are both fighter here we cout their battle

            //Slow is down and allow clear screan for effect
            this_thread::sleep_for(chrono::milliseconds(1));
            system("clear");
            //cout the current amount of attackers and defenders
            cout << "Attackers: " << attackers.size()<< endl;
            cout << "Defenders: " << defenders.size() << endl;
            //cout the type of fighter/defender
            cout <<"Attacker: " << CurrentAttacker->name << ":" << CurrentAttacker->hp << "hp" << endl;
            outfile <<"Attacker: " << CurrentAttacker->name << ":" << CurrentAttacker->hp << "hp" << endl;
            cout << "Defender: " << CurrentDefender->name << ":" <<CurrentDefender->hp << "hp" << endl << endl;
            outfile << "Defender: " << CurrentDefender->name << ":" <<CurrentDefender->hp << "hp" << endl << endl;
   
     int damage = CurrentAttacker->attack();
            CurrentDefender->takeDamage(damage);

        }
        //if the current attacker is unalive then they are moved to back of vector
        if(!CurrentAttacker->alive()) {
            attackers.pop_back();
            //couts that they have died
            cout << "Attacker " << CurrentAttacker->name << " died" << endl;
            outfile << "Attacker " << CurrentAttacker->name << " died" << endl;
        }

        //this function signifys when a defender dies
        int i = 0;
        for(BaseFighter* fighter : defenders) {
            if(fighter->hp <= 0) {
                defenders.erase(defenders.begin() + i);
                cout << "Defender " << CurrentDefender->name << " died" << endl;
                outfile << "Defender " << CurrentDefender->name << " died" << endl;
            }
            i++;
        }

    }
    //simply states who the winners are
    if(attackers.size()) {
        cout << "Attackers win";
        outfile << "Attackers win";
    }
    if(defenders.size()) {
        cout << "Defenders win";
        outfile << "Defenders win";
    }}