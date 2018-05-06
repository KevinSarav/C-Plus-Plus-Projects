#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream file("advice.txt");
	string line, inp;
	
	cout << "PROGRAMMING ADVICE: \n";

	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, line);
			cout << line;
			if (!file.eof())
				cout << endl;
		}

		file.close();
		file.open("advice.txt", ios::trunc | ios::out);
		do {
			cout << "Enter your programming advice and enter a blank line to quit: ";
			getline(cin, inp);
			if(inp.length() > 0)
				file << inp << endl;
		} while (inp.length() > 0);
	}

	file.close();
	cin.get();
	cin.ignore();
}