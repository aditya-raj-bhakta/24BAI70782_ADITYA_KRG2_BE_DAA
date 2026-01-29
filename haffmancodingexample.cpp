#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    
    if (root->ch != '\0')
        codes[root->ch] = code;
    
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

string encode(string text, unordered_map<char, string>& codes) {
    string encoded = "";
    for (char c : text)
        encoded += codes[c];
    return encoded;
}

string decode(string encoded, Node* root) {
    string decoded = "";
    Node* current = root;
    
    for (char bit : encoded) {
        current = (bit == '0') ? current->left : current->right;
        
        if (current->ch != '\0') {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}

int main() {
    string text = "hello world";
    
    // Calculate frequency
    unordered_map<char, int> freq;
    for (char c : text)
        freq[c]++;
    
    cout << "Character Frequencies:\n";
    for (auto& p : freq)
        cout << p.first << ": " << p.second << "\n";
    
    // Build Huffman Tree
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freq)
        pq.push(new Node(p.first, p.second));
    
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    
    Node* root = pq.top();
    
    // Generate codes
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);
    
    cout << "\nHuffman Codes:\n";
    for (auto& p : codes)
        cout << p.first << ": " << p.second << "\n";
    
    // Encode
    string encoded = encode(text, codes);
    cout << "\nOriginal String: " << text << "\n";
    cout << "Encoded String: " << encoded << "\n";
    
    // Decode
    string decoded = decode(encoded, root);
    cout << "Decoded String: " << decoded << "\n";
    
    return 0;
}