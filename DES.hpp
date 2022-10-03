#ifndef DES_HPP
#define DES_HPP

#include "helpers.hpp"

// Key size - 56 bits, Block size - 64 bits
class DES {
private:
	std::bitset<56> key;
	std::vector<char> message; // message in bytes

	void leftShift(std::bitset<28>& bits, unsigned count);
	std::bitset<48> generateSubKey(std::bitset<28>& block_C, std::bitset<28>& block_D, unsigned round);
	std::bitset<32> feistel(std::bitset<32>& block_R, std::bitset<48> subkey);
public:
	DES(std::string key_filename, std::string message_filename);
	void encrypt();
	void decrypt();
};

#endif // !DES_HPP
