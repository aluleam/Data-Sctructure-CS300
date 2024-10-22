#include "HashPython.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

// Function prototypes
void handleFile(const string& filename, HashPython& hashTable);
bool ValidWord(const string& word);
void userInput();

int main()
{
    userInput();  //Call the function to start the program
    return 0;
}

void userInput()
{
    HashPython hashTable;  // Create an instance of the HashPython class
    string filename;

    while (true) 
    {
        cout << "Enter filename (Q to exit): ";
        getline(cin, filename);  // Read the filename entered by the user

        if (filename == "Q" || filename == "q") {  // Check if the user wants to quit
            break;  // Exit the loop if the user wants to quit
        }

        handleFile(filename, hashTable);  // Process the file  entered by the user
    }
}

void handleFile(const string& filename, HashPython& hashTable)
{
    ifstream file;
    string word;
    int totalFound = 0;
    
    file.open(filename);  // Attempt to open the file
    if (!file)
    {
        cout << "Unable to open the file" << endl;  // Display an error message
        return;
    }

    while (file >> word)  // Read each word from the file
    {
        if (ValidWord(word))  // Check if the word is a valid Python keyword
        {
            if (hashTable.search(word))  // Check if the word is present in the hash table
            {
                totalFound++;  // Increment the count of Python keywords found
            }
        }
    }
    file.close();

    cout << "\nTotal Python keywords found: " << totalFound << endl;
    hashTable.print();  // Print the contents of the hash table
    hashTable.clear();  // Reset the hash table for the next file
}

bool ValidWord(const string& word)
{
    return isdigit(word[0]) || isalpha(word[0]);
}

