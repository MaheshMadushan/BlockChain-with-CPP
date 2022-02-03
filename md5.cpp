#include "md5.h"
#include <string>
#include <iostream>

#include "clib/cryptlib.h"
#include "clib/md5.h"

// using namespace std;

MD5::addData(std::string* data){
	this->data = data;
};

MD5::Hash(std::string* data){
	this->data = data;
};

MD5::Hash(){
};

MD5::setData(){
	
}
