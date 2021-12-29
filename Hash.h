#include "clib/cryptlib.h"
#include "clib/md5.h" // from https://cryptopp.com/
#include <iostream>
#include <string>

using namesapce std;

class Hash {
	private:
		string *data;
		string *hash;
		
	public:
		Hash();
		Hash(string *data);
		
		void addData(string *data);
		string getHash();
};
