#include<iostream>
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

}
int main() {
	return 0;
}