#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>

class Huffman
{
public:
    // Структура узла дерева Хаффмана
    struct Node {
        char ch;
        int freq;
        Node* left;
        Node* right;
    };

    // Создание нового узла дерева Хаффмана
    Node* newNode(char ch, int freq, Node* left, Node* right) {
        Node* node = new Node;
        node->ch = ch;
        node->freq = freq;
        node->left = left;
        node->right = right;
        return node;
    }

    // Сравнение узлов дерева Хаффмана по частоте
    struct compare {
        bool operator()(Node* l, Node* r) {
            return l->freq > r->freq;
        }
    };

    // Построение дерева Хаффмана на основе частоты символов
    Node* buildHuffmanTree(std::unordered_map<char, int>& freq) {
        std::priority_queue<Node*, std::vector<Node*>, compare> pq;

        for (auto pair : freq) {
            pq.push(newNode(pair.first, pair.second, nullptr, nullptr));
        }

        while (pq.size() != 1) {
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();
            int sum = left->freq + right->freq;
            pq.push(newNode('\0', sum, left, right));
        }

        return pq.top();
    }

    // Создание таблицы кодирования символов на основе дерева Хаффмана
    void encode(Node* root, std::string code, std::unordered_map<char, std::string>& huffmanCode) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            huffmanCode[root->ch] = code;
        }

        encode(root->left, code + "0", huffmanCode);
        encode(root->right, code + "1", huffmanCode);
    }

    // Запись таблицы кодирования в сжатый файл
    void writeEncodingTable(std::unordered_map<char, std::string>& huffmanCode, std::ofstream& out) {
        for (auto pair : huffmanCode) {
            out << pair.first << " " << pair.second << std::endl;
        }
    }

    // Запись закодированных данных в сжатый файл
    void writeEncodedData(std::string& data, std::unordered_map<char, std::string>& huffmanCode, std::ofstream& out) {
        std::string encodedData = "";
        for (char c : data) {
            encodedData += huffmanCode[c];
        }

        int padding = 8 - encodedData.length() % 8;
        for (int i = 0; i < padding; i++) {
            encodedData += "0";
        }

        out << padding << std::endl;

        for (int i = 0; i < encodedData.length(); i += 8) {
            std::string byte = encodedData.substr(i, 8);
            out << (char)std::bitset<8>(byte).to_ulong();
        }
    }

    // Сжатие файла методом Хаффмана
    void compressFile(std::string inputFile, std::string outputFile) {
        std::ifstream in(inputFile, std::ios::binary);
        std::ofstream out(outputFile, std::ios::binary);

        std::unordered_map<char, int> freq;
        char c;
        while (in.get(c)) {
            freq[c]++;
        }

        Node* root = buildHuffmanTree(freq);

        std::unordered_map<char, std::string> huffmanCode;
        encode(root, "", huffmanCode);

        writeEncodingTable(huffmanCode, out);

        in.clear();
        in.seekg(0, std::ios::beg);

        std::string data = "";
        while (in.get(c)) {
            data += c;
        }

        writeEncodedData(data, huffmanCode, out);

        in.close();
        out.close();
    }

    void decompressFile(std::string inputFile, std::string outputFile) {
        // Чтение таблицы кодирования из входного файла
        std::ifstream input(inputFile, std::ios::binary);
        std::unordered_map& lt; std::string, char& gt; decodingTable;
        std::string line;
        while (getline(input, line)) {
            char character = line[0];
            std::string code = line.substr(1);
            decodingTable[code] = character;
        }
        input.close();
        // Чтение закодированного текста из входного файла
        std::string encodedText = &quot;&quot;;
        std::bitset& lt;8 & gt; bits;
        input.open(inputFile, std::ios::binary);
        input.seekg(0, std::ios::end);
        int fileSize = input.tellg();
        input.seekg(fileSize - 1, std::ios::beg);
        char lastByte = input.get();
        input.seekg(0, std::ios::beg);
        while (input.get(bits)) {
            encodedText += bits.to_string();
        }
        encodedText = encodedText.substr(0, encodedText.size() - 8) + std::bitset & lt;8 & gt;(lastByte).to_string();
        // Раскодирование текста с использованием таблицы декодирования
        std::string text = &quot;&quot;;
        std::string code = &quot;&quot;;
        for (char c : encodedText) {
            code += c;
            if (decodingTable.find(code) != decodingTable.end()) {
                text += decodingTable[code];
                code = &quot;&quot;;
            }
        }
        // Запись раскодированного текста в выходной файл
        std::ofstream output(outputFile, std::ios::binary);
        output& lt;&lt; text;
        output.close();
    }
};


//int main(int argc, char* argv[])
//{
//    ////// считаем частоты символов   
//
//
//    ///// считывание из файла output.txt и преобразование обратно
//
//    std::ifstream F("output.txt", std::ios::in | std::ios::binary);
//
//    setlocale(LC_ALL, "Russian"); // чтоб русские символы отображались в командной строке
//
//    Node* p = root;
//    count = 0; char byte;
//    byte = F.get();
//    while (!F.eof())
//    {
//        bool b = byte & (1 << (7 - count));
//        if (b) p = p->right; else p = p->left;
//        if (p->left == NULL && p->right == NULL) { std::cout << p->c; p = root; }
//        count++;
//        if (count == 8) { count = 0; byte = F.get(); }
//    }
//
//    F.close();
//
//    return 0;
//}
