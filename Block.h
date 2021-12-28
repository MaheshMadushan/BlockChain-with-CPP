#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
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
		Block();
		
		// constructor
		Block(string i_previous_hash);
		
		// destracutor
		~Block();
		
		void displayMyHash();
};


#endif //BLOCK
