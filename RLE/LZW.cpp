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
    std::string textinput;
    getline(input, textinput);
    std::unordered_map<std::string, int> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[std::string(1, char(i))] = i;
    }
    
    std::string currentString;
    for (unsigned char c : textinput) {
        std::string newString = currentString + std::to_string(c);
        if (dictionary.count(newString)) {
            currentString = newString;
        }
        else {
            result.push_back(dictionary[currentString]);
            dictionary[newString] = dictionary.size();
            currentString = std::string(1, c);
        }
    }
    if (!currentString.empty()) {
        result.push_back(dictionary[currentString]);
        if (output.is_open())
        {
            output << dictionary[currentString];
        }
    }

    input.close();
    output.close();
}

void LZW::LZW_Decompress(std::string input_file_name, std::string output_file_name)
{
    std::vector<int> inputs = result;
    std::ifstream input(input_file_name);
    std::ofstream output(output_file_name);
    std::unordered_map<int, std::string> dictionary;

    std::string textinput;
    getline(input, textinput);

    for (int i = 0; i < 256; ++i) {
        dictionary[i] = std::string(1, char(i));
    }

    std::string currentString = dictionary[inputs[0]];
    std::string results = currentString;
    for (int i = 1; i < inputs.size(); ++i) {
        int code = inputs[i];
        std::string newString;
        if (dictionary.count(code)) {
            newString = dictionary[code];
        }
        else if (code == dictionary.size()) {
            newString = currentString + currentString[0];
        }
        else {
            throw std::invalid_argument("Invalid LZW code.");
        }

        results += newString;
        dictionary[dictionary.size()] = currentString + newString[0];
        currentString = newString;
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