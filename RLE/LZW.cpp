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
    // Открытие входного файла для чтения
    if (!input) {
        std::cerr << "Ошибка открытия файла " << input_file_name << std::endl;
        return;
    }

    // Открытие выходного файла для записи
    if (!output) {
        std::cerr << "Ошибка открытия файла " << output_file_name << std::endl;
        return;
    }

    // Инициализация словаря
    std::unordered_map<std::string, int> dictionary;
    for (int i = 0; i < 256; i++) {
        std::string s(1, (char)i);
        dictionary[s] = i;
    }

    // Инициализация переменных
    int code = 256;
    std::string current = "";
    char c;

    // Считывание символов из входного файла
    while (input.get(c)) {
        std::string next = current + c;
        if (dictionary.count(next)) {
            current = next;
        }
        else {
            output.write((char*)&dictionary[current], sizeof(int));
            dictionary[next] = code++;
            current = std::string(1, c);
        }
    }

    // Запись последнего кода
    if (!current.empty()) {
        output.write((char*)&dictionary[current], sizeof(int));
    }

    // Закрытие файлов
    input.close();
    output.close();
}

void LZW::LZW_Decompress(std::string input_file_name, std::string output_file_name)
{
    std::ifstream input_F(input_file_name, std::ios::binary);
    std::ofstream output_F(output_file_name, std::ios::binary);

    // Открытие входного файла для чтения
    if (!input_F) {
        std::cerr << "Ошибка открытия файла " << input_file_name << std::endl;
        return;
    }

    // Открытие выходного файла для записи
    if (!output_F) {
        std::cerr << "Ошибка открытия файла " << output_file_name << std::endl;
        return;
    }

    // Инициализация словаря
    std::unordered_map<int, std::string> dictionary;
    for (int i = 0; i < 256; i++) {
        std::string s(1, (char)i);
        dictionary[i] = s;
    }

    // Инициализация переменных
    int code = 256;
    int current_code, previous_code;
    char c;
    std::vector<char> output;

    // Считывание кодов из входного файла
    input_F.read((char*)&current_code, sizeof(int));
    output = std::vector<char>(dictionary[current_code].begin(), dictionary[current_code].end());
    output_F.write(output.data(), output.size());

    while (input_F.read((char*)&current_code, sizeof(int))) {
        if (dictionary.count(current_code)) {
            output = std::vector<char>(dictionary[current_code].begin(), dictionary[current_code].end());
            output_F.write(output.data(), output.size());
            c = output[0];
            dictionary[code++] = dictionary[previous_code] + c;
        }
        else {
            output = std::vector<char>(dictionary[previous_code].begin(), dictionary[previous_code].end());
            output.push_back(output[0]);
            output_F.write(output.data(), output.size());
            dictionary[code++] = dictionary[previous_code] + output[0];
        }
        previous_code = current_code;
    }

    // Закрытие файлов
    input_F.close();
    output_F.close();
}