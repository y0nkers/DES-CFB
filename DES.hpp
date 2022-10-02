#ifndef DES_HPP
#define DES_HPP

#include "helpers.hpp"

// Key size - 56 bits, Block size - 64 bits
class DES {
private:
	std::bitset<56> key;
	std::vector<char> message; // message in bytes
public:
	DES(std::string key_filename, std::string message_filename);
	void encrypt();
	void decrypt();
};

#endif // !DES_HPP
