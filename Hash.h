#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

using namespace std;

class Hash {
	private:
		string *data;
		string *hash;
		
	public:
		Hash();
		Hash(string *data);
		
		void addData(string *data);
		string getHash();
		void setData(string *data);
};

#endif // HASH_H
