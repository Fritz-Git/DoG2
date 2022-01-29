#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int sheildFunc() {
	srand(time(0));
	int block = (rand() % 5) + 1;

	switch (block) {
	case 1:
		break;      
	case 2: block = block + 1;
		break;
	
	case 3:block = block + 2;
		break;
	case 4: block = block + 3;
		break;
	case 5: block = block + 4;
		break;

	}

	return block; 

}