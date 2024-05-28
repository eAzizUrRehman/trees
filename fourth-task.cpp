// Submitted by: AZIZ UR REHMAN - 866-FOC/BSIT/F22(A)

// FOURTH TASK
// Question: Implement a function to delete a node from the BST.

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

// FUNCTION TO FIND MINIMUM VALUE IN THE TREE OR SUB-TREE
TreeNode *findMinValueInBST(TreeNode *root)
{
    TreeNode *temp = root;

    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp;
}

TreeNode *deleteNodeFromBST(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->value == value)
    {
        // ZERO CHILD
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 1 LEFT CHILD
        if (root->left != nullptr && root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // 1 RIGTH CHILD
        if (root->left == nullptr && root->right != nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }

        // 2 CHILDREN - BOTH LEFT & RIGHT
        if (root->left != nullptr && root->right != nullptr)
        {
            int minimumValue = findMinValueInBST(root->right)->value;

            root->value = minimumValue;

            root->right = deleteNodeFromBST(root->right, minimumValue);
            return root;
        }
    }
    else if (root->value > value)
    {
        root->left = deleteNodeFromBST(root->left, value);
        return root;
    }
    else if (root->value < value)
    {
        root->right = deleteNodeFromBST(root->right, value);
        return root;
    }
}

int main()
{

    TreeNode *root = nullptr;

    root = insertInBST(root, 50);

    insertInBST(root, 30);
    insertInBST(root, 70);

    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout << "\nIn-order Traversal Before Deletion: ";
    inOrderTraversal(root);
    cout << endl;

    root = deleteNodeFromBST(root, 50); // Delete node with value 50
    root = deleteNodeFromBST(root, 30); // Delete node with value 30
    root = deleteNodeFromBST(root, 20); // Delete node with value 20

    cout << "\nIn-order Traversal After Deletion: ";
    inOrderTraversal(root);
    cout << endl
         << endl;

    return 0;
}