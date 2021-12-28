#include <iostream>
#include <string>
//#include "md5.h"
#include <ctime>

using namespace std;

#include "Block.h"

class Transaction{
	
	private:
		double amount;
		string originator;
		string borrower;
		
	public:
		
		Transaction(double a, string o, string b){
			amount = a;
			originator = o;
			borrower = b;
		}
		
		// destructor - calls when freeing the memory with delete
		~Transaction(){
			cout << "Transaction closed gracefully." << endl;
		}
		
		double getTransactionAmount();
		
		void setAmount(double amount)
		{
			this->amount = amount;
		}
		
};

double Transaction :: getTransactionAmount()
{
	return Transaction :: amount;
}

int main()
{
	//	dynamic object creation in heap
	Transaction *PTrnsction = new Transaction(100.00, "sol", "eth");
	
	cout << PTrnsction->getTransactionAmount() << endl;
	Block transactionBlock;
	transactionBlock.displayMyHash();
	
	delete PTrnsction;
	return 0;
}
