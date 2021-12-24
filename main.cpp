#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Block
{
	private:
//		static long long index = 0;
		string *hash;
		string *previous_hash;
		
		// current date/time based on current system - should change
		time_t now;
		
	public :
		
		// for implementation purposes
		Block(){
//			index++;
			this->now = time(0);
		}
		
		Block(string previous_hash)
		{
			// allcate mem dynamically to hash n previous_hash
			hash = new string;
			previous_hash = new string;
//			index++;
			this->now = time(0);
			*previous_hash = previous_hash;
			cout << "block " << index << " created" << endl;
			// TODO : calculate hash of this block
		}
		
		void displayMyHash()
		{
			cout << hash << endl;
		}
};

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
