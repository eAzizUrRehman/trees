// SECOND TASK
// Question: Add error handling in the insertInBST function to avoid duplicate values.

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

    // IF CURRENT NODE VALUE IS SAME AS INCOMING VALUE, RETURN CURRENT NODE INSTEAD OF INSERTING A NEW NODE
    // THUS PREVENTING ENTRY OF DUPLICATE VALUES IN THE TREE
    if (root->value == value)
    {
        return root;
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
    root = insertInBST(root, 50);

    // first level of the tree
    insertInBST(root, 30);
    insertInBST(root, 70); // FIRST TIME ENTERING 70 - ALLOWED

    // second level of the tree
    insertInBST(root, 20);
    insertInBST(root, 70); // SECOND TIME ENTERING 70 - NOT ALLOWED
    insertInBST(root, 60);
    insertInBST(root, 70); // THIRD TIME ENTERING 70 - NOT ALLOWED

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