#include "DES.hpp"

int initial_message_permutation[64] = {
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17,  9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7
};

DES::DES(std::string key_filename, std::string message_filename) {
	std::string key = getStringFromFile(key_filename);
	if (key.size() != 56) {
		std::cout << "ERROR: Wrong key size (must be 56 ones or zeros)" << std::endl;
		exit(-1);
	}

	try { this->key = std::bitset<56>(key); }
	catch (std::exception& e) {
		std::cout << "Error: invalid key characters" << std::endl;
		exit(-1);
	}

	message = readBytesFromFile(message_filename);
	int remain_bytes = 8 - (message.size() % 8); // How many bytes must be added so that the message length is a multiple of 8 bytes
	// if message length is already a multiple of 8 bytes
	if (remain_bytes != 8) {
		std::vector<char> tmp(remain_bytes, ' ');
		message.insert(message.end(), tmp.begin(), tmp.end());
	}

	//std::bitset<8> char1(message[0]);
	//std::cout << char1 << std::endl;
	//unsigned long i = char1.to_ulong();
	//unsigned char c = static_cast<unsigned char>(i);
	//std::cout << c << std::endl;
}

void DES::encrypt() {
	for (int i = 0; i < message.size(); i += 8) {
		// Work with the message in the form of blocks of 8 bytes
		std::vector<char> message_block(message.cbegin() + i, message.cbegin() + i + 8);

		// Convert message block from 8 chars to 64 bits using string
		std::string block;
		for (auto c : message_block) block += std::bitset<8>(c).to_string();
		std::bitset<64> block_bits(block);

		// Initial message block permutation
		std::bitset<64> permutated_bits;
		for (int j = 0; j < 64; j++) permutated_bits[j] = block_bits[initial_message_permutation[j] - 1];

		// next - 16 Feistel's rounds of encryption
		// 16 keys generation with shifts and permutations
		// final permutation of message
	}
}

void DES::decrypt() {

}
