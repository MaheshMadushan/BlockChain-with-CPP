#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

using namesapce std;

class Hash {
	protected:
		string *data;
		string *hash;
		
	public:
		Hash();
		Hash(string *data);
		
		void addData(string *data);
		string getHash();
};

#endif // HASH_H
