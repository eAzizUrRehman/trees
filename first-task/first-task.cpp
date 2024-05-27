// FIRST TASK
// Question: Modify the main function to create a different BST by inserting different values.

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

int main()
{

    TreeNode *root = nullptr;

    // zero level of the tree
    root = insertInBST(root, 1000);

    // first level of the tree
    insertInBST(root, 500);
    insertInBST(root, 1600);

    // second level of the tree
    insertInBST(root, 300);
    insertInBST(root, 700);
    insertInBST(root, 1400);
    insertInBST(root, 1800);

    // third level of the tree
    insertInBST(root, 200);
    insertInBST(root, 400);
    insertInBST(root, 600);
    insertInBST(root, 800);
    insertInBST(root, 1300);
    insertInBST(root, 1500);
    insertInBST(root, 1700);
    insertInBST(root, 2000);

    cout << "\nIn-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "\nPre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "\nPost-order Traversal: ";
    postOrderTraversal(root);
    cout << endl
         << endl;

    return 0;
}