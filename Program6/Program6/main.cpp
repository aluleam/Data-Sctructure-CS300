#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;

//Function prototypes
void displayMenu();
void displayRoot(BST& tree);
void displayAllItemsPreOrder(BST& tree);
void fileContent(BST& tree);
void searchForItem(BST& tree);
void displayTotalPrizes(BST& tree);
void displayTreeHeight(BST& tree);


int main() {
    BST tree; // Create an instance of the BST class
    fileContent(tree); //Populate the BST with data from a file

    int choice;
    do {
        displayMenu(); // Display the menu
        cin >> choice;
        switch (choice) {
            case 1:
                displayRoot(tree);
                break;
            case 2:
                displayAllItemsPreOrder(tree);
                break;
            case 3:
                searchForItem(tree);
                break;
            case 4:
                displayTotalPrizes(tree);
                break;
            case 5:
                displayTreeHeight(tree);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    cout << "\nMENU" << endl;
    cout << "1. Print the Information for the root node" << endl;
    cout << "2. Display the information for all Items" << endl;
    cout << "3. Display the information for a particular title" << endl;
    cout << "4. Display the total number of prizes" << endl;
    cout << "5. Display the tree height" << endl;
    cout << "6. Exit the program." << endl << endl;
    cout << "Enter your choice: ";
}

void fileContent(BST& tree) {
    int quantity;
    string name;
    ifstream file;
    
    // Open the file
    file.open("/Users/makingaberto/Desktop/Data Stuctures/Program6/prizes.txt");
    if (!file) {
      cout << "Failed to open the file!" << endl;
    }

    // Read data from the file and populate the BST
    while (file >> quantity)
    {
        file.ignore(1);
        getline(file, name);
        tree.insertNode(name, quantity);
    }

    // Close the file
    file.close();
}

void displayRoot(BST& tree) {
    tree.displayRoot(); // Display the root node information
}

void displayAllItemsPreOrder(BST& tree) {
    tree.preOrderTraversal(); // Display all items using pre-order traversal
}

void searchForItem(BST& tree) {
    string title;
    cout << "Enter the title to search: ";
    cin.ignore();
    getline(cin, title);
    tree.searchTree(title); // Search for a particular title in the BST
}

void displayTotalPrizes(BST& tree) {
    cout << "Total number of prizes: " << tree.findTotalFields() << endl; // Display the total number of prizes in the BST
}

void displayTreeHeight(BST& tree) {
    cout << "Tree height: " << tree.getHeight() << endl; // Display the height of the BST tree
}

