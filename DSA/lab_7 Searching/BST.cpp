#include <iostream>
using namespace std;

// DLL Node acting as BST Node
struct Node {
    int data;
    Node* prev; // left child
    Node* next; // right child

    Node(int value) {
        data = value;
        prev = next = nullptr;
    }
};

// Insert a node in the BST
Node* insert(Node* root, int item) {
    if (root == nullptr)
        return new Node(item);

    if (item < root->data)
        root->prev = insert(root->prev, item);
    else if (item > root->data)
        root->next = insert(root->next, item);

    return root;
}

// Search a node in the BST
Node* search(Node* root, int item) {
    if (root == nullptr || root->data == item)
        return root;

    if (item < root->data)
        return search(root->prev, item);
    else
        return search(root->next, item);
}

// Find minimum node (used in delete)
Node* findMin(Node* root) {
    while (root && root->prev)
        root = root->prev;
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int item) {
    if (root == nullptr)
        return nullptr;

    if (item < root->data)
        root->prev = deleteNode(root->prev, item);
    else if (item > root->data)
        root->next = deleteNode(root->next, item);
    else {
        // Node found
        if (root->prev == nullptr) {
            Node* temp = root->next;
            delete root;
            return temp;
        }
        else if (root->next == nullptr) {
            Node* temp = root->prev;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->next);
        root->data = temp->data;
        root->next = deleteNode(root->next, temp->data);
    }

    return root;
}

// Inorder traversal (sorted output)
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->prev);
    cout << root->data << " ";
    inorderTraversal(root->next);
}

int main() {
    Node* root = nullptr;

    // Inserting nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Deleting a node
    root = deleteNode(root, 70);
    cout << "After deleting 70: ";
    inorderTraversal(root);
    cout << endl;

    // Searching for a node
    Node* found = search(root, 40);
    cout << "Search 40: " << (found ? "Found" : "Not found") << endl;

    return 0;
}
