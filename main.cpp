#include <iostream>
#include <ctime>
#include <Transaction.h>
#include <stdio.h>
#include <memory>
using namespace std;
#include "Block.h"

// for debugging of new (this is overloaded new) (logger for new)
// overloaded new and delete for logging
#ifdef _DEBUG /* only build with debug */
void* operator new(size_t size, const char* file, int line){
	std::string fullpath = file;
	std::string filename = fullpath.substr(fullpath.find_last_of("\//"));
	printf("new F:%s L:%d \n",filename.c_str(), line);
	return malloc(size);
}
void log_delete(const char* file, int line){
	std::string fullpath = file;
	std::string filename = fullpath.substr(fullpath.find_last_of("\//"));
	printf("new F:%s L:%d \n",filename.c_str(), line);
}
void operator delete(void* p, const char* file, int line){
	free(p);
}
/* __FILE__ is a preprocessor macro that expands to full path to the current file. __FILE__ is useful when generating log statements, error messages intended for programmers, when throwing exceptions, or when writing debugging code. */
#define new new(__FILE__,__LINE__)
#define delete log_delete(__FILE__,__LINE__); delete
#endif

int main()
{
	//	Bad allocation problem resolved
	try
	{
		// use shared_ptr instead of new (it deletes when ptr no longer in use)
		Transaction *PTrnsction = new Transaction(100.00, "sol", "eth");
		std::shared_ptr<Transaction> spTransaction = std::make_shared<Transaction>(100.00, "sol", "eth");
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
