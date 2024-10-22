#ifndef ROBOTPATH_H
#define STACK_H
#include <iostream>
#include <string>
using namespace std;

// Defines direction of rotation for robot path segments.
enum Direction {CLOCKWISE, COUNTERCLOCKWISE};

// Class to manage robot path using a stack.
class RobotPath {
private:
    struct StackNode {
        double distance; // Segment distance.
        int degree; // Angle of turn in degrees.
        Direction direction; //Direction of turn.
        StackNode *next; //Pointer to next segment.
        
        // Constructor for initializing default values
        StackNode()
        {
            distance = 0.0;
            degree = 0;
            direction = CLOCKWISE;
            next = nullptr;
        }
    };
    
    StackNode *top; //Points to the top of the stack.

public:
    // Initializes an empty path
    RobotPath()
    {
        top = nullptr;
        
    }
    //Destructor for the Robotpath class.
    ~RobotPath();
    RobotPath(RobotPath &theCopy); //Copy constructor
    // Adds a segment to the path.
    void push(double theDistance, int theDegree, Direction theDirection);
    // Removes the top segment from the path
    void pop(double &theDistance, int &theDegree, Direction &theDirection);
    // Checks if the path is empty.
    bool isEmpty();
};

#endif


