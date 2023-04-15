#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>

// Структура узла дерева Хаффмана
struct Node {
    char data;  // символ
    int freq;   // частота символа
    Node* left, * right; // левый и правый потомки

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Сравнение узлов по их частоте
struct CompareNodes {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Построение дерева Хаффмана на основе частот символов
Node* buildHuffmanTree(const std::unordered_map<char, int>& freqMap) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNodes> pq;

    // Создание начальных узлов-листьев для каждого символа и добавление их в очередь
    for (const auto& kv : freqMap) {
        pq.push(new Node(kv.first, kv.second));
    }

    // Слияние узлов до тех пор, пока не останется один корневой узел дерева
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('$', left->freq + right->freq); // Создание нового узла-родителя
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top(); // Возврат корневого узла дерева Хаффмана
}

// Рекурсивное построение таблицы кодов Хаффмана
void buildHuffmanCodes(Node* root, std::string code, std::unordered_map<char, std::string>& codesMap) {
    if (!root) return;

    if (root->data != '$') {
        codesMap[root->data] = code;
    }

    buildHuffmanCodes(root->left, code + "0", codesMap);
    buildHuffmanCodes(root->right, code + "1", codesMap);
}

// Сжатие файла методом Хаффмана
void compressFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inFile(inputFileName, std::ios::in | std::ios::binary);
    if (!inFile.is_open()) {
        std::cout << "Error: Could not open file " << inputFileName << std::endl;
        return;
    }

    // Подсчет частот символов в файле
    std::unordered_map<char, int> freqMap;
    int fileSizeInBytes = 0;
    char ch;
    while (inFile.get(ch)) {
        freqMap[ch]++;
        fileSizeInBytes++;
    }
    inFile.close();

    // Построение дерева Хаффмана на основе частот символов
    Node* root = buildHuffmanTree(freqMap);

    // Построение таблицы кодов Хаффмана для каждого символа
    std::unordered_map<char, std::string> codesMap;
    buildHuffmanCodes(root, "", codesMap);

    // Запись сжатых данных в выходной файл
    std::ofstream outFile(outputFileName, std::ios::out | std::ios::binary);
    if (!outFile.is_open()) {
        std::cout << "Error: Could not open file " << outputFileName << std::endl;
        return;
    }

    // Запись числа символов и их частот в выходной файл
    int numSymbols = freqMap.size();
    outFile.write(reinterpret_cast<char*>(&numSymbols), sizeof(numSymbols));
    for (const auto& kv : freqMap);
}

// Расжатие файла, используя код Хаффмана для каждого символа
void decompressFile(const std::string & compressedFileName, const std::string & decompressedFileName) {
    std::ifstream compressedFile(compressedFileName, std::ios::in | std::ios::binary);
    if (!compressedFile.is_open()) {
        std::cout << "Error: Could not open file " << compressedFileName << std::endl;
        return;
    }

    // Чтение таблицы частот из сжатого файла
    int numSymbols;
    compressedFile.read(reinterpret_cast<char*>(&numSymbols), sizeof(numSymbols));
    std::unordered_map<char, int> freqMap;
    for (int i = 0; i < numSymbols; i++) {
        char ch;
        int freq;
        compressedFile.read(reinterpret_cast<char*>(&ch), sizeof(ch));
        compressedFile.read(reinterpret_cast<char*>(&freq), sizeof(freq));
        freqMap[ch] = freq;
    }

    // Построение дерева Хаффмана на основе таблицы частот
    Node* root = buildHuffmanTree(freqMap);

    // Чтение закодированных данных из сжатого файла
    std::ofstream decompressedFile(decompressedFileName, std::ios::out | std::ios::binary);
    if (!decompressedFile.is_open()) {
        std::cout << "Error: Could not open file " << decompressedFileName << std::endl;
        return;
    }
    Node* curr = root; // текущий узел в дереве
    char bit;
    while (compressedFile.read(&bit, 1)) {
        if (bit == '0') { // если текущий бит 0, идем влево в дереве
            curr = curr->left;
        }
        else { // иначе, идем вправо
            curr = curr->right;
        }
        if (curr->left == nullptr && curr->right == nullptr);
    } // если текущий узел-лист, то это и есть раскодированный символ
}