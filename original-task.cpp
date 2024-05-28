// Submitted by: AZIZ UR REHMAN - 866-FOC/BSIT/F22(A)

#include <iostream>
using namespace std;

// Definition of a TreeNode
class TreeNode
{
public:
    int value;       // Value of the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Constructor to initialize the node with a value
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// RECURSIVE FUNCTION ---- insertInBST()
// Function to insert a new value into a BST
TreeNode *insertInBST(TreeNode *root, int value)
{

    // BASE CONDITION
    if (root == nullptr)
    {
        return new TreeNode(value); // calling constructor
    }

    // 30<50
    if (value < root->value)
    {
        root->left = insertInBST(root->left, value);
        // ROOT->LEFT behave as root for above call
    }
    else if (value > root->value)
    {
        root->right = insertInBST(root->right, value);
    }
    return root;
}

// In-order traversal of a binary tree
void inOrderTraversal(TreeNode *root)
{

    // BASE CONDITION
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);

    cout << root->value << " "; // root

    inOrderTraversal(root->right);
}

// \nPre-order Traversal of a binary tree
void preOrderTraversal(TreeNode *root)
{
    // BASE CONDITION
    if (root == nullptr)
        return;

    cout << root->value << " ";

    preOrderTraversal(root->left);
    
    preOrderTraversal(root->right);
}

// \nPost-order Traversal of a binary tree
void postOrderTraversal(TreeNode *root)
{

    // BASE CONDITION
    if (root == nullptr)
        return;

    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    cout << root->value << " ";
}

int main()
{

    TreeNode *root = nullptr;

    // zero level of the tree
    root = insertInBST(root, 50); // root now storing Node with value 50

    // first level of the tree
    insertInBST(root, 30);
    insertInBST(root, 70);

    // second level of the tree
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout << "\nIn-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "\nPre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "\nPost-order Traversal: ";
    postOrderTraversal(root);
    cout << endl << endl;

    return 0;
}