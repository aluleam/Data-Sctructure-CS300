#ifndef BST_H
#define BST_H
#include <string>
using namespace std;

class BST
{
private:
    struct TreeNode
    {
        string name;
        int quantity;
        TreeNode* left;
        TreeNode* right;
        TreeNode(string theName, int quant): name(theName), quantity(quant), left(nullptr), right(nullptr) { }
    };
    TreeNode *root;

    void insertNodeHelper(TreeNode*& node, string name, int quantity);
    void preOrderTraversalHelper(TreeNode* node);
    void searchTreeHelper(TreeNode* node, const string& name);
    int findTotalFieldsHelper(TreeNode* node);
    int getHeightHelper(TreeNode* node);
    void deleteTree(TreeNode* node);
   
public:
    //Default constructor
    BST()
    {
        root = nullptr;
    }
    //Destructor
    ~BST()
    {
        deleteTree(root);
    }
    // Public function to insert a node into the BST
    void insertNode(string thename, int thequantity)
    {
        insertNodeHelper(root,thename,thequantity);
    }
    void displayRoot();
    //Public function to perform pre-order traversal of the BST
    void preOrderTraversal()
    {
        preOrderTraversalHelper(root);
    }
    //Public function to search for a node with a given name in the BST
    void searchTree(string thename)
    {
        searchTreeHelper(root, thename);
    }
    //Public function to calculate the total number of prizes in the BST
    int findTotalFields()
    {
        return findTotalFieldsHelper(root);
    }
    //Public function to calculate the height of the BST
    int getHeight()
    {
        return getHeightHelper(root);
    }
};

#endif

