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

	// static members to for the static variable
	static void setLastAccountNumber(long accountNumber);
	static long getLastAccountNumber();
	// these are for insertion in the file
	friend ofstream & operator<<(ofstream &ofs, Account &acc);
	friend ifstream & operator>>(ifstream &ifs, Account, &acc);




	// this is for the display of account information
	friend ostream & operator<<(ostream, &os, Account, &acc);

};


class Bank {
private:
	map<long , Account>accounts;
public:
	Bank();

}

int main() {
	return 0;
}
























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
// this stores everything in a file
ofstream & operator<<(ofstream &ofs, Account &acc) {
	ofs << acc.accountNumber << endl;
	ofs << acc.firstName << endl;
	ofs << acc.lastName << endl;
	ofs << acc.balance << endl;
	return ofs;
}
// this reads everything from the file in order of how it was save
ifstream & operator>>(ifstream &ifs, Account &acc) {
	ifs >> acc.accountNumber;
	ifs >> acc.firstName;
	ifs >> acc.lastName << endl;
	ifs >> acc.balance;
	return ifs;
}

//this operator is overloaded to display the output on the console
ostream & operator<<(ostream &os , Account &acc) {
	os << "First Name: " << acc.getFirstName() << endl;
	os << "Last Name: " << acc.getLastName() << endl;
	os << "Account Number: " << acc.getAccNo() << endl;
	os << "Balance: " << acc.getBalance() << endl;
	return os;
}
