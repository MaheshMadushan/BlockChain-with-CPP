#include <iostream>
#include <string>
#include "md5.h"
#include <ctime>

using namespace std;

class Block
{
	private:
		
		string *hash;
		string *previous_hash;
		
		// current date/time based on current system - should change to checking with www
		time_t time_stamp;
		
	public :
		static unsigned long long index;
		// for implementation purposes
		Block(){
			index++;
			this->time_stamp = time(0);
			cout << "block " << index << " created " << time_stamp << endl;
		}
		
		// constructor
		Block(string i_previous_hash)
		{
			// allcate mem dynamically to hash n previous_hash
			hash = new string;
			previous_hash = new string;
			this->time_stamp = time(0);
			index++;
			*previous_hash = i_previous_hash;
			cout << "block " << index << " created " << time_stamp << endl;
			// TODO : calculate hash of this block
		}
		
		// destracutor
		~Block(){
			delete hash;
			delete previous_hash;
			delete time_stamp;
		}
		
		void displayMyHash()
		{
			cout << hash << endl;
		}
};

// initializing static member in blockchain
unsigned long long Block::index = 0;

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
