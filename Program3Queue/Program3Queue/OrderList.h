#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <string>
using namespace std;

class OrderList
{
private:
    struct Order
    {
        string name;
        int burgers;
        int cheeseburgers;
        int fries;
    };

    Order* queueArray; //array of struct to hold the customer's details
    int front;
    int rear;
    int itemCount;
    int queueSize;
    double hamburgerPrice;
    double cheeseburgerPrice;
    double friesPrice;
    double taxRate;
    double discountRate;
    
    // Helper function to print the queue in reverse
    void printReverse(int index) const;

public:
    //initializes the queue with given size
    OrderList(int size);
    ~OrderList();

    // Adds an order to the queue
    void enqueue(const string& name, int burgers, int cheeseburgers, int fries);
    // Remove an order from the queue
    bool dequeue(string &name, int &burgers, int &cheeseburgers, int &fries);
    // Checks if the queue is full
    bool isFull() const;
    // Checks if the queue is empty
    bool isEmpty() const;
    
    
    
    // Search for an order by name display its details
    bool searchOrder(const string& name, int& burgers, int& cheeseburgers, int& fries) const;
    // Print the queue in reverse order
    void printReverse() const;
};

#endif


