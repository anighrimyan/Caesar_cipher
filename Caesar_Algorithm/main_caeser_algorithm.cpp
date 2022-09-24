#include <iostream>
#include "caeser_algorithm.h"

int main() {
	caeser_algorithm::Caeser_Algorithm obj_caeser_algorithm;
	obj_caeser_algorithm.set_key();
	std::cout << " Dear user, if you want do the encrypt , pleas enter 0,if you want do the dencrypt, pleas enter 1." << std::endl;
	int choice;
	std::cout << "choice: ";
	std::cin >> choice;
	if (choice == 0) {
		obj_caeser_algorithm.do_encrypt();
	}
	else {
		obj_caeser_algorithm.do_dencrypt();
	}
	std::cout << "Thank you!!!!";
	return 0;
}