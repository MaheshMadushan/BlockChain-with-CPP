#ifndef MD5_H
#define MD5_H

#include <iostream>
#include <string>
#include "Hash.h"

#include "clib/cryptlib.h"
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include "clib/md5.h"

using namespace CryptoPP;
class MD5 : public Hash
{
	private:
		Weak::MD5 hash;
		string data_digest;

	public:
		MD5() : Hash(){};
		MD5(string *data) : Hash(data){};
		void addData(string* data);
		void setData(string* data);
		void getHash();
}; 

#endif // MD5_H
