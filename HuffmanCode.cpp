#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;


struct node {
    char ch;
    int freq;
    node* left;
    node* right;
};


node* getNode(char ch, int freq, node* left, node* right) {
    node* newNode = new node();
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}


struct compare {
    bool operator()(node* l, node* r) {
        return l->freq > r->freq; 
    }
};


void encode(node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == NULL) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}


void decode(node* root, int &top_index, string str) {
    if (root == NULL) return;

    if (!root->left && !root->right) {
        cout << root->ch;
        return;
    }

    top_index++;
    if (str[top_index] == '0')
        decode(root->left, top_index, str);
    else
        decode(root->right, top_index, str);
}


void buildHuffmanTree(string text) {
   
    unordered_map<char, int> mp;
    for (char ch : text) {
        mp[ch]++;
    }

 
    priority_queue<node*, vector<node*>, compare> pq;
    for (auto pair : mp) {
        pq.push(getNode(pair.first, pair.second, NULL, NULL));
    }

    while (pq.size() != 1) {
        node* left = pq.top(); 
        pq.pop();
        node* right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    node* root = pq.top();
 unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    cout << "\nOriginal String: " << text << '\n';

    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded String:\n" << str << "\n";
  
    int top_index = -1;
    cout << "\nDecoded String:\n";
    while (top_index < (int)str.size() - 1) {
        decode(root, top_index, str);
    }
    cout << "\n";
}

int main() {
    string text = "";
    cin>>text;
    
    buildHuffmanTree(text);
    return 0;
}