// Submitted by: AZIZ UR REHMAN - 866-FOC/BSIT/F22(A)

// THIRD TASK
// Question: Implement a function to search for a value in the BST and return a boolean indicating whether the value exists in the tree.

#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode *insertInBST(TreeNode *root, int value)
{

    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (value < root->value)
    {
        root->left = insertInBST(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insertInBST(root->right, value);
    }
    return root;
}

void inOrderTraversal(TreeNode *root)
{

    if (root == nullptr)
        return;

    inOrderTraversal(root->left);

    cout << root->value << " ";

    inOrderTraversal(root->right);
}

void preOrderTraversal(TreeNode *root)
{

    if (root == nullptr)
        return;

    cout << root->value << " ";

    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode *root)
{

    if (root == nullptr)
        return;

    postOrderTraversal(root->left);

    postOrderTraversal(root->right);

    cout << root->value << " ";
}

bool searchValueInBST(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (value == root->value)
    {
        return true;
    }

    if (value < root->value)
    {
        return searchValueInBST(root->left, value);
    }
    else
    {
        return searchValueInBST(root->right, value);
    }
}

int main()
{

    TreeNode *root = nullptr;

    // zero level of the tree
    root = insertInBST(root, 50);

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
    cout << endl;

    cout << "\nIs 50 available? : " << (searchValueInBST(root, 50) ? "True" : "False") << endl; // TRUE

    cout << "\nIs 70 available? : " << (searchValueInBST(root, 70) ? "True" : "False") << endl; // TRUE

    cout << "\nIs 60 available? : " << (searchValueInBST(root, 60) ? "True" : "False") << endl; // TRUE

    cout << "\nIs 0 available? : " << (searchValueInBST(root, 0) ? "True" : "False") << endl; // FALSE

    cout << "\nIs -500 available? : " << (searchValueInBST(root, -500) ? "True" : "False") << endl; // FALSE

    cout << "\nIs 500 available? : " << (searchValueInBST(root, 500) ? "True" : "False") << endl // FALSE
         << endl;

    return 0;
}