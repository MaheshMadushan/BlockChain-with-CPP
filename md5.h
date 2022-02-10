#ifndef MD5_H
#define MD5_H

#include <iostream>
#include <string>
#include "Hash.h"


using namespace std;

class MD5 : public Hash
{
	MD5() : Hash(){};
	MD5(string *data) : Hash(data){};
	void addData(string* data);
	void MD5::setData(string* data);
}; 

#endif // MD5_H
