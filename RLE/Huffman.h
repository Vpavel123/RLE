#pragma once
//#include <iostream>
//#include <fstream>
//#include <queue>
//#include <unordered_map>
//#include <bitset>
//
//// Структура узла дерева Хаффмана
//struct Node {
//    char ch;
//    int freq;
//    Node* left;
//    Node* right;
//    Node(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
//        this->ch = ch;
//        this->freq = freq;
//        this->left = left;
//        this->right = right;
//    }
//};
//
//// Сравнение узлов дерева Хаффмана по частоте
//struct Compare {
//    bool operator()(Node* a, Node* b) {
//        return a->freq > b->freq;
//    }
//};
//
//
//// Построение дерева Хаффмана
//Node* buildHuffmanTree(std::unordered_map<char, int>& freq) {
//    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
//    for (auto& p : freq) {
//        pq.push(new Node(p.first, p.second));
//    }
//    while (pq.size() > 1) {
//        Node* left = pq.top(); pq.pop();
//        Node* right = pq.top(); pq.pop();
//        Node* parent = new Node('\0', left->freq + right->freq, left, right);
//        pq.push(parent);
//    }
//    return pq.top();
//}
//
//// Создание таблицы кодирования
//void createEncodingTable(Node* root, std::string code, std::unordered_map<char, std::string>& table) {
//    if (!root) return;
//    if (!root->left && !root->right) {
//        table[root->ch] = code;
//    }
//    createEncodingTable(root->left, code + "0", table);
//    createEncodingTable(root->right, code + "1", table);
//}
//
//// Сжатие файла методом Хаффмана
//void compressFile(std::string inputFile, std::string outputFile) {
//    // Считываем исходный файл и подсчитываем частоту встречаемости каждого символа в нем
//    std::unordered_map<char, int> freq;
//    std::ifstream fin(inputFile);
//    char ch;
//    while (fin.get(ch)) {
//        freq[ch]++;
//    }
//    fin.close();
//
//    // Построение дерева Хаффмана
//    Node* root = buildHuffmanTree(freq);
//
//    // Создание таблицы кодирования
//    std::unordered_map<char, std::string> encodingTable;
//    createEncodingTable(root, "", encodingTable);
//
//    // Записываем таблицу кодирования в сжатый файл
//    std::ofstream fout(outputFile);
//    for (auto& p : encodingTable) {
//        fout << p.first << " " << p.second << std::endl;
//    }
//    fout << std::endl;
//
//    // Считываем исходный файл еще раз и заменяем каждый символ на его код из таблицы кодирования
//    fin.open(inputFile);
//    std::string encodedStr = "";
//    while (fin.get(ch)) {
//        encodedStr += encodingTable[ch];
//    }
//    fin.close();
//
//    // Записываем закодированный файл в сжатый файл
//    int padding = 8 - encodedStr.length() % 8;
//    for (int i = 0; i < padding; i++) {
//        encodedStr += "0";
//    }
//    fout << padding << std::endl;
//    for (int i = 0; i < encodedStr.length(); i += 8) {
//        std::string byteStr = encodedStr.substr(i, 8);
//        char byte = std::bitset<8>(byteStr).to_ulong();
//        fout.put(byte);
//    }
//    fout.close();
//}