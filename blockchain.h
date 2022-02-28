#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "Block.h"
#include "Hash.h"
#include "md5.h"

// TODO : create genesis block
// TODO : hash a block
// TODO : create genesis block
// TODO : data structure to keep blocks (prefer hash table for now)
// TODO : create block

using std::string;
using std::deque;
class Blockchain
{
private:
    deque<Block> blocks;
    Block createGenisisBlock();
public:
    Blockchain(){
        Block gensisBlock = createGenisisBlock();
        blocks.push_back(gensisBlock);
    }
     
    ~Blockchain();
};

Blockchain::Blockchain(/* args */)
{
}

Blockchain::~Blockchain()
{
}



#endif // BLOCKCHAIN_H