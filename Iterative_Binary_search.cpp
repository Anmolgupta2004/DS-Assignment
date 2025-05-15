#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* left;
 Node* right;
 Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Iterative insert
Node* insertIterative(Node* root, int key) {
 Node* newNode = new Node(key);
 if (root == nullptr) return newNode;
 Node* parent = nullptr;
 Node* current = root;
 while (current != nullptr) {
 parent = current;
 if (key < current->data)
 current = current->left;
 else if (key > current->data)
 current = current->right;
 else
 return root; // Duplicate key, do nothing
 }
 if (key < parent->data)
 parent->left = newNode;
 else parent->right = newNode;
 return root;
}
// Iterative search
bool searchIterative(Node* root, int key) {
 while (root != nullptr) {
 if (root->data == key)
 return true;
 else if (key < root->data)
 root = root->left;
 else
 root = root->right;
 }
 return false;
}
// In-order traversal
void inorder(Node* root) {
 if (root) {
 inorder(root->left);
 cout << root->data << " ";
 inorder(root->right);
 } }
int main() {
 Node* root = nullptr;
 // Insert elements
 root = insertIterative(root, 50);
 insertIterative(root, 30);
 insertIterative(root, 70);
 insertIterative(root, 20);
 insertIterative(root, 40);
 insertIterative(root, 60);
 insertIterative(root, 80);
 cout << "In-order Traversal (Iterative BST): ";
 inorder(root);
 cout << endl;
 cout << "Search 40: " << (searchIterative(root, 40) ? "Found" : "Not Found") << endl;
 cout << "Search 50: " << (searchIterative(root, 50) ? "Found" : "Not Found") << endl;
 return 0;
}
