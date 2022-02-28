#include "Transaction.h"


#include "trap.h"
// class for transaction template

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
    BLOCKCHAIN_ASSERT();
    this->amount = amount;
}

double Transaction ::getTransactionAmount()
{
    return Transaction :: amount;
}
