#pragma once
#include <string>
#include <fstream>

class RLEencryption
{
public:
	RLEencryption();
	~RLEencryption();
	void RLE_Compress(std::string input_file_name, std::string output_file_name);
	void RLE_Decompress(std::string input_file_name, std::string output_file_name);
	std::string ReadFile(std::string input_file);
	std::string WriteFile(std::string input_file, std::string text);
private:

};