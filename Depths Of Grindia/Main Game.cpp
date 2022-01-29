//parts BATTLE, LEVELING, FIGHTING stuff - glen 
//Main loop, inventory, item system - Daylen Rickert
//

//who did what^^^^^^^


#include <iostream>
#include <string>
#include <ctime>
#include "Save_Load.h"
#include "rat.h"
#include "sheild.h" 

//Default Values
using namespace std;
int stepsTaken = 0;
int stepsRequired = 0;
int playerLevel = 1;//can we have the player stuff if we load things? does global overide local? 
int playerEXP = 0; 
int playerGold = 10;
int playerAttack = 1;
int playDefense = 1;
int invArray[20]{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//std::vector<type> invArray(size);
int PlayerHealth = 10;
int MaxHealth = 10;
string weapon = "Dagger";
int weaponDamage = 0;

void printInv() {
	cout << "\nPrinting inventory: ";
	int counter = 0;
	while (counter != 20) {
		cout << " " << invArray[counter] << " ";
		counter++;
	}
}


//Checks if the item is in inventory
bool checkItem(int No) {
	int counter = 0;
	int items = 0;
	while (counter != 20) {
		if (invArray[counter] == No) {
			items++;
		}
		counter++;
	}
	if (items >= 1) {
		return true;
	}
	else {
		return false;
	}
}

//Removes item from inventory
void removeItem(int itemToRemove) {
	int counter = 0;
	while (counter != 20) {
		if (invArray[counter] == itemToRemove) {
			invArray[counter] = 0;
			break;
		}
		counter++;
	}
}

//Adds item from inventory
void addItem(int itemToAdd) {
	int counter = 0;
	while (counter != 20) {
		if (invArray[counter] == 0 || invArray[counter] == NULL) {
			//debug
			cout << "\nAdded item" << endl;
			//
			invArray[counter] = itemToAdd;
			break;
		}
		counter++;
		cout << "\nLoop" << endl;
	}
}

//uses items both in overworld and in battle
void useItem(int item, int Section) {
	if (checkItem(item) == true) {
		//If check item passes
		if (item == 1) {
			PlayerHealth = PlayerHealth + 5;
			if (PlayerHealth >= MaxHealth) {
				PlayerHealth = MaxHealth;
			}
			cout << "\nYour health was restored by 5!";
		}
		if (item == 2) {
			if (Section == 1) {
				cout << "You threw the bomb..." << endl;
				cout << "KABOOM!" << endl;
				cout << "Nothing happened." << endl;
			}
			else {
				cout << "You threw the bomb..." << endl;
				cout << "KABOOM!" << endl;
				//damage the enemy
				cout << "You did 20 damage!" << endl;
			}
		}
		removeItem(item);
	}
	else {
		cout << "\nThe item you typed is not in your inventory" << endl;
	}
}

string getItemName(int item) {
	//Function that grabs item names. Input item number, returns name in string
	if (item == 1) {
		return "Potion";
	}
	else if (item == 2) {
		return "Bomb";
	}
	else if (item == 3) {
		return "Big Bomb";
	}
	else if (item == 4) {
		return "Clear Potion";
	}
	else {
		return "INVALID ITEM ID";
		cerr << " >>ERROR! WRONG ITEM ID CALLED!<< ";
	}
}

string getWeaponName(int item) {
	//Function that grabs weapon names. Input item number, returns name in string
	if (item == 1) {
		return "Short Sword";
	}
	else if (item == 2) {
		return "Broad Sword";
	}
	else if (item == 3) {
		return "Big Bomb";
	}
	else if (item == 4) {
		return "knight's sword";
	}
	else {
		return "INVALID WEAPON ID";
		cerr << "ERROR! WRONG WEAPON ID CALLED!";
	}
}

int getWeaponStats(int item) {
	if (item == 1) {
		return 2;
	}
	else if (item == 2) {
		return 4;
	}
	else if (item == 3) {
		return 8;
	}
	else if (item == 4) {
		return 16;
	}
	else {
		return 0;
		cerr << "ERROR! WRONG WEAPON ID CALLED!";
	}
}

void listInventory() {
	int counter = 0;
	while (counter != 20) {
		if (invArray[counter] != 0) {
			cout << "\n[" << invArray[counter] << "] " << getItemName(invArray[counter]) << endl;
		}
		else {
			break;
		}
		counter++;
	}
}

string getChoice() {
	string choice;
	cout << "\nWhat would you like to do?\n>> ";
	cin >> choice;
	return choice;
}

string getChoiceYN() {
	string choice;
	cout << "\n(Y/N)>> ";
	cin >> choice;
	return choice;
}


int main() {
	//making monster name
	//Monster *rat = new Monster();
	//Monster *goblin = new Monster(); //this monster and below are for level 5 and up
	//Monster *thief = new Monster(); //give thief extra gold
	//Monster *dragon = new Monster(); //for high level


	//definde the monsters up here
	/*rat* seven = new rat;// seven since level seven rat
	seven->setYell((char*)"SKRRRRRRRRRRRT");
	seven->setLevel(7);
	seven->setHealth(3);
	seven->setDamage(2);
	seven->setExp(5);
	seven->setGold(1);
	*/
	bool inBattle = true; //for fight
	bool turn = true; //this is for the turn method

	
	
	

	
	

	//Not currently using the save and load system

	//intro
	string Intro = "Depths of Grindia 2.\nDeveloped by Daylen Rickert, Duc Nyugen and Glenville Pecor.";
	cout << Intro << endl;
	int Section = 0;

	while (Section != 9) {
		if (Section == 0) {
			
			cout << "\n\nWhat would you like to do?" << endl;
			//Choises
			cout <<
				"S Start Game"
				<< "\nC Contine Game"
				<< "\nQ Quit"
				<< "\n>> ";
			string choice;
			getline(cin, choice);
			if (choice == "s") {
				cout << "Starting new game..." << endl;
				//This is where the game sets default variables and DOES not access save file.

				//Asking to skip intro text
				cout << "Would you like to skip the intro text? (Y/N)"<< "\n>> ";
				getline(cin, choice);
				if (choice == "n") {
					cout << "\nYou've awoken in a dark and ominous looking cave that seems to go straight forever.\n";
					cout << "The entrance behind you seems to have collapsed recently.\n";
					cout << "You're not sure how or why you ended up here...\n";
					cout << "or even who you are.\n";
					cout << "You're armed with a rather stubby dagger.\n";
					cout << "Search the caves for another exit.\n";
					cout << "Oh, and watch out for the monsters.\n";
					Section = 1;
				}
				else {
					cout << "Alright! Let's get right into it!" << endl;
					Section = 1;
				}
			}
			else if (choice == "c") {//choice 
				cout << "Currently working on this feature..." << endl;
				
				//This is where you'd check to see if the save file exists then load save file.
			}
			else if (choice == "debug") {//helps to show stuff works and that all the functions will adjust when needed
				cout << "\nEntered debug mode." << endl;
				playerLevel = 100; 
				PlayerHealth = 100000; 
				playerAttack = 2; 
				//debug choices
				cout <<
					"PI Print Inventory"
					<< "\nB Back"
					<< "\nPII Print Inventory Item"
					<< "\nPW Print Weapon"
					<< "\nCI Check Item in inventory"
					<< "\nUI Use Item in inventory"
					<< "\nAI Add Item in inventory"
					<< "\n>> ";
					getline(cin, choice);
					if (choice == "pi") {
						printInv();
						cout << "\n";
					}
					if (choice == "pii") {
						cout << "\nTesting get inventory item function. \nPlease type an item number.\n>> ";
						int number;
						cin >> number;
						cout << getItemName(number);
					}
					if (choice == "pw") {
						cout << "\nTesting get weapon function. \nPlease type a weapon number.\n>> ";
						int number;
						cin >> number;
						cout << getWeaponName(number);
					}
					if (choice == "ci") {
						cout << "\nTesting item check. \nPlease type an item to check.\n>> ";
						int number;
						cin >> number;
						if (checkItem(number) == true) {
							cout << "\nThe item is there" << endl;
						}
						else {
							cout << "\nThe item is not there" << endl;
						}
					}
					if (choice == "ui") {
						cout << "\nTesting use item. \nPlease type an item to use.\n>> ";
						int number;
						cin >> number;
						useItem(number, 1);
					}
					if (choice == "ai") {
						cout << "\nTesting add item. \nPlease type an item to add.\n>> ";
						int number;
						cin >> number;
						addItem(number);
					}
			}
			else if (choice == "q") {//quits
				Section = 9;
			}
			else {
				cout << "I dunno what you said, but I hope it wasn't and insult.\n(Make sure you type only the uppercase letter next to the corresponding command in lower case)";//if user fails to type 
			}
		}
		if (Section == 1) {
			//In overworld section
			cout << "\nIn overworld section" << endl;
			cout << "A(Advance Forward)\n"
				<< "I(Inventory)\n"
				<< "S(Stats)\n"
				<< "Q(Quit)" << endl;
			string advance;
			advance = getChoice();
			if (advance == "a") {
				stepsTaken++;
				cout << "\nYou advance further in the cave..." << endl;
				srand( time(0) );
				int step = (rand() % 3) + 1;
				//this cout is for debugging.
				cout << "Random number generator: " << step << endl;
				//Advance with no encounters
				if (step == 2) {
					cout << "There doesn't seem to be any monsters around..." << endl;
				}
				//battle engages
				if (step == 3) {//

					cout << "There's something in the shadows..." << "ITS A MONSTER... What would you like to do? Y for fight and N for run." << endl;

					string answerFight; //string to hold yes or now
					cin >> answerFight;
					//lets add an item to help run away AND lets make the steps up to 5
					if (answerFight == "N" || answerFight == "n") {//if the user wants to run 
						srand(time(0));
						int chance = (rand() % 3) + 1;
						//this cout is for debugging.
						cout << "Random number generator: " << chance << endl;
						if (chance == 2) {
							cout << "\nYou got away!" << endl;
						}
						else {
							cout << "\nYou failed to run away. Prepare to fight!" << endl;
							//cout << "\n\n\n" << PlayerHealth<<" " << playerAttack;
							srand(time(0));
							int monsterChance = (rand() % 8) + 1;//need to test RAND out later, but for now this is for the future to choose which monster that is here
							if (monsterChance >= 0 && monsterChance <= 8) {//this is for how mant damage it does, in the future we will have diffrent numbers = to dif attack and who you fight
								//make 0-1 rat, 2-3, skelly, 4-5 goblin, 6-7 thief, 8 dragon
								//for now it is just everything


								//setting rat variables (can move up) 
								string ratYell = setYell();
								int ratLevel = setLevel(playerLevel);
								int ratHealth = setHealth(playerLevel);
								int ratDamage = setDamage(playerLevel);
								int ratEXP = setEXP(ratLevel);
								int ratGold = setGold(ratLevel);
								do {
									//intro to rat fight
									cout << "you are fighing a rat" << ratYell << "\nRat is @ lvl " << ratLevel << " and has " << ratHealth << "HP" << endl;
									//will ask user if they want to use items or sheild, right now we are just making him attack 100% of the time for speed. 
									cout << "What do you want to do?" << endl;
									
									cout << "\n\n1 Attack" << endl << "2 Sheild" << endl << "3 items" << endl;

									int answerFight;

									cin >> answerFight;
									if (answerFight == 1) {//chose to attack

										cout << "\n\nATTACK WITH " << playerAttack << " DAMAGE... RAT IS NOW AT ";
										int newHealth = ratHealth - playerAttack;
										//ratHealth = newHealth;
										if (newHealth < 0) {
											newHealth = 0;
										}


										cout << newHealth << " HP" << endl;
										ratHealth = newHealth;//to check if we die, take out this line
										PlayerHealth = PlayerHealth - ratDamage;
										cout << ratYell << "!!!! RAT ATTACKS WITH " << ratDamage << " DAMAGE!!! YOU ARE AT " << PlayerHealth << " HP" << endl;
									}
									else if (answerFight == 2) {//chose to sheild 
										cout << "\n You took out your sheild!" << endl; 
										int block = sheildFunc();
										if (block >= ratDamage) {
											block = ratDamage; 
											cout << "Lucky you! Rat did no damage! You bash the rat for 1 damage!" << endl; 
											int newHealth = ratHealth - 1;
											if (newHealth < 0) {
												newHealth = 0;
											}
											PlayerHealth = PlayerHealth - ratDamage + block ;
											ratHealth = newHealth;
											cout << ratYell << "!!!! RAT ATTACKS WITH " << ratDamage << " DAMAGE!!! BUT YOU HAD A SHEILD!!! YOU ARE AT " << PlayerHealth << " HP" << endl;
										}
										else {
											cout << "you blocked some rat damage! You bash the rat for 1 damage!" << endl;
											int newHealth = ratHealth - ratDamage + block;
											if (newHealth < 0) {//this is here so there will never be a negative health 
												newHealth = 0;
											}
											cout<<"Rat is at "<< newHealth << " HP" << endl;
											PlayerHealth = PlayerHealth - ratDamage + block;
											ratHealth = newHealth;
											cout << ratYell << "!!!! RAT ATTACKS WITH " << ratDamage << " DAMAGE!!! BUT YOU HAD A SHEILD!!! YOU ARE AT " << PlayerHealth << " HP" << endl;
										}
									}
									if (ratHealth <= 0) {// if the rat is dead
										cout << "CONGRATS ON KILLING THE RAT..." << endl;//will add things like drops, EXP, ect...
										cout << "YOU GET " << ratEXP << " EXP AND " << ratGold << " GOLD";

										playerEXP = playerEXP + ratEXP;// will make a function to make if EXP = set number, to level up
										playerGold = playerGold + ratGold;

										cout << "YOU HAVE| Gold: " << playerGold << " | EXP: " << playerEXP << endl;//will make more stats here 


										inBattle = false;
									}
									else {
										//idk what to put here??? 
										//PlayerHealth = PlayerHealth - ratDamage;

									}
									if (PlayerHealth <= 0) { //if player is dead
										inBattle = false;//takes you out of battle
									}
								} while (inBattle);




							}
							else {//make else if for later
								cout << "how";//this is for other monsters, will set up later
							}


						}
					}//
					else {//Y option to fight
						
							cout << "\nYou did not type N SO Prepare to fight!" << endl;
							//cout << "\n\n\n" << PlayerHealth<<" " << playerAttack;
							srand(time(0));
							int monsterChance = (rand() % 8) + 1;
							if (monsterChance >= 0 && monsterChance <= 8) {//this is for how mant damage it does, in the future we will have diffrent numbers = to dif attack and who you fight
																		   //for now it is just everything
								string ratYell = setYell();
								int ratLevel = setLevel(playerLevel);
								int ratHealth = setHealth(playerLevel);
								int ratDamage = setDamage(playerLevel);
								int ratEXP = setEXP(ratLevel);
								int ratGold = setGold(ratLevel);
								//will move up ^^^^
								do {
									cout << "you are fighing a rat" << ratYell << "\nRat is @ lvl " << ratLevel << " and has " << ratHealth << "HP" << endl;
									//will ask user if they want to use items or sheild, right now we are just making him attack 100% of the time for speed. 
									cout << "What do you want to do?" << endl;

									cout << "\n\n1 Attack" << endl << "2 Sheild" << endl << "3 items" << endl;

									int answerFight;

									cin >> answerFight;
									if (answerFight == 1) {

										cout << "\n\nATTACK WITH " << playerAttack << " DAMAGE... RAT IS NOW AT ";
										int newHealth = ratHealth - playerAttack;
										//ratHealth = newHealth;
										if (newHealth < 0) {
											newHealth = 0;
										}


										cout << newHealth << " HP" << endl;
										ratHealth = newHealth;//to check if we die, take out this line
										PlayerHealth = PlayerHealth - ratDamage;
										cout << ratYell << "!!!! RAT ATTACKS WITH " << ratDamage << " DAMAGE!!! YOU ARE AT " << PlayerHealth << " HP" << endl;
									}
									else if (answerFight == 2) {//sheild 
										cout << "\n You took out your sheild!" << endl;
										int block = sheildFunc();
										if (block >= ratDamage) {//if sheild cancels 
											block = ratDamage;
											cout << "Lucky you! Rat did no damage! You bash the rat for 1 damage!" << endl;
											int newHealth = ratHealth - 1;
											if (newHealth < 0) {
												newHealth = 0;
											}
											PlayerHealth = PlayerHealth - ratDamage + block;
											ratHealth = newHealth;
											cout << ratYell << "!!!! RAT ATTACKS WITH " << ratDamage << " DAMAGE!!! BUT YOU HAD A SHEILD!!! YOU ARE AT " << PlayerHealth << " HP" << endl;
										}
										else { // doesnt block all
											cout << "you blocked some rat damage! You bash the rat for 1 damage!" << endl;
											int newHealth = ratHealth - ratDamage + block;
											if (newHealth < 0) {
												newHealth = 0;
											}
											cout << "Rat is at " << newHealth << " HP" << endl;
											PlayerHealth = PlayerHealth - ratDamage + block;
											ratHealth = newHealth;
											cout << ratYell << "!!!! RAT ATTACKS WITH " << ratDamage << " DAMAGE!!! BUT YOU HAD A SHEILD!!! YOU ARE AT " << PlayerHealth << " HP" << endl;
										}
									}
									if (ratHealth <= 0) {
										cout << "CONGRATS ON KILLING THE RAT..." << endl;//will add things like drops, EXP, ect...
										cout << "YOU GET " << ratEXP << " EXP AND " << ratGold << " GOLD";

										playerEXP = playerEXP + ratEXP;// will make a function to make if EXP = set number, to level up
										playerGold = playerGold + ratGold;

										cout << "YOU HAVE| Gold: " << playerGold << " | EXP: " << playerEXP << endl;//will make more stats here 


										inBattle = false;
									}
									else {
										//idk ?? delete 
										//PlayerHealth = PlayerHealth - ratDamage;

									}
									if (PlayerHealth <= 0) {
										inBattle = false;
									}
								} while (inBattle);




							}
							else {
								cout << "how";//this is for other monsters, will set up later
							}


						


						if (PlayerHealth <= 0) {
							cout << "YOU DIED GG! TYPE GG TO END" << endl;
							string gg;
							cin >> gg;
							break;
						}




					}
				}//




				//found treasure
				if (step == 1) {
					cout << "There's a treasure chest!" << endl;
					int treasure = (rand() % 100) + 1;
					if (treasure < 81) {
						int item = (rand() % 3) + 1;
						cout << "It had a " << getItemName(item) << "!\nWill you take the " << getItemName(item) << "?\n(Y/N)" << endl;
						if (getChoiceYN() == "y") {
						//Add item to inventory
							cout << "You took the " << getItemName(item) << "!" << endl;//add stuff to array
							addItem(item);
						}
						else {
							cout << "You left the " << getItemName(item) << "..." << endl;
						}
					}
					else {
						cout << "It had a weapon!" << endl;
						int item = (rand() % 3) + 1;
						cout << "It had a " << getWeaponName(item) << "!\nWill you take the " << getWeaponName(item) << "?\n(Y/N)" << endl;
						if (getChoiceYN() == "y") {
							//Add item to inventory
							cout << "You took the " << getWeaponName(item) << "!" << endl;
							weapon = getWeaponName(item);
							weaponDamage = getWeaponStats(item);
						}
						else {
							cout << "You left the " << getWeaponName(item) << "..." << endl;
						}
					}
				}
				cout << "\nSteps taken: " << stepsTaken << endl;
			}
			else if (advance == "i") {
				//check invitory
				listInventory();
				cout << "Would you like to use an item?" << endl;
				if (getChoiceYN() == "y") {
					cout << "\nWhich item would you like to use? (TYPE THE NUMBER BESIDE THE NAME OF THE ITEM)" << endl;
					int useitem;
					cin >> useitem;
					useItem(useitem, 1);
				}
			}
			else if (advance == "s") {
				//add stats
			}

			else if (advance == "q") {
				//add would you like to save feature
				cout << "BYE" << endl;
				cout << "Are you sure you want to exit? (Y/N)";
				if (getChoice() == "y") {
					break;
				}
				else {
					Section = 0;
				}
			}
		}
	}
	return 1;



	

}