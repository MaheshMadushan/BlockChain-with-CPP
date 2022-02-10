#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

using namespace std;

class Hash {
	protected:
		std::string *data;
		std::string *hash;
		
	public:
		Hash();
		Hash(std::string *data){
			this->data = data;
		};
		
		void addData(std::string *data);
		std::string getHash();
		void setData(std::string *data);
};

#endif // HASH_H
