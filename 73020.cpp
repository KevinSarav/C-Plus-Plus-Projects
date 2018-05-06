#include <iostream>
#include <string>
using namespace std;

class Month {
	int intMonth;
	string strMonth;
	
public:
	Month();
	Month(int month);
	Month(string, string, string);
	void set_monthInt(int month);
	int get_monthInt();
	string get_monthStr();
};

int main() {
	int inp, i;
	string letter1, letter2, letter3;
	string arry[12] = { "JAN", "FEB", "MAR", "APR", "MAY", 
		"JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

	cout << "Enter a month value as an integer: ";
	cin >> inp;
	while (inp < 1 || inp > 12) {
		cout << "Incorrect Month. Enter another integer.";
		cin >> inp;
	}
	Month firstObj(inp);
	firstObj.set_monthInt(inp);
	cout << "This month is: " << arry[firstObj.get_monthInt() - 1] << endl;
	firstObj.set_monthInt(inp + 1);
	if (firstObj.get_monthInt() == 13)
		firstObj.set_monthInt(1);
	cout << "The next month is: " << arry[firstObj.get_monthInt() - 1] << endl;

	cout << "Enter the first letter of the month name: ";
	cin >> letter1;
	cout << "Enter the second letter of the month name: ";
	cin >> letter2;
	cout << "Enter the third letter of the month name: ";
	cin >> letter3;
	Month secondObj(letter1, letter2, letter3);
	for (i = 0; i < 12; i++) {
		if (arry[i] == secondObj.get_monthStr()) {
			secondObj.set_monthInt(i + 1);
			break;
		}
	}
	cout << "This month number is: " << secondObj.get_monthInt() << endl;
	secondObj.set_monthInt(i + 2);
	if (secondObj.get_monthInt() == 13)
		secondObj.set_monthInt(1);
	cout << "Next month is: " << arry[secondObj.get_monthInt() - 1] << endl;

	Month thirdObj(1);
	Month();
	cout << "Using the default constructor, the month is: " << arry[thirdObj.get_monthInt() - 1] << endl;
	thirdObj.set_monthInt(1 + 1);
	cout << "The next month is: " << arry[thirdObj.get_monthInt() - 1] << endl;
	
	cin.ignore();
	cin.get();
	return 0;
}

Month::Month() {
	intMonth = 1;
}

Month::Month(int month) {
	intMonth = month;
}

Month::Month(string first, string second, string third) {
	strMonth = first + second + third;
}

void Month::set_monthInt(int inp){
	intMonth = inp;
}

int Month::get_monthInt() {
	return intMonth;
}

string Month::get_monthStr() {
	return strMonth;
}