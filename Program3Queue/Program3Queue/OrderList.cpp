#include "OrderList.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Initializes the OrderList with the given size and default values
OrderList::OrderList(int size)
{
    queueSize = size;
    front = -1;
    rear = -1;
    itemCount = 0;

    queueArray = new Order[queueSize];
    hamburgerPrice = 7.00;
    cheeseburgerPrice = 8.00;
    friesPrice = 2.50;
    taxRate = 0.07;
    discountRate = 0.1;
}

// Releases dynamically allocated memory
OrderList::~OrderList() {
    delete[] queueArray;
}

// Add an order to the queue
void OrderList::enqueue(const string& name, int burgers, int cheeseburgers, int fries) 
{
    // Check if the queue is not full
    if (!isFull()) {
        // Create a new order
        Order newOrder;
        newOrder.name = name;
        newOrder.burgers = burgers;
        newOrder.cheeseburgers = cheeseburgers;
        newOrder.fries = fries;

       
        //Calculate the new rear position
        rear = (rear + 1) % queueSize;
        queueArray[rear] = newOrder;
        itemCount++;

        // If this is the first order update front
        if (front == -1) {
            front = 0;
        }
    } else {
        // If the queue is full print an error message
        cout << "Queue is full, cannot add new order." << endl;
    }
}

// Remove an order from the queue
bool OrderList::dequeue(string& name, int& burgers, int& cheeseburgers, int& fries) 
{
    double subtotal,discount;
    cout << fixed << setprecision(2);

    // Check if the queue is not empty
    if (!isEmpty()) {
        // Get details of the order at the front
        Order order = queueArray[front];
        name = order.name;
        burgers = order.burgers;
        cheeseburgers = order.cheeseburgers;
        fries = order.fries;

        // Calculate order details
        subtotal = burgers * hamburgerPrice + cheeseburgers * cheeseburgerPrice + fries * friesPrice;
        discount = subtotal > 25.0 ? subtotal * discountRate : 0; // If the total is greater than $25 apply discount otherwise set it to 0
        double tax = (subtotal - discount) * taxRate;
        double total = subtotal - discount + tax;

        // Display order summary
        cout << "Order for " << name << ":\n"
             << "Burgers: " << burgers << " at $" << hamburgerPrice << " each\n"
             << "Cheeseburgers: " << cheeseburgers << " at $" << cheeseburgerPrice << " each\n"
             << "Fries: " << fries << " at $" << friesPrice << " each\n"
             << "Subtotal: $" << subtotal << "\n"
             << "Discount: -$" << discount << "\n"
             << "Tax: +$" << tax << "\n"
             << "Total: $" << total << endl
             << string(30, '-') << endl;

        // Remove the order from the queue
        front = (front + 1) % queueSize;
        itemCount--;

        // Reset the queue if becomes empty
        if (itemCount == 0)
        {
            front = -1;
            rear = -1;
        }

        return true;
    } else 
    {
        // Print an error message if the queue is empty
        cout << "Queue is empty, cannot dequeue an order." << endl;
        return false;
    }
}

// Check if the queue is full
bool OrderList::isFull() const
{
    return itemCount == queueSize;
}

// Check if the queue is empty
bool OrderList::isEmpty() const {
    return itemCount == 0;
}

// Search for an order by name and retrieve its details
// Search for an order by name
bool OrderList::searchOrder(const string& name, int& burgers, int& cheeseburgers, int& fries) const
{
    // Check if the queue is not empty
    if (!isEmpty()) {
        int cur = front;
        // Loop through the queue to find the order
        for (int i = 0; i < itemCount; ++i) 
        {
            // If the name matches update the details and return true
            if (queueArray[cur].name == name) {
                burgers = queueArray[cur].burgers;
                cheeseburgers = queueArray[cur].cheeseburgers;
                fries = queueArray[cur].fries;
                return true; // Order found
            }
            // Move to the next element
            cur = (cur + 1) % queueSize;
        }
    }
    // If order not found, return false
    return false; // Order not found
}


// Print the queue in reverse order
void OrderList::printReverse() const 
{
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    // Start the recursion from rear
    printReverse(rear);
}

// Helper function to print the queue in reverse recursively
void OrderList::printReverse(int index) const 
{
    int prevIndex;
    if (index == front - 1) // Base case
    {
         return;
    }

    // Print order details
    cout << "Order Name: " << queueArray[index].name
         << ", Burgers: " << queueArray[index].burgers
         << ", Cheeseburgers: " << queueArray[index].cheeseburgers
         << ", Fries: " << queueArray[index].fries << endl;

    // Move to the previous one
    prevIndex = index - 1;
    if (prevIndex < 0)
        prevIndex = queueSize - 1; // Wrap around

    if (index != front)
    {
        printReverse(prevIndex);
    }
}

