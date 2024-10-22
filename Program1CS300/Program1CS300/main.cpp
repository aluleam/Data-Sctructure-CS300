// **********************************************************************************
// **********************************************************************************
// Program:      Fishing Tournament                                                **
// Name:         Masumbuko Alulea                                                  **
// course:       CSC 300 Data Structures                                           **
// Instructor:   Paula Kurtenbach                                                  **
// Date:         26 January 2024                                                   **
// Description:  This program keeps track of fish caught in an ice fishing         **
//               tournament. It stores each fisher's name and details about        **
//               their biggest fish - its length, weight, and type (Perch,         **
//               Walleye, or Bass). The program lists these fish in order of       **
//               size adding up the length and weight. You can add new fish        **
//               to the list, see all fish of one type, show the list in order or  **
//               backwards, remove from the list and exit the program using a menu.**
// **********************************************************************************
// **********************************************************************************

#include <iostream>
#include <string>
#include "FishList.h"

using namespace std;
//prototypes
int printMenu();
void insertItem(FishList& myList);
void listSpeciesItems(FishList& myList);
void printList(FishList& myList);
void printListReverse(FishList& myList);
void deleteNode(FishList& myList);
Species getSpecies();

int main() {
    
    // Creating an instance of FishList to store the fish data
    FishList myList;
    int choice;

    do {
        choice = printMenu();

        switch (choice)
        {
            case 1:
                insertItem(myList);
                break;
            case 2:
                listSpeciesItems(myList);
                break;
            case 3:
                printList(myList);
                break;
            case 4:
                printListReverse(myList);
                break;
            case 5:
                deleteNode(myList);
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid " << endl;
        }
    } while (choice != 6);  // Continue until the user chooses 6 to exit

    return 0;
}


// Function to display the menu and get the user's choice
int printMenu() {
    int choice;

    // Loop until a valid choice is made
    do
    {
        // Printing the menu options
        cout << "ICE FISHING TOURNAMENT MENU" << endl;
        cout << string(27, '-') << endl;  // Printing a separator line
        cout << "1. Insert an item" << endl;
        cout << "2. List items for a species" << endl;
        cout << "3. Print List" << endl;
        cout << "4. Print List in Reverse" << endl;
        cout << "5. Remove from the list" << endl;
        cout << "6. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

    } while (choice < 1 || choice > 6);
    
    return choice;
        
}

// Function to insert a new item into FishList
void insertItem(FishList& myList)
{
    string userName;
    double speciesLength;
    double speciesWeight;
    Species speciesType;

    // Prompting user for the information of the fish to insert
    cout << "Enter the information below" << endl;
    cout << "Participant name: ";
    cin >> userName;
    cout << "Species length: ";
    cin >> speciesLength;
    cout << "Species weight: ";
    cin >> speciesWeight;
    speciesType = getSpecies();  // Getting species type

    // Calling insertItem method of myList with the provided information
    myList.insertItem(userName, speciesLength, speciesWeight, speciesType);
}

// Function to list items of a specific species in FishList
void listSpeciesItems(FishList& myList)
{
    Species speciesType;

    speciesType = getSpecies();  // Getting the species type from the user
    myList.printSpeciesItems(speciesType);
}

// Function to print the entire FishList
void printList(FishList& myList)
{
    myList.printList();  // Calling printList method of myList to print all items
}

// Function to print the FishList in reverse order
void printListReverse(FishList& myList)
{
    myList.printReverseList(); // Calling printReverseList method to print the list in reverse order
}

// Function to delete a node from the FishList
void deleteNode(FishList& myList)
{
    string userName;
    double speciesLength;
    double speciesWeight;
    Species speciesType;

    // Prompting the user to enter the information for deletion
    cout << "Enter the information below for deletion" << endl;
    
    cout << "Name of participant: ";
    cin >> userName;

    cout << "Species length: ";
    cin >> speciesLength;

    cout << "Species weight: ";
    cin >> speciesWeight;

    // Getting the species type by calling getSpecies function
    speciesType = getSpecies();

    // Calling deleteNode method of myList
    myList.deleteNode(userName, speciesLength, speciesWeight, speciesType);
}

// Function to get the user's choice of fish species
Species getSpecies()
{
    int choice = 0;  // Variable to store the user's choice

    // Loop to ensure valid input
    do {
        cout << "Enter the species: 0 for PERCH, 1 for WALLEYE, 2 for BASS: ";
        cin >> choice;

    } while (choice < 0 || choice > 2);
    
    switch (choice)
    {
        case 0:
            return PERCH;
        case 1:
            return WALLEYE;
        case 2:
            return BASS;
        default:
            cout << "Invalid." << endl;
            return PERCH;  // Returns PERCH as a default, though this shouldn't occur
    }
}
