
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
using namespace std;

// Create a node for the Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Minimum frequency gets highest priority
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Generate Huffman codes
void makeCodes(Node* root, string code,
               map<char, string>& codes) {
    if (root == nullptr)
        return;

    // If leaf node, save its code
    if (root->left == nullptr &&
        root->right == nullptr) {
        if (code == "")
            code = "0";

        codes[root->ch] = code;
        return;
    }

    makeCodes(root->left, code + "0", codes);
    makeCodes(root->right, code + "1", codes);
}

int main() {
    string text;

    cout << "Enter text: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Please enter some text.\n";
        return 0;
    }

    // Count frequency of each character
    map<char, int> frequency;

    for (char ch : text) {
        frequency[ch]++;
    }

    // Create a min-priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto item : frequency) {
        pq.push(new Node(item.first, item.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node(
            '\0', left->freq + right->freq
        );

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    // Generate codes for each character
    map<char, string> codes;
    makeCodes(root, "", codes);

    cout << "\nCharacter frequencies and codes:\n";

    for (auto item : frequency) {
        char ch = item.first;

        if (ch == ' ')
            cout << "space";
        else
            cout << ch;

        cout << "  Frequency: " << item.second
             << "  Code: " << codes[ch] << "\n";
    }

    // Encode the original text
    string encoded = "";

    for (char ch : text) {
        encoded += codes[ch];
    }

    cout << "\nOriginal text: " << text << "\n";
    cout << "Encoded text: " << encoded << "\n";

    cout << "Original size: "
         << text.size() * 8 << " bits\n";

    cout << "Encoded size: "
         << encoded.size() << " bits\n";

    return 0;
}
