// ************************************************************************************
// ************************************************************************************
// Program:      Food Truck                                                          **
// Name:         Masumbuko Alulea                                                    **
// Course:       CSC 300 Data Structures                                             **
// Instructor:   Paula Kurtenbach                                                    **
// Date:         14th February 2024                                                  **
// Description:  This program implements a static queue system for managing customer **
//               orders at a food truck. It allows customers to place orders for     **
//               hamburgers, cheeseburgers, and fries, which are then queued and     **
//               served on a first-come, first-served basis. The program offers      **
//               functionalities such as adding and removing orders, printing the    **
//               current queue, and searching for orders by customer name.           **
//               Additionally, it provides an option to print the queue in reverse.  **
//                                                                                   **
// ************************************************************************************
// ************************************************************************************
#include "OrderList.h"
#include <iostream>
#include <string>

using namespace std;
void addOrder(OrderList& queue);
void remOrder(OrderList& queue);
void printQueue(OrderList& queue);
void printQueueReverse(OrderList& queue);
void searchForOrder(OrderList& queue); // Function to search for an order by name

int main() {
  //queue size
    const int size = 5;
    // Create an instance of OrderList with the given size
    OrderList queue(size);
    int choice;

    do {
        // Print menu options
        cout << "The Food Truck Menu" << endl;
        cout<<"============================="<<endl;
        cout << "1. Add an order" << endl;
        cout << "2. Remove an order" << endl;
        cout << "3. Print the queue" << endl;
        cout << "4. Print the queue in reverse" << endl;
        cout << "5. Search for an order by name" << endl; // Added search option
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        // Get user choice
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                // Add an order to the queue
                addOrder(queue);
                break;
            case 2:
                // Remove an order from the queue
                remOrder(queue);
                break;
            case 3:
                // Print the queue
                printQueue(queue);
                break;
            case 4:
                // Print the queue in reverse
                printQueueReverse(queue);
                break;
            case 5:
                // Search for an order by name
                searchForOrder(queue); // Added search option
                break;
            case 6:
                // Exit the program
                cout << "Exiting program...Toodles!!!"<<endl;
                break;
            default:
                // Invalid choice
                cout << "Invalid choice"<<endl;
                break;
        }
    } while (choice != 6); // Continue until user chooses to exit

    return 0;
}

// Function to add an order to the queue.
void addOrder(OrderList& queue)
{
    string name;
    int burgers, cheeseburgers, fries;
    
    // Check if the queue is full.
    if (queue.isFull())
    {
        cout << "The queue is full" << endl;
        return;
    }
    
    // Prompt the user to enter order details.
    cout << "Enter the name for the order: ";
    getline(cin, name);  // Use getline to allow spaces in the name
    cout << "Enter the number of hamburgers: ";
    cin >> burgers;
    cout << "Enter the number of cheeseburgers: ";
    cin >> cheeseburgers;
    cout << "Enter the number of fries: ";
    cin >> fries;

    // Add the order to the queue.
    queue.enqueue(name, burgers, cheeseburgers, fries);
    cout << "Order added successfully." << endl;
    cin.ignore(); // Ignore newline character in the input buffer
}


// Function to remove an order from the queue.
void remOrder(OrderList& queue)
{
    string name;
    int burgers, cheeseburgers, fries;
    // Check if the queue is empty.
    if (queue.isEmpty())
    {
        cout << "The queue is empty." << endl;
    } else {

        // Dequeue an order from the queue.
        if (queue.dequeue(name, burgers, cheeseburgers, fries))
        {
            cout << "Order for " << name << " removed successfully.\n";
        } else {
            cout << "Failed to remove an order." << endl;
        }
    }
}

// Function to print the orders in reverse order
void printQueueReverse(OrderList& queue)
{
    queue.printReverse();
}
// Function to print the orders currently in the queue.
void printQueue(OrderList& queue)
{
    // Check if the queue is empty.
    if (queue.isEmpty()) 
    {
        cout << "The queue is currently empty." << endl;
        return;
    }

    // Create a temporary queue
    OrderList temp(5);
    string name;
    int burgers, cheeseburgers, fries;

    cout << "Current Queue:" << endl<<endl;

    // Dequeue orders from the queue print their details and enqueue them into the temp queue
    while (!queue.isEmpty())
    {
        queue.dequeue(name, burgers, cheeseburgers, fries);
        cout << "Name: " << name << ", Burgers: " << burgers << ", Cheeseburgers: " << cheeseburgers << ", Fries: " << fries << endl;
        temp.enqueue(name, burgers, cheeseburgers, fries);
    }

    // Move the orders back from the temp queue to the original one
    while (!temp.isEmpty())
    {
        temp.dequeue(name, burgers, cheeseburgers, fries);
        queue.enqueue(name, burgers, cheeseburgers, fries);
    }
}

// Function to search for an order by the name of the customer in the queue
void searchForOrder(OrderList& queue)
{
    string name;
    int burgers, cheeseburgers, fries;
    // Prompt user to input the name of the customer.
    cout << "Enter the name of the customer: ";
    getline(cin, name);
    // Search for the order with the given name in the queue.
    if (queue.searchOrder(name, burgers, cheeseburgers, fries))
    {
        // If order found, display the order details.
        cout << "Order found for " << name << ":\n"
             << "Burgers: " << burgers << "\n"
             << "Cheeseburgers: " << cheeseburgers << "\n"
             << "Fries: " << fries << endl;
    }
    else
    {
        // If no order found, inform the user.
        cout << "No oder found for \"" << name << "\"" << endl;
        cout<<string(30,'-')<<endl;
    }
}
