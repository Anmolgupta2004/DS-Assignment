#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};


Node* insertIterative(Node* root, int key) {
    Node* newNode = new Node(key);
    if (root == nullptr)
        return newNode;

    Node* parent = nullptr;
    Node* curr = root;

    while (curr != nullptr) {
        parent = curr;
        if (key < curr->key)
            curr = curr->left;
        else if (key > curr->key)
            curr = curr->right;
        else
            return root; 
    }

    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}


Node* minValueNode(Node* root) {
    Node* current = root;
    while (current && current->left)
        current = current->left;
    return current;
}

// Iterative Deletion
Node* deleteIterative(Node* root, int key) {
    Node* parent = nullptr;
    Node* curr = root;

    
    while (curr && curr->key != key) {
        parent = curr;
        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (!curr) return root; 

    
    if (!curr->left && !curr->right) {
        if (!parent) return nullptr; // Deleting root
        if (parent->left == curr) parent->left = nullptr;
        else parent->right = nullptr;
        delete curr;
    }
    
    else if (!curr->left || !curr->right) {
        Node* child = (curr->left) ? curr->left : curr->right;
        if (!parent) return child; // Deleting root
        if (parent->left == curr) parent->left = child;
        else parent->right = child;
        delete curr;
    }
    
    else {
        Node* successor = minValueNode(curr->right);
        int successorValue = successor->key;
        root = deleteIterative(root, successorValue);
        curr->key = successorValue;
    }

    return root;
}


void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n;
    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insertIterative(root, val);
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    int delKey;
    cout << "Enter key to delete: ";
    cin >> delKey;

    root = deleteIterative(root, delKey);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
