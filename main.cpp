#include <iostream>
#include <ctime>
#include <Transaction.h>
// #include <stdio.h>
using namespace std;

#include "Block.h"

// for debugging of new (this is overloaded new) (logger for new)
#ifdef _DEBUG /* only build with debug */
void* operator new(size_t size, const char* file, int line){
	std::string fullpath = file;
	std::string filename = fullpath.substr(fullpath.find_last_of("\//"));
	printf("new F:%s L:%d \n",filename.c_str(), line);
	return malloc(size);
}
#define new new(__FILE__,__LINE__)
#endif

int main()
{
	//	Bad allocation problem resolved
	try
	{
		Transaction *PTrnsction = new Transaction(100.00, "sol", "eth");
		cout << PTrnsction->getTransactionAmount() << endl;
		Block transactionBlock;
		transactionBlock.displayMyHash();
		delete PTrnsction;
		return 0;
	}
	catch (const bad_alloc &e)
	{
		cerr << e.what() << '\n';
	}
}
