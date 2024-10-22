#ifndef FISHLIST_H
#define FISHLIST_H
#include <string>
using namespace std;

// Enumeration for the species
enum Species { PERCH, WALLEYE, BASS };

class FishList
{
private:
    struct ListNode
    {
        string name;         // Name of the participant
        double length;       // Length of the fish
        double weight;       // Weight of the fish
        Species speciesType; // Type of the fish species

        ListNode *next;  // Pointer to the next node in the list
        // Default constructor for ListNode
        ListNode()
        {
            next = nullptr;
            name = "";
            length = 0.0;
            weight = 0.0;
        }
    };

    ListNode *head; // Pointer to the first node in the list

    // Private function for printing recursively
    void printReverse(ListNode *node = nullptr) const;

public:
    // Default constructor
    FishList(): head(nullptr) { } //set head to nullptr
    FishList(const FishList& theCopy); // Copy constructor
    ~FishList(); // Destructor

    // Public member functions
    void insertItem(string name, double length, double weight, Species speciesType);
    void printSpeciesItems(Species speciesType) const;
    void printList() const;
    void printReverseList() const; //Wrapper for the printing recursively funtion
    void deleteNode(string name, double length, double weight, Species speciesType);

};

#endif

