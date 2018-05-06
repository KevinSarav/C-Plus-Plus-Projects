#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream file;
	string line, inp = " ";
	file.open("advice.txt", ios::in | ios::out);

	cout << 
		"PROGRAMMING·ADVICE: \n" <<
		"Write·comments. \n" <<
		"Name·your·variables·in·ways·that·make·sense. \n"

	if (file.is_open) {
		while (!file.eof()) {
			getline(file, line);
			cout << line;
		}
		
		while (inp != "") {
			cout << "Enter·your·programming·advice·and·enter·a·blank·line·to·quit: ";
			cin >> inp;
			put(file, inp);
		}
	}

	file.close();
	cin.ignore();
	cin.get();
	return 0;
}