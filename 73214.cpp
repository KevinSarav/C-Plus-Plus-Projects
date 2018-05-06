#include <iostream>
using namespace std;

class Account {
private:
	double balance;
public:
	Account() {
		balance = 0;
	}
	Account(double initialDeposit) {
		balance = initialDeposit;
	}
	double getBalance() {
		return balance;
	}
	// returns new balance or -1 if error
	double deposit(double amount) {
		try {
			if (amount > 0)
				balance += amount;
			else
				throw amount; // Code indicating error
			cout << "$" << amount << " deposited.\n";
			return balance;
		}
		catch (double e) {
			cout << "That is not a valid deposit amount.\n";
			return balance;
		}
	}
	// returns new balance or -1 if invalid amount
	double withdraw(double amount) {
		try {
			if ((amount > balance) || (amount < 0))
				throw amount;
			else
				balance -= amount;
			cout << "$" << amount << " withdrawn.\n";
			return balance;
		}
		catch (double e) {
			cout << "That is not a valid withdraw amount.\n";
		}
	}
};

int main() {
	double inp;

	cout << "Enter amount to deposit: ";
	cin >> inp;
	Account acct(0);
	acct.deposit(inp);
	if (acct.getBalance() == 0)
		return 0;

	cout << "Enter amount to withdraw: ";
	cin >> inp;
	acct.withdraw(inp);
}