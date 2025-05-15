#include <iostream>
using namespace std;
// Node structure
struct Node {
 int data;
 Node* left;
 Node* right;
 Node(int val) {
 data = val;
 left = right = nullptr; }
};
// Recursive Insertion
Node* insertRecursive(Node* root, int key) {
 if (root == nullptr) { return new Node(key); }
 if (key < root->data) { root->left = insertRecursive(root->left, key); } 
else { root->right = insertRecursive(root->right, key); }
 return root;
}
// Iterative Insertion
Node* insertIterative(Node* root, int key) {
 Node* newNode = new Node(key);
 if (root == nullptr) { return newNode; }
 Node* parent = nullptr;
 Node* curr = root;
 while (curr != nullptr) {
 parent = curr;
 if (key < curr->data) {
    curr = curr->left;
 } else {
 curr = curr->right;
 } }
 if (key < parent->data) {
 parent->left = newNode;
 } else {
 parent->right = newNode;
 }
 return root;}
// Inorder Traversal (for checking)
void inorder(Node* root) {
 if (root != nullptr) {
 inorder(root->left);
 cout << root->data << " ";
 inorder(root->right);
 } }
int main() {
 Node* root1 = nullptr; // For recursive
 Node* root2 = nullptr; // For iterative
 int arr[] = {50, 30, 10,55,2,70, 20, 40, 60, 80};
 int n = sizeof(arr) / sizeof(arr[0]);
 for (int i = 0; i < n; i++) {
 root1 = insertRecursive(root1, arr[i]);
 }
for (int i = 0; i < n; i++) {
 root2 = insertIterative(root2, arr[i]); 
 }
 cout << "Inorder Traversal (Recursive Insertion Tree): ";
 inorder(root1);
 cout << "\n";
 cout << "Inorder Traversal (Iterative Insertion Tree): ";
 inorder(root2);
 cout << "\n";
 return 0;
}
