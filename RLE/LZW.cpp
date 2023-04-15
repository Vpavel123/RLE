#include "LZW.h"
#include <unordered_map>
#include <vector>

LZW::LZW()
{
}

void LZW::LZW_Compress(std::string input_file_name, std::string output_file_name)
{
    std::ifstream input(input_file_name);
    std::ofstream output(output_file_name);

    if (!input || !output) {
        throw std::runtime_error("Cannot open files");
    }

    std::unordered_map<std::vector<unsigned char>, int> dict;
    for (int i = 0; i < 256; ++i) {
        dict[std::vector<unsigned char>(1, i)] = i;
    }
    int dict_size = 256;
    std::vector<unsigned char> s;
    unsigned char ch;
    while (input.read(reinterpret_cast<char*>(&ch), sizeof(ch))) {
        std::vector<unsigned char> s_new = s;
        s_new.push_back(ch);
        if (dict.count(s_new)) {
            s = s_new;
        }
        else {
            output.write(reinterpret_cast<const char*>(&dict[s]), sizeof(dict[s]));
            dict[s_new] = dict_size++;
            s = std::vector<unsigned char>(1, ch);
        }
    }
    if (!s.empty()) {
        output.write(reinterpret_cast<const char*>(&dict[s]), sizeof(dict[s]));
    }

    input.close();
    output.close();
}

void LZW::LZW_Decompress(std::string input_file_name, std::string output_file_name)
{
    std::ifstream input(input_file_name);
    std::ofstream output(output_file_name);
    if (!input || !output) {
        throw std::runtime_error("Cannot open files");
    }

    std::unordered_map<int, std::vector<unsigned char>> dict;
    for (int i = 0; i < 256; ++i) {
        dict[i] = std::vector<unsigned char>(1, i);
    }
    int dict_size = 256;

    int code;
    std::vector<unsigned char> s;
    unsigned char ch;
    while (input.read(reinterpret_cast<char*>(&code), sizeof(code))) {
        if (dict.count(code)) {
            s = dict[code];
        }
        else if (code == dict_size) {
            s.push_back(s[0]);
        }
        else {
            throw std::runtime_error("Bad compressed file");
        }
        output.write(reinterpret_cast<const char*>(&s[0]), s.size());
        if (!dict.count(dict_size - 1)) {
            s.push_back(s[0]);
            dict[dict_size++ - 1] = s;
            s.pop_back();
        }
    }
    input.close();
    output.close();


    //createDictionary();
    //std::string compressed((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    //input.close();
    //std::string decompressedFileName = input_file_name.substr(0, input_file_name.find(".")) + "_decompressed.txt";
    //std::string w = "";
    //int k;
    //for (char& c : compressed) {
    //    int i = c - '0';
    //    if (dictionary.count(w + std::to_string(i))) {
    //        w += std::to_string(i);
    //    }
    //    else {
    //        output << (char)dictionary[w];
    //        dictionary[w + std::to_string(i)] = dictionary.size();
    //        w = std::to_string(i);
    //    }
    //}
}