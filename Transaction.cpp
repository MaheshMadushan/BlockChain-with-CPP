#include <Transaction.h>
#include <string>
#include <iostream>

using namespace std;

Transaction ::Transaction(double a, string o, string b)
{
    amount = a;
    originator = o;
    borrower = b;
}

// destructor - calls when freeing the memory with delete
Transaction ::~Transaction()
{
    cout << "Transaction closed gracefully." << endl;
}

void Transaction :: setAmount(double amount)
{
    this->amount = amount;
}

double Transaction ::getTransactionAmount()
{
    return Transaction ::amount;
}
