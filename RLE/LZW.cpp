#include "LZW.h"

LZW::LZW()
{
}

void LZW::LZW_Compress(std::string input_file_name, std::string output_file_name)
{
    std::ifstream input(input_file_name);
    std::ofstream output(output_file_name);

    std::map<std::string, int> dictionary;
    for (int i = 0; i < 256; i++) {
        std::string s = "";
        s += char(i);
        dictionary[s] = i;
    }
    int dictSize = 256;
    std::string w = "";
    char c;
    while (input.get(c)) {
        std::string wc = w + c;
        if (dictionary.count(wc)) {
            w = wc;
        }
        else {
            output.write((char*)&dictionary[w], sizeof(int));
            dictionary[wc] = dictSize++;
            w = std::string(1, c);
        }
    }
    if (!w.empty()) {
        output.write((char*)&dictionary[w], sizeof(int));
    }
}

void LZW::LZW_Decompress(std::string input_file_name, std::string output_file_name)
{
    std::ifstream input(input_file_name);
    std::ofstream output(output_file_name);
    std::vector<std::string> dictionary;
    for (int i = 0; i < 256; i++) {
        std::string s = "";
        s += char(i);
        dictionary.push_back(s);
    }
    int dictSize = 256;
    int oldCode = -1;
    int newCode;
    std::string str;
    while (input.read((char*)&newCode, sizeof(int))) {
        if (newCode >= dictSize) {
            str = dictionary[oldCode] + dictionary[oldCode][0];
        }
        else {
            str = dictionary[newCode];
        }
        output << str;
        if (oldCode != -1) {
            dictionary.push_back(dictionary[oldCode] + str[0]);
            dictSize++;
        }
        oldCode = newCode;
    }
}