#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "Block.h"
#include "Hash.h"
#include "md5.h"

// TODO : create genesis block
// TODO : hash a block
// TODO : create genesis block
// TODO : data structure to keep blocks (prefer deque for now)
// TODO : create block

using std::string;
using std::deque;

class Blockchain
{
private:
    deque<Block> blocks;
    Block createGenisisBlock();
    Hash *md5Hash;

public:
    // add functinality to dynamic changing of hash function at runtime (prefer factory pattern or find better pattern to implement the function)
    Blockchain(){
        Block gensisBlock = createGenisisBlock();
        blocks.push_back(gensisBlock);
    }

    string 
    ~Blockchain();


};


#endif // BLOCKCHAIN_H