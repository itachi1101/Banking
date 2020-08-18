#include<iostream>
#include<cstring>
#include<map>
#include<fstream>
using namespace std;
class Account {
private:
	long long accountNumber;
	string firstName;
	string lastName;
	float balance;
	static long NextAccountNumber;
public:
	Account() {}
	Account(string fname, string lname, float balance);
	long getAccNo() {return accountNumber;}
	string getFirstName() {return firstName;}
	string getLastName() {return lastName;}
	float getBalance() {return balance;}

	void Deposit(float amount);
	void Withdraw(float amount);
	static void setLastAccountNumber(long accountNumber);
	static long getLastAccountNumber();
	friend ofstream & operator<<(ofstream &ofs, Account &acc);
	friend ifstream & operator>>(ifstream &ifs, Account, &acc);
	friend ofstream & operator<<(ofstream, &os, Account, &acc);

};

Account::Account(string fname, string lname, foat balance) {
	NextAccountNumber++;// why are we doing this let me see afterwards
	accountNumber = NextAccountNumber;
	firstName = fname;
	lastName = lname;
	this->balance = balance;
}
void Account::Deposit(float amount) {
	balance += amount;
}
void Account::Withdraw(float amount) {
	balance -= amount;
}

void Account::setLastAccountNumber(long accountNumber) {
	NextAccountNumber = accountNumber;
}
void Account::getLastAccountNumber() {
	return NextAccountNumber;
}


int main() {
	return 0;
}