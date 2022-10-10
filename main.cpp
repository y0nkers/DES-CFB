#include "DES.hpp"

int main(int argv, char** argc) {
	system("chcp 65001 > nul");
	setlocale(LC_ALL, "RUS");
	
	//DES::demonstration();
	
	int choice = 0;
	
	do {
		std::cout << "\nChoose an operation:\n1. Encrypt message.\n2. Decrypt message.\n3. Generate Key\n4. Generate Initialization Vector\n5. Exit program.\nYour choice: ";
		std::cin >> choice;

		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Your choice: ";
			std::cin >> choice;
		}

		switch (choice) {
		case 1:
			{
				DES des("input\\key.txt", "output\\IV.txt");
				des.process("input\\message.txt", "output\\encrypted.txt", Mode::ENCRYPTION);
			}
			break;
		case 2:
			{
				DES des("input\\key.txt", "output\\IV.txt");
				des.process("output\\encrypted.txt", "output\\decrypted.txt", Mode::DECRYPTION);
			}
			break;
		case 3:
			DES::generateBytes("input\\key.txt", true);
			break;
		case 4:
			DES::generateBytes("output\\IV.txt", false);
			break;
		default: 
			break;
		}
	} while (choice != 5);

	system("pause");
	return 0;
}