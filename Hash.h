#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

using std::string;

class Hash {
	protected:
		string *data;
		string *hash;
		
	public:
		Hash();
		Hash(string *data){
			this->data = data;
		};
		
		virtual void addData(string *data) = 0;
		virtual string getHash() = 0;
		virtual void setData(string *data) = 0;
};

#endif // HASH_H
