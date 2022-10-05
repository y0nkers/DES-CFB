#include "DES.hpp"

int main(int argv, char** argc) {
	system("chcp 65001 > nul");

	DES des("input\\key.txt", "input\\message.txt");
	des.encrypt("output\\encrypted.txt");

	system("pause");
	return 0;
}