#pragma once
#include <iostream>
#include <string>
using namespace std;
/*

class Monster {
public:
	Monster(char* Yell, char* name, int Health, int Damage, int Gold, int Exp) : myYell{ Yell }, myName{ name }, myHealth{ Health }, myDamage{ Damage }, myGold{ Gold }, myExp{ Exp } {

	}
	Monster() {};



	void setName(char *name) { //useless class maybe???
		myName = name;
	}
	char* getName() const { return myName; }

	void setYell(char *Yell) {
		myYell = Yell;
	}
	char* getYell() const { return myYell; }

	

	void setLevel(int Level) {
		myLevel = Level;
	}
	int getLevel() const { return myLevel; }

	void setHealth(int Health) {
		int x = getLevel();
		if (x < 3) {
			myHealth = Health;
		}
		else if (x < 6) {
			myHealth = Health * 2;

		}
		else {
			myHealth = Health * 3;
		}
	}
	int getHealth() const { return myHealth; }

	void setDamage(int Damage) {
		int x = getLevel();
		if (x < 3) {
			myDamage = Damage;
		}
		else if (x < 6) {
			myDamage = Damage * 2;

		}
		else {
			myDamage = Damage * 3;
		}
	}
	int getDamage() const { return myDamage; }


	void setExp(int Exp) {
		int x = getLevel();
		if (x < 3) {
			myExp = Exp;
		}
		else if (x < 6) {
			myExp = Exp * 2;

		}
		else {
			myExp = Exp * 3;
		}
	}
	int getExp() const { return myExp; }


	void setGold(int Gold) {
		int x = getLevel();
		if (x < 3) {
			myGold = Gold;
		}
		else if (x < 6) {
			myGold = Gold * 2;

		}
		else {
			myGold = Gold * 3;
		}
	}
	int getGold() const { return myGold; }





private:
	//can change my to monster
	char *myName = (char*)"Generic monster";
	char *myYell = (char*)"Generic Scream";
	int myHealth;
	int myLevel;
	int myDamage;
	int myExp;
	//int myMaxHP; 
	int myGold;

};

class rat : public Monster {
public:
	void define() {
		cout << getYell() << ": This is a rat with: " << getHealth() << " HP, That is level" << "getLevel since it isnt working"  << endl << endl;
		//for debug
		cout<<"This Rat does DAMAGE: " << getDamage() << 
			"EXP: "<< getExp() << 
			"GOLD: "<<getGold()<<endl;
	}

	int health(int myHealth) {
		return myHealth; 

	}

	


};
*/

string setYell() {
	string ratYell = "SKRRRRRRRRRT";
		 return ratYell;
}




int setLevel(int playerLevel) {
	int level =1;
	if (playerLevel <= 3) {
		
		return level;

	}
	else if (playerLevel <= 6) {
		return level * 2;
	}
	else {
		return level * 3;
	}
}


int setHealth(int playerLevel) {
	int health = 2;
	if (playerLevel <= 3) {

		return health;

	}
	else if (playerLevel <= 6) {
		return health * 2;
	}
	else {
		return health * 3;
	}
}


int setDamage(int ratLevel) {
	int Damage = 1;
	if (ratLevel < 3) {
		return Damage;
	}
	else if (ratLevel < 6) {
		return Damage * 2;

	}
	else {
		return Damage * 3;
	}
}


int setEXP(int ratLevel) {
	int EXP = 5;
	if (ratLevel < 3) {
		return EXP;
	}
	else if (ratLevel < 6) {
		return EXP * 2;

	}
	else {
		return EXP * 3;
	}
}

int setGold(int ratLevel) {
	int gold = 5;
	if (ratLevel < 3) {
		return gold;
	}
	else if (ratLevel < 6) {
		return gold * 2;

	}
	else {
		return gold * 3;
	}
}