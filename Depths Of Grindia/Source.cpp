#include <iostream>
#include <string>
#include <fstream>//file stream


using namespace std;

int main() {
	string i;
	cin >> i;

	//ofstream myFile;
	ofstream myFile;
	myFile.open("testing.txt");	
	if (myFile.is_open())
	{
		myFile << i;
		myFile.close();
	}
	else cout << "Unable to open file";
	return 0;
}

