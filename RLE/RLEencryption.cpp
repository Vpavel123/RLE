#include "RLEencryption.h"
using namespace std;

RLEencryption::RLEencryption()
{
}

void RLEencryption::RLE_Compress(std::string input_file_name, std::string output_file_name)
{
    ifstream input_file(input_file_name);
    ofstream output_file(output_file_name);

    char prev_char = '\0';
    int count = 0;
    char current_char;
    while (input_file.get(current_char)) {
        if (current_char != prev_char) {
            if (count > 0) {
                output_file << count << prev_char;
            }
            prev_char = current_char;
            count = 1;
        }
        else {
            count++;
        }
    }
    if (count > 0) {
        output_file << count << prev_char;
    }

    input_file.close();
    output_file.close();
}

void RLEencryption::RLE_Decompress(string input_file_name, string output_file_name)
{
    ifstream input_file(input_file_name);
    ofstream output_file(output_file_name);

    int count;
    char current_char;
    while (input_file >> count >> current_char) {
        for (int i = 0; i < count; i++) {
            output_file << current_char;
        }
    }

    input_file.close();
    output_file.close();
}

std::string RLEencryption::ReadFile(std::string input_file)
{
    std::string line;
    ifstream in(input_file, ios::binary);
    if (in.is_open())
    {
        getline(in, line);
    }
    in.close();     // закрываем файл
    return line;
}

std::string RLEencryption::WriteFile(std::string input_file, std::string text)
{
    ofstream myfile;
    myfile.open(input_file);
    if (myfile.is_open())
    {
        myfile << text;
        myfile.close();
    }
    return text;
}
