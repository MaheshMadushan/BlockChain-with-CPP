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
		
		virtual void addData(std::string *data) = 0;
		virtual void getHash() = 0;
		virtual void setData(std::string *data) = 0;
};

#endif // HASH_H
