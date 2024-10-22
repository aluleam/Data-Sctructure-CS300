#include <iostream>
#include "RobotPath.h"

// Push a new segment onto the stack.
void StackPath::push(double theDistance, int theDegree, Direction theDirection)
{
    StackNode *newNode = new StackNode; //Create new node.
    newNode->distance = theDistance; //Assign distance.
    newNode->degree = theDegree; // Assign degree.
    newNode->direction = theDirection; //Assign direction.
    
    // Insert newNode at top of stack.
    if(isEmpty()) 
    {
        top = newNode; // Stack was empty, newNode is now top.
    } else 
    {
        newNode->next = top; //Stack was not empty, insert before current top
        top = newNode; // Update top to newNode.
    }
}

// Pop the top segment from the stack.
void StackPath::pop(double &theDistance, int &theDegree, Direction &theDirection) {
    if (isEmpty())
    {
        cout << "Nothing to pop!" << endl;
    } else
    {
        // Retrieve and remove top node's data.
        theDistance = top->distance;
        theDegree = top->degree;
        theDirection = top->direction;
        
        StackNode *nodePtr = top; //Temp pointer to top.
        top = top->next; //Move top to next node.
        delete nodePtr; //Delete old top node.
    }
}

// Check if stack is empty.
bool StackPath::isEmpty()
{
    return !top; // True if top is nullptr, false otherwise.
}

StackPath::~StackPath() {
    StackNode *nodePtr = top; // Start at top of stack.
    while (nodePtr != nullptr)
    {
        StackNode *nextNode = nodePtr->next; //Save next node.
        delete nodePtr; //Delete current node.
        nodePtr = nextNode; // Move to next node.
    }
}

