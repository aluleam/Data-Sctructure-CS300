// **********************************************************************************
// **********************************************************************************
// Program:      Robot Path                                                         **
// Name:         Masumbuko Alulea                                                   **
// Course:       CSC 300 Data Structures                                            **
// Instructor:   Paula Kurtenbach                                                   **
// Date:         06 February 2024                                                   **
// Description:  This program is about helping a fire-fighting robot remember       **
//               where it has gone inside a building. It can keep track of the      **
//               path by storing how far the robot travels, which way it turns,     **
//               and if it turns left or right. You can add new moves to the path,  **
//               see the path backwards, save the path, and stop the program.       **
//                                                                                  **
// **********************************************************************************
// **********************************************************************************

#include <iostream>
#include "RobotPath.h"
using namespace std;

// Function prototypes.
int printMenu();
void addSegment(StackPath &robot);
void returntoStart(StackPath &robot);
Direction returnEnumChoice();
void Exit();

int main() {
    StackPath robot; // Create an instance of RobotPath
    int choice;
    
    // Loop until the user chooses to exit
    do {
        choice = printMenu(); //Display menu and get choice.
        
        switch (choice) {
            case 1:
                addSegment(robot); //Add a path segment to the robot's path.
                break;
            case 2:
                returntoStart(robot); //Return robot to start by reversing path.
                break;
            case 3:
                Exit();
                break;
            default:
                cout << "Invalid choice!" << endl; //Handle invalid menu choice.
                break;
        }
    } while (choice != 3);
    
    return 0;
}

// Function to add a segment to the robot's path.
void addSegment(StackPath &robot)
{
    double theDistance;
    int theDegree;
    Direction theDirection;
    
    cout << "Enter the distance: ";
    cin >> theDistance;
    
    // Validate degree input
    do {
        cout << "Enter the degree (0 to 360): ";
        cin >> theDegree;
        if (theDegree < 0 || theDegree > 360) {
            cout << "Invalid input. Please enter a value between 0 and 360." << endl;
        }
    } while (theDegree < 0 || theDegree > 360); //Ensure degree is within 0 to 360.
    
    theDirection = returnEnumChoice();
    
    robot.push(theDistance, theDegree, theDirection); //Add the segment to the robot's path.
}

// Function to reverse the robot's path and simulate returning to start.
void returntoStart(StackPath &robot) {
    double distance;
    string reDirection;
    int degree;
    Direction direction;

    // Check if the path is empty.
    if (robot.isEmpty())
    {
        cout << "The path is empty" << endl;
    }
    else
    {
        cout << "Reversing the path " << endl;
        cout<<endl;
        // Reverse the path by popping each segment until empty.
        while (!robot.isEmpty())
        {
            robot.pop(distance, degree, direction); // Pop each segment.
            
            //Reverse the direction for display.
            if (direction == CLOCKWISE)
            {

                reDirection = "CounterClockwise (reverse)";
            }
            else
            {
                reDirection = "Clockwise (reverse)";
            }

            // Display the reversed segment.
            cout << "Distance = " << distance<<" meters"
                 << ", Turn = " << degree << "° "
                 << reDirection << endl;
        }
    }
}

//Function to exit the program with a message.
void Exit()
{
    cout << "Exiting program..." << endl;
}

//Function to print the menu and get the user's choice.
int printMenu() {
    int choice;
    
    cout << endl<< "MENU" << endl;
    cout << "-------------------" << endl;
    cout << "1. Add a segment" << endl;
    cout << "2. Return to start" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    return choice;
}

//Function to return the direction choice as an enum based on user input
Direction returnEnumChoice()
{
    int choice;
    Direction direc;
    // Get direction choice from user.
    cout << "Enter the direction 0 for Clockwise, 1 for CounterClockwise: ";
    cin >> choice;
    // Validate choice
    if(choice<0 || choice>1)
    {
        while (choice != 0 && choice != 1)
        {
            cout << "Invalid choice. Please enter 0 for Clockwise or 1 for CounterClockwise: ";
            cin >> choice;
        }
    }
    
    direc = static_cast<Direction>(choice); //Convert integer choice to enum.
    
    return direc; //Return the direction as enum.
}
