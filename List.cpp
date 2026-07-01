#include <iostream>
using namespace std;

// Definition of a Binary Tree Node structure
typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

// Forward declarations of core traversal functions
void print_leaf(Node *root);
void print_all_nodes(Node *root);
Node *newNode(int data);

int main()
{
    // Hardcoded allocation and construction of a sample hierarchical tree structure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    // Execute and print tree traversal outputs
    print_leaf(root);
    print_all_nodes(root);

    return 0;
}

// Recursive function to print only the leaf nodes of the tree
void print_leaf(Node *root)
{
    if (!root)
        return;

    // Check if the current node has no children (Leaf condition)
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }

    if (root->left)
        print_leaf(root->left);

    if (root->right)
        print_leaf(root->right);
}

// Recursive function to perform a pre-order traversal of all tree nodes
void print_all_nodes(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";

    if (root->left)
        print_all_nodes(root->left);
    if (root->right)
        print_all_nodes(root->right);
}

// Helper function to allocate and initialize a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
