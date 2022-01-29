/*
#include "Save_Load.h"
#include "Tester.cpp"
#include <iostream>
#include <string>
#include <fstream>//file stream
#include <cstdlib>
#include <iomanip>
using namespace std;

int saveLoad() {
	SaveLoad SaveSystem;
	string shit = "name test";
	SaveSystem.PrintName();
	SaveSystem.SetName(shit);
	SaveSystem.PrintName();	
	cout << endl;
	cout << "Testing save name: ";
	int SaveHealth;
	int SaveLevel;;
	int SaveDamage;
	int SaveExp;
	int SaveMaxHP;
	string SaveName;
	ifstream InSaveFile{ "SaveFile.txt", ios::in };
	while (InSaveFile >> SaveHealth >> SaveLevel >> SaveDamage >> SaveExp >> SaveMaxHP >> SaveName) {
		InputVariables(SaveHealth, SaveLevel, SaveDamage, SaveExp, SaveMaxHP, SaveName);
	}// loading

	ofstream myFile;
	myFile.open("SaveFile.txt");
	myFile << "testing";
	myFile.close();


	return 0;
}

	/*bool CheckSave() {
		//Opening file
		//ofstream InSaveFile{ "SaveFile.txt", ios::in };
		//Checking if save file exists
		if (!InSaveFile) {
			return false;
		}
		else {
			return true;
		}
	}         add star here /

	bool PrintCheckSave() {
		if (CheckSave() == true) {

		}
		else {
			cerr << "Failed. Make sure the disc is not in read only mode.";
		}
		return CheckSave();
	}


void InputVariables(int SaveHealth, int SaveLevel, int SaveDamage, int SaveExp, int SaveMaxHP, string SaveName) {
	cout << SaveHealth << setw(2) << SaveLevel << setw(2) << SaveDamage << setw(2) << SaveExp << setw(2) << SaveMaxHP << setw(6) << SaveName;
 }

void Load() {
}

void Save() {

}

void PrintName() {
}*/