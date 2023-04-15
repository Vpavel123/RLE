#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

class LZW
{
public:
	LZW();
	~LZW();
	void LZW_Compress(std::string input_file_name, std::string output_file_nam);
	void LZW_Decompress(std::string input_file_name, std::string output_file_name);
	std::map<std::string, int> dictionary;
private:

};