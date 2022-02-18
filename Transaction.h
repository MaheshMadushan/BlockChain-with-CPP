#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Transaction
{

private:
	double amount;
	string originator;
	string borrower;

public:
	Transaction(double a, string o, string b);

	// destructor - calls when freeing the memory with delete
	~Transaction();
	
	double getTransactionAmount();

	void setAmount(double amount);
};

#endif // TRANSACTION_H