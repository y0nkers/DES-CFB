#include "DES.hpp"

int main(int argv, char** argc) {
	system("chcp 65001 > nul");
	setlocale(LC_ALL, "RUS");

	DES des("input\\key.txt", "input\\message.txt");
	//des.encrypt("output\\encrypted.txt");
	des.demonstration();

	system("pause");
	return 0;
}