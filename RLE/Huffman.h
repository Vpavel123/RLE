#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>

//class Huffman{
//public:
//struct Node {
//    char ch;
//    int freq;
//    Node* left, * right;
//
//    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
//
//    bool isLeaf() const { return left == nullptr && right == nullptr; }
//};
//
//struct comp {
//    bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
//};
//
//void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode) {
//    if (root == nullptr) return;
//
//    if (root->isLeaf()) {
//        huffmanCode[root->ch] = str;
//    }
//
//    encode(root->left, str + "0", huffmanCode);
//    encode(root->right, str + "1", huffmanCode);
//}
//
//std::unordered_map<char, std::string> buildHuffmanTree(std::string text) {
//    std::unordered_map<char, int> freq;
//    for (char ch : text) {
//        freq[ch]++;
//    }
//
//    std::priority_queue<Node*, std::vector<Node*>, comp> pq;
//
//    for (auto pair : freq) {
//        pq.push(new Node(pair.first, pair.second));
//    }
//
//    while (pq.size() != 1) {
//        Node* left = pq.top();
//        pq.pop();
//        Node* right = pq.top();
//        pq.pop();
//
//        int sum = left->freq + right->freq;
//        Node* parent = new Node('\0', sum);
//        parent->left = left;
//        parent->right = right;
//
//        pq.push(parent);
//    }
//
//    std::unordered_map<char, std::string> huffmanCode;
//    encode(pq.top(), "", huffmanCode);
//
//    return huffmanCode;
//}
//
//std::string compressString(std::string text, std::unordered_map<char, std::string> huffmanCode) {
//    std::string compressedTxt = "";
//    for (char ch : text) {
//        compressedTxt += huffmanCode[ch];
//    }
//    return compressedTxt;
//}
//
//void compressFile(std::string input_text, std::string output_text)
//{
//    std::ifstream f(input_text, std::ios::binary);
//    std::string line;
//    if (f.is_open())
//    {
//        while (std::getline(f, line))
//        {
//            std::cout << line << std::endl;
//        }
//    }
//    f.close();     // закрываем файл
//
//    std::unordered_map<char, std::string> huffmanCode = buildHuffmanTree(line);
//    std::string compressedText = compressString(line, huffmanCode);
//
//    std::ofstream out(output_text, std::ios::binary);
//    if (out.is_open())
//    {
//        out << line << std::endl;
//    }
//    out.close();
//
//    std::cout << "The original text is: " << line << std::endl;
//    std::cout << "The compressed text is: " << compressedText << std::endl;
//}
//};