#include "md5.h"
#include <string>
#include <iostream>
#include "clib/filters.h"

using namespace std;


#include "clib/hex.h"
#include "clib/files.h"

// The HexEncoder encodes bytes into base 16 encoded data. The partner decoder is a HexDecoder.
// A FileSink allows you to write data to a file using a BufferedTransformation
// BufferedTransformation is the basic unit of data flow in Crypto++. 
// An object which derives from BufferedTransformation can participate in Pipelining. 
// Pipelining is a paradigm in Crypto++ which allows data to flow from a Source to a Sink. 
// Each filter in the pipeline transforms the data in some way in the in route to the Sink, 
// and BufferedTransformation provides the interface across objects.
HexEncoder encoder(new FileSink(std::cout));

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
	std::cout << "Digest: " ;
	StringSource(data_digest, true, new Redirector(encoder));
	std::cout << std::endl;
}