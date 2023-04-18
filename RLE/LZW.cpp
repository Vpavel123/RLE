#include "LZW.h"
#include <unordered_map>
#include <vector>

LZW::LZW()
{
}

void LZW::LZW_Compress(std::string input_file_name, std::string output_file_name)
{
    std::ifstream input(input_file_name, std::ios::binary);
    std::ofstream output(output_file_name, std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения" << std::endl;
        return;
    }

    // Открытие файла для записи
    if (!output.is_open()) {
        std::cerr << "Ошибка открытия файла для записи" << std::endl;
        return;
    }

    // Инициализация словаря
    std::unordered_map<std::string, int> dictionary;
    for (int i = 0; i < 256; i++) {
        std::string s(1, (char)i);
        dictionary[s] = i;
    }

    // Чтение входного файла и сжатие данных
    std::string currentString;
    char c;
    std::vector<int> compressedData;
    while (input.get(c)) {
        std::string newString = currentString + c;
        if (dictionary.count(newString)) {
            currentString = newString;
        }
        else {
            compressedData.push_back(dictionary[currentString]);
            dictionary[newString] = dictionary.size();
            currentString = std::string(1, c);
        }
    }
    if (!currentString.empty()) {
        compressedData.push_back(dictionary[currentString]);
    }

    // Запись сжатых данных в выходной файл
    for (int i : compressedData) {
        output.write((char*)&i, sizeof(int));
    }

    input.close();
    output.close();
}

void LZW::LZW_Decompress(std::string input_file_name, std::string output_file_name)
{
    std::ifstream input(input_file_name, std::ios::binary);
    std::ofstream output(output_file_name, std::ios::binary);

    std::unordered_map<int, std::vector<char>> dictionary;
    for (int i = 0; i < 256; i++) {
        dictionary[i] = { char(i) };
    }

    int code = 256;
    int currentCode;
    std::vector<char> currentString;
    input.read(reinterpret_cast<char*>(&currentCode), sizeof(currentCode));
    currentString = dictionary[currentCode];
    output.write(currentString.data(), currentString.size());

    while (input.read(reinterpret_cast<char*>(&currentCode), sizeof(currentCode))) {
        if (dictionary.find(currentCode) == dictionary.end()) {
            dictionary[currentCode] = currentString;
            currentString.push_back(currentString[0]);
        }
        else {
            currentString = dictionary[currentCode];
        }
        output.write(currentString.data(), currentString.size());
        dictionary[code] = dictionary[currentCode];
        code++;
    }

    input.close();
    output.close();
}