#include "helpers.hpp"

/* Reads the entire contents of a file and writes it to a string */
std::string getStringFromFile(std::string filename) {
	std::ifstream file(filename);
	std::stringstream buffer;
	std::string str = "";

	if (!file.is_open()) {
		std::cout << "An error occurred while opening " << filename << std::endl;
		exit(-1);
	}

	buffer << file.rdbuf();
	str = buffer.str();
	if (str == "") std::cout << "The specified file " << filename << " is empty" << std::endl;
	file.close();
	
	return str;
}

/* Reads the contents of a file in bytes and writes them to a vector */
std::vector<char> readBytesFromFile(std::string filename) {
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	if (!file.is_open()) {
		std::cout << "An error occurred while opening " << filename << std::endl;
		exit(-1);
	}

	std::ifstream::pos_type length = file.tellg();
	std::vector<char> bytes(length);
	file.seekg(0, std::ios::beg);
	file.read(&bytes[0], length);

	return bytes;
}
