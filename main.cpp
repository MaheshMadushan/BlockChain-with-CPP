#include <iostream>
#include <ctime>
#include <Transaction.h>

using namespace std;

#include "Block.h"


int main()
{
	//	dynamic object creation in heap
	try
	{
		Transaction *PTrnsction = new Transaction(100.00, "sol", "eth");
		cout << PTrnsction->getTransactionAmount() << endl;
		Block transactionBlock;
		transactionBlock.displayMyHash();
		delete PTrnsction;
		return 0;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << e.what() << '\n';
	}
}
