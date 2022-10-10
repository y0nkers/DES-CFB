#ifndef DES_HPP
#define DES_HPP

#include "helpers.hpp"

enum Mode {
	ENCRYPTION = 1,
	DECRYPTION = 2
};

// Key size - 56 (extra 8 for error detection) bits, Block size - 64 bits
class DES {
private:
	std::bitset<64> key;
	std::bitset<64> IV;

	static void leftShift(std::bitset<28>& bits, unsigned count);
	std::bitset<48> generateSubKey(std::bitset<28>& block_C, std::bitset<28>& block_D, unsigned round);
	std::bitset<32> feistel(std::bitset<32>& block_R, std::bitset<48> subkey);
public:
	DES(std::string key_filename, std::string IV_filename = "");
	void process(std::string message_filename, std::string output_filename, Mode mode);
	static void demonstration();
	static std::bitset<64> generateBytes(std::string output_filename, bool generateKey);
};

#endif // !DES_HPP
