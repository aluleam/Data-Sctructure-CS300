
#include "HashPython.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Constructor for the HashPython class
HashPython::HashPython() 
{
    string word;
    
    clear(); // Reset the hash table
    ifstream file;
    file.open("/Users/makingaberto/Desktop/Data Stuctures/Program7/Program7/keywords.txt");
    
    if (!file)
    {
       cout<< "Unable to open the file" <<endl;
        return;
    }

    while (file >> word) 
    {
        insert(word); // Insert each word into the hash table
    }
    file.close();
}


int HashPython::hashFunction(const string& key) const
{
    int sum = 0;
    for (int i = 0; i<key.length(); i++)
    {
        sum += static_cast<int>(key[i]); // Add ASCII value of each character to sum
    }
    return sum % TABLE_SIZE; // Return sum mod TABLE_SIZE as hash value
}



int HashPython::probe(int index) const
{
    // Calculate new index using linear probing with a step size of 3
    return (index + 3) % TABLE_SIZE;
}

void HashPython::insert(const string& keyword)
{
    int index = hashFunction(keyword);  // Calculate hash index for keyword
    while (!hashTable[index].element.empty())  // Check if position is occupied
    {
        if (hashTable[index].element == keyword)
            return;  // Exit if keyword already exists in the table
        index = probe(index);  // Find next position using probing
    }
    hashTable[index].element = keyword;  // Insert keyword at found index
    hashTable[index].count = 0; // Initialize count to 0
}

bool HashPython::search(const string& keyword)
{
    int index = hashFunction(keyword);
    int start_index = index;
    do
    {
        if (hashTable[index].element == keyword)
        {
            hashTable[index].count++;  // Increment count for keyword
            return true;  // Keyword found
        }
        if (hashTable[index].element.empty())
            return false;  // Stop search if empty slot found
        index = probe(index);  // Move to next index using probing
        
    } while (index != start_index);  // Continue unless we loop back to start
    
    return false;  // Keyword not found
}


void HashPython::clear() {
    // Loop through each slot of the hash table
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        hashTable[i].count = 0;  // Reset count to 0 for all elements
    }
}

void HashPython::print() const
{
    cout << "\nHash Table Contents:\n";
    cout << "---------------------------------------" << endl;
    cout << left << setw(9) << "Index" << "|" << setw(19) << " Keyword" << "|" << " Count" <<"  |" << endl;
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        if (!hashTable[i].element.empty())
        {
            cout << left << setw(9) << i << "|"
                 << setw(19) << hashTable[i].element << "|"
                 << right << setw(6) << hashTable[i].count << "  |"<<endl;
        }
    }
     cout << "---------------------------------------" << endl;
}
