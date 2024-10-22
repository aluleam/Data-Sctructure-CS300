#include <iostream>
#include "BST.h"

using namespace std;

// Inserts a new node into the BST maintaining alphabetical order
void BST::insertNodeHelper(TreeNode*& node, string thename, int thequantity)
{
    // If node is nullptr create a new node
    if (node == nullptr)
        node = new TreeNode(thename, thequantity);
    //Insert into the left subtree if name is less than current node's name
    else if (thename < node->name)
        insertNodeHelper(node->left, thename, thequantity);
    //Insert into the right subtree if name is greater than current node's name
    else if (thename > node->name)
        insertNodeHelper(node->right, thename, thequantity);
}

// Performs a pre-order traversal
void BST::preOrderTraversalHelper(TreeNode* node)
{
    // If node is not nullptr print its quantity and name
    if (node != nullptr)
    {
        cout << node->quantity << " " << node->name << endl;
        // Recursively traverse left subtree
        preOrderTraversalHelper(node->left);
        // Recursively traverse right subtree
        preOrderTraversalHelper(node->right);
    }
}

// Searches for a node with a name containing the given string
void BST::searchTreeHelper(TreeNode* node, const string& name)
{
    // If node is nullptr print "Not Found" and return
    if (node == nullptr) {
        cout << "Not Found"<<endl;
        return;
    }

    // If the node's name contains the search string print its quantity and name
    if (node->name.find(name) != string :: npos)
    {
        cout << "Found: " << node->quantity << " " << node->name << endl;
    } else {
        // Recursively search left subtree
        searchTreeHelper(node->left, name);
        // Recursively search right subtree
        searchTreeHelper(node->right, name);
    }
}


// Returns the sum of quantities of all items
int BST::findTotalFieldsHelper(TreeNode* node)
{
 
    int total = 0;
    // If node is nullptr return total
    if (node == nullptr)
    {
        return total;
    } 
    else
    {
        // Add current node's quantity to total
        total = node->quantity + findTotalFieldsHelper(node->left) + findTotalFieldsHelper(node->right);
    }
    // Return the sum
    return total;
}

int BST::getHeightHelper(TreeNode* node)
{
    // Base case if the node is nullptr the height is 0
    if(node == nullptr) {
        return 0;
    }
    else {
        // If the left subtree's height is greater than the right subtree's height
        if(1 + getHeightHelper(node->left) > 1 + getHeightHelper(node->right))
        {
            // Return the height of the left subtree
            return 1 + getHeightHelper(node->left);
        }
        else {
            // Return the height of the right subtree
            return 1 + getHeightHelper(node->right);
        }
    }
}


// Function to delete the entire Binary Search Tree
void BST::deleteTree(TreeNode* node)
{
    // Check if the node exists
    if(node)
    {
        // Recursively delete the left subtree
        deleteTree(node->left);
        
        // Recursively delete the right subtree
        deleteTree(node->right);
        
        // Delete the current node
        delete node;
    }
}

// Prints the name and quantity of the root node
void BST::displayRoot()
{
    // If the root node is nullptr print that the tree is empty
    if(root == nullptr)
    {
        cout<<"The tree is empty"<<endl;
    }
    else
    {
        // Print the quantity and name of the root node
        cout << root->quantity<< " "<< root->name << endl;
    }
}
