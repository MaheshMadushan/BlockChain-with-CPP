#include <iostream>
#include <string>

using namespace std;

class Block
{
	private:
		string hash;
		string previous_hash;
	public :
		void displayMyHash()
		{
			cout << MyHash << endl;
		}
};

class Transaction{
	
	private:
		double amount = 0.0;
		string originator;
		string borrower;
		
	public:
		
		Transaction(double a, string o, string b){
			amount = a;
			originator = o;
			borrower = b;
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
	return 0;
}
