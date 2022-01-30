#ifndef MD5_H
#define MD5_H

#include <iostream>
#include <string>
#include "Hash.h"

class MD5 : public Hash
{
	MD5() : Hash();
	MD5(string *data) : Hash(*data);
}; 

#endif // MD5_H
