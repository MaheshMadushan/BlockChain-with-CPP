#include "Block.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// for implementation purposes
Block :: Block(){
	index++;
	time_stamp = time(0);
	cout << "block " << index << " created " << time_stamp << endl;
}

// constructor
Block :: Block(string i_previous_hash)
{
	// allocate mem dynamically to hash n previous_hash
	hash = new string;
	previous_hash = new string;
	time_stamp = time(0);
	
	// count of the block	
	index++;
	*previous_hash = i_previous_hash;
	cout << "block " << index << " created " << time_stamp << endl;
	// TODO : calculate hash of this block
}

// destructor
Block :: ~Block(){
	delete hash;
	delete previous_hash;
}

void Block :: displayMyHash()
{
	cout <<  this->hash << endl;
}

// initializing static member in blockchain
unsigned long long Block::index = 0;
