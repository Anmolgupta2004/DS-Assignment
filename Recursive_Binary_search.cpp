#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* left;
 Node* right;
 Node(int val) : data(val), left(nullptr), right(nullptr) {} };
// Recursive insert
Node* insertRecursive(Node* root, int key) {
 if (root == nullptr) return new Node(key);
 if (key < root->data)
 root->left = insertRecursive(root->left, key);
 else if (key > root->data)
 root->right = insertRecursive(root->right, key);
 return root; }
// Recursive search
bool searchRecursive(Node* root, int key) {
 if (root == nullptr) return false;
 if (root->data == key) return true;
 else if (key < root->data) return searchRecursive(root->left, key);
 else return searchRecursive(root->right, key);
}
// • In-order traversal
void inorder(Node* root) {
 if (root) { inorder(root->left);
 cout << root->data << " ";
 inorder(root->right); } }
int main() {
    Node* root = nullptr;
 // Insert elements
 root = insertRecursive(root, 50);
 insertRecursive(root, 30);
 insertRecursive(root, 65);
 insertRecursive(root, 23);
 insertRecursive(root, 98);
 insertRecursive(root, 33);
 insertRecursive(root, 100);
 cout << "In-order Traversal (Recursive BST): ";
 inorder(root);
 cout << endl;
 cout << "Search 98: " << (searchRecursive(root, 98) ? "Found" : "Not Found") << endl;
 cout << "Search 25: " << (searchRecursive(root, 25) ? "Found" : "Not Found") << endl;
 return 0;
}
