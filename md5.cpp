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

void MD5::getHash(){

	std::cout << "Name: " << hash.AlgorithmName() << std::endl;
    std::cout << "Digest size: " << hash.DigestSize() << std::endl;
    cout << "Block size: " << hash.BlockSize() << std::endl;

	hash.Update((const CryptoPP::byte*)&data[0], (*data).size());
	data_digest.resize(hash.DigestSize());
	hash.Final((CryptoPP::byte*)&data_digest[0]);

	std::cout << "Message: " << *data << std::endl;
	std::cout << "Digest: " << data_digest << std::endl;
	std::cout << std::endl;
}