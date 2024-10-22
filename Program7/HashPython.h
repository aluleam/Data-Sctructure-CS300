#ifndef HASHPYTHON_H
#define HASHPYTHON_H
#include <string>
using namespace std;


const int TABLE_SIZE = 67;

class HashPython 
{
private:
    struct TableElem 
    {
        string element;
        int count;
    };

    TableElem hashTable[TABLE_SIZE];

    int hashFunction(const string& key) const;
    int probe(int index) const;
    void insert(const string& keyword);

public:
    HashPython();
    bool search(const string& keyword);
    void clear();
    void print() const;
};

#endif

