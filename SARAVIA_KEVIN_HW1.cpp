#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	int classA[10], classB[10], classInUse[10], sortedClass[10];   
	int selectionNum, i, studentIndex, average = 0, exit = 0, maxVal = 0, index = 0;
	char inUse(65);
	srand(time(0));
	const int size = 10;											//instantiate variables

	for (i = 0; i < size; i++) {   
		classA[i] = rand() % 101;
		classB[i] = rand() % 101;									//input randomn grades into the classes
		classInUse[i] = classA[i];									//input class A's grades into the class in use
	}

	do {															//do: output menu and ask for input
		cout << 
			"Class in use is Class " << inUse << ". \n" <<
			"1. Print Class Grades \n" <<
			"2. Select A Student \n" <<
			"3. Calculate Average \n" <<
			"4. Switch Class \n" <<
			"5. Sort \n" <<
			"0. Exit \n" <<
			"Enter your selection number: ";						//print menu
		cin >> selectionNum;										//ask for selection number

		switch (selectionNum) {										//make menu for selection choices
			case 1:{												//if you pick choice 1:
				for (i = 0; i < size; i++)							//go through class
					cout << "Student " << i + 1 << " | Grade " 
					<< classInUse[i] << endl;						//print grades
					break;
			}
			case 2: {												//if you pick choice 2:
				cout << "Enter the student number, between 1 and 10, " 
					<< "that you would like the grade for: ";
				cin >> studentIndex;								//ask for student index
				if (studentIndex < 1 || studentIndex > 10)			//if you pick out of index:
					cout << "ERROR - The Student Index number you entered is invalid. \n"; //print error
				else                                                //else:
					cout << "Student " << studentIndex <<			//print student's grade
						" has a grade of " << classInUse[studentIndex - 1] << endl;
				break;
			}
			case 3: {												//if you pick choice 3:
				for (i = 0; i < size; i++)							//add up grades in class in use
					average += classInUse[i];
				average /= size;									//divide by number of students
				cout << "Class " << inUse << " has an average of " << average << endl; //print average
				average = 0;										//make average 0 again
				break;
			}
			case 4: {												//if you pick choice 4:
				if (inUse == 65) {									//if class A is in use:
					inUse = 66;										//make char variable B
					for (i = 0; i < size; i++)						//go through class in use
						classInUse[i] = classB[i];					//make class B class in use
				}
				else {												//else if class B is in use:
					inUse = 65;
					for (i = 0; i < size; i++)
						classInUse[i] = classA[i];					//make class A class in use
				}
				break;
			}
				/*case 5: {
					while (index < size) {
						if (maxVal < classInUse[index]) {

						}
					}
				}
						*/
			case 0: {												//if you pick choice 0:
				exit++;												//exit do while loop
				break;
			}
			default:												//if you pick an invalid choice:
				cout << "ERROR - The Selection Number you entered is invalid. \n"; //print error
		}
	} while (exit == 0);											//while choice 0 isn't picked

	cin.ignore();
	cin.get();
	return 0;
}