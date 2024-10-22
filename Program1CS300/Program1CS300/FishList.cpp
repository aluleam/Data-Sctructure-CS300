#include "FishList.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string speciesString(Species species);
// Function to insert a new item into the FishList
void FishList::insertItem(string Thename, double Thelength, double Theweight, Species ThespeciesType)
{
    ListNode *newNode;   //Pointer for the new node
    ListNode *nodePtr;
    ListNode *previousNode; // Pointer to track the previous node
    previousNode = nullptr;

    // Creating a new node and assigning the data
    newNode = new ListNode; //allocate memory for the new node
    newNode->name = Thename;
    newNode->length = Thelength;
    newNode->weight = Theweight;
    newNode->speciesType = ThespeciesType;
    newNode->next = nullptr;

    // Insert the new node at the head if the list is empty
    if (!head)
    {
        head = newNode;
    }
    else
    {
        // Start at the head of the list
        nodePtr = head;

        // Traverse through the entire list to find the insert location based on length + weight
        while (nodePtr != nullptr && (nodePtr->length + nodePtr->weight) > (Thelength + Theweight))
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // Inserting at the head if no previous node is found
        if (!previousNode)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            // Inserting the node in the right position
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

// Function to print items of a specific species in the list
void FishList::printSpeciesItems(Species Type) const
{
    ListNode *nodePtr;

    nodePtr = head;  // Start from the head of the list

    // Print the header of the table
    cout << setw(5) << "Name"
         << setw(12) << "Length"
         << setw(12) << "Weight"
         << setw(15) << "Species Type" << endl;
    cout << string(43, '-') << endl;  //Print a separator line

    // Traverse the list
    while (nodePtr != nullptr)
    {
        // Check if the current node's species is the same as the specified type
        if (nodePtr->speciesType == Type)
        {
        
            cout << setw(5) << nodePtr->name
                 << setw(10) << nodePtr->length
                 << setw(10) << nodePtr->weight
                 << setw(15) << speciesString(nodePtr->speciesType) //Convert species enum to string
                 << endl;
        }
        nodePtr = nodePtr->next;  // Move to the next node
    }
}

// Function to convert Species enum to string
string speciesString(Species species)
{
    switch (species)
    {
        case PERCH:
            return "PERCH";
        case WALLEYE:
            return "WALLEYE";
        case BASS:
            return "BASS";
        default:
            return "UNKNOWN";
    }
}

// Function to print all the items in the FishList
void FishList::printList() const {
    ListNode *nodePtr = head;  // Starting from the head of the list

    // Print the header of the table
    cout << setw(5) << "Name"
         << setw(12) << "Length"
         << setw(12) << "Weight"
         << setw(15) << "Species Type" << endl;
    cout << string(43, '-') << endl;  // Print a separator line

    // Traverse the list
    while (nodePtr != nullptr)
    {
        cout << setw(5) << nodePtr->name
             << setw(10) << nodePtr->length
             << setw(10) << nodePtr->weight
             << setw(15) << speciesString(nodePtr->speciesType)
             << endl;
        
        nodePtr = nodePtr->next;  // Move to the next node
    }
}

// Displaying the list in reverse
void FishList::printReverse(ListNode *nodePtr) const
{
    //base case
    if (nodePtr == nullptr) //if the nodeptr is nullptr end the recursion
    {
        cout << setw(5) << "Name"
        << setw(12) << "Length"
        << setw(12) << "Weight"
        << setw(15) << "Species Type" << endl;
        cout << string(43, '-') << endl;
        
        return;
    }
    // Recursive call with the next node
    printReverse(nodePtr->next);
    
    cout<< setw(5) << nodePtr->name
        << setw(10) << nodePtr->length
        << setw(10) << nodePtr->weight
        << setw(15) << speciesString(nodePtr->speciesType)
    << endl;
}

// Public function to display the entire list in reverse order
void FishList::printReverseList() const
{
    printReverse(head); //Call for the private recursive function from the start
    cout <<endl;
    
}

void FishList::deleteNode(string thename, double thelength, double theweight, Species thespeciesType)
{
    ListNode *nodePtr;
    ListNode *prevNode;
    prevNode = nullptr;
    
    // If the list is empty, there's nothing to delete
    if (!head)
    {
        return;
    }
    
    // Check if the head node is the one to be deleted
    if (head->name == thename && head->length == thelength &&
        head->weight == theweight && head->speciesType == thespeciesType)
    {
        nodePtr = head->next;  // Save the next node
        delete head;           // Delete the head node
        head = nodePtr;        // Update the head to the next node
    }
    else
    {
        nodePtr = head;  // Start from the beginning of the list
        
        while (nodePtr != nullptr && !(nodePtr->name == thename &&
         nodePtr->length == thelength && nodePtr->weight == theweight &&
          nodePtr->speciesType == thespeciesType))
        {
            prevNode = nodePtr;       // Update the previous node
            nodePtr = nodePtr->next;  // Move to the next node
        }
        
        // If node found, remove it from the list and delete
        if (nodePtr)
        {
           prevNode->next = nodePtr->next;
           delete nodePtr;
        }
        
    }
}

 FishList :: ~FishList()
{
     ListNode *curNode;
     ListNode *nodePtr;
     
     if(!head) //if there's nothing, do nothing
     {
         return;
     }
     else
     {
         nodePtr= head; //start from the beginning of the list
         
         while(nodePtr != nullptr)
         {
             curNode = nodePtr->next; // Save the pointer to the next node
             delete nodePtr;         // Delete the current node
             nodePtr = curNode;   // Move to the next node in the list
         }
     }
 }
