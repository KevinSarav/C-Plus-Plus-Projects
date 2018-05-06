#include <iostream>
using namespace std;

int main()
{
	int choice = 0;
	int inp = 0;
	int temp = 0;
	int currentSize = 0;
	int *dynArray = NULL;
	int *tempArray = NULL;
	int capacity = 2;
	dynArray = new int[capacity];
	tempArray = new int[capacity];

	do {
		cout << "1) Print Elements" << endl
			<< "2) Add Element" << endl
			<< "3) Delete Element" << endl
			<< "4) Return Size" << endl
			<< "5) Exit" << endl
			<< "Please choose from 1-5 " << endl;
		cin >> choice;
		// if choice<=0||>5 crap

		switch (choice)
		{
		case 1: {
			for (int i = 0; i < currentSize; i++)
			{
				cout << dynArray[i] << endl;
			}
			break;
		}
		case 2: {

			cout << "Please enter number " << endl;
			cin >> inp;

			if(currentSize >= capacity){													
				capacity *= 2;						
				delete[]dynArray;					
				dynArray = new int[capacity];		
				for (int i = 0; i < currentSize; i++)	
				{
					*(dynArray + i) = tempArray[i];
				}
				delete[]tempArray;					
				tempArray = new int[capacity];
				for (int i = 0; i < currentSize; i++)
				{
					*(tempArray + i) = dynArray[i];
				}
				cout << "Array size Expanded to " << capacity << endl;
			}
			*(dynArray + currentSize) = inp;
			*(tempArray + currentSize) = inp;
			currentSize++;

			int i, key, j;
			for (int i = 1; i < currentSize; i++)
			{
				int key = dynArray[i];
				int j = i - 1;
				while (j >= 0 && dynArray[j] > key)
				{
					dynArray[j + 1] = dynArray[j];
					tempArray[j + 1] = tempArray[j];
					j = j - 1;
				}
				dynArray[j + 1] = key;
				tempArray[j + 1] = key;
			}
			break;
		}
		case 3: {
			cout << "Please enter number " << endl;
			cin >> inp;
			for (int i = 0; i < currentSize; i++) {
				if (*(dynArray + i) == inp) {
					for (int j = i; j <= currentSize; j++) {
						*(dynArray + j) = dynArray[j+1];
						*(tempArray + j) = tempArray[j+1];
					}
					if (currentSize <= (capacity / 2) + 1) {
						capacity /= 2;
						delete[]dynArray;
						dynArray = new int[capacity];
						for (int i = 0; i < currentSize; i++)
						{
							*(dynArray + i) = tempArray[i];
						}
						delete[]tempArray;
						tempArray = new int[capacity];
						for (int i = 0; i < currentSize; i++)
						{
							*(tempArray + i) = dynArray[i];
						}
						cout << "Array size Shrunk to " << capacity << endl;
					}
					currentSize--;
					break;
				}
				else if (i == currentSize - 1)
					cout << "ERROR - Your Input is not in the array." << endl;
			}
			break;
		}
		case 4: {
			cout << "Size of Array is " << capacity << " and there is " <<
				currentSize << " element inside \n";
			break;
		}
		case 5:
			break;
		default: {
			cout << "ERROR - Your Selection is not in the array." << endl;
			break;
		}
		}
	} while (choice != 5);

	cin.ignore();
	cin.get();
	return 0;
}