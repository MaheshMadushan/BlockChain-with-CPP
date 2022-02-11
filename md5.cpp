#include "md5.h"
#include <string>
#include <iostream>

using namespace std;

void MD5::addData(string *data){
	this->data = data;
};

void MD5::setData(string *data){
	this->data = data;
}
