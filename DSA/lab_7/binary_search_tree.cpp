#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node *root;

    Node *insert(Node *node, int value) {
        if (node == nullptr) {
            return new Node(value); // Create a new node if the position is empty
        }
        if (value < node->data) {
            node->left = insert(node->left, value); // Insert into the left subtree
        } else if (value > node->data) {
            node->right = insert(node->right, value); // Insert into the right subtree
        }
        return node; // Return the (unchanged) node pointer
    }

    void inOrder(Node *node) {
        if (node != nullptr) {
            inOrder(node->left);       // Visit left subtree
            cout << node->data << " "; // Visit root
            inOrder(node->right);      // Visit right subtree
        }
    }

    bool search(Node *node, int value) {
        if (node == nullptr) {
            return false; // Not found
        }
        if (node->data == value) {
            return true; // Found
        } else if (value < node->data) {
            return search(node->left, value); // Search in left subtree
        } else {
            return search(node->right, value); // Search in right subtree
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void inOrder() {
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }

    void search(int value) {
        if (search(root, value)) {
            cout << value << " is found in the BST.\n";
        } else {
            cout << value << " is not found in the BST.\n";
        }
    }
};

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    /*     10
          /  \
        5    15
       / \  
      3  7
    */
    tree.inOrder(); // Output: 3 5 7 10 15

    tree.search(7);  // Output: 7 is found in the BST.
    tree.search(20); // Output: 20 is not found in the BST.

    return 0;
}
/*
In-order Traversal: 3 5 7 10 15 
7 is found in the BST.
20 is not found in the BST.
*/