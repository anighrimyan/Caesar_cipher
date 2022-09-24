/**
 * @file caser_algorithm .cpp
 * this file defines some definitions of
 * the class Caser_Algorithm
 */

#include <iostream>
#include <string>
#include "caeser_algorithm.h"

caeser_algorithm::Caeser_Algorithm::Caeser_Algorithm() {
	std::string path1 = "encrypt";
	std::string path2 = "dencrypt";
	fin.open(path1 + ".txt");
	fout.open(path2 + ".txt");
	if (fin.is_open() && fout.is_open()) {
		std::cout << "The files are open. " << std::endl;
	}
	else {
		std::cout << "ERROR!!!!!" << std::endl;
	}
}

caeser_algorithm::Caeser_Algorithm::~Caeser_Algorithm() {
	fin.close();
	fout.close();
}

void caeser_algorithm::Caeser_Algorithm::set_key() {
	int key{};
	bool is_valid = true;
	do {
		std::cout << "Enter the key, that can be integer, positive number." << std::endl;
		std::cout << "key is: ";
		std::cin >> key;
		std::cout << std::endl;
		if (!(key > 0)) {
			is_valid = false;
		}
	} while (!is_valid);
	m_key = key;
}

const int caeser_algorithm::Caeser_Algorithm::get_key() const {
	return m_key;
}
 
/*code encrypt*/
 void caeser_algorithm::Caeser_Algorithm::do_encrypt() {
	 std::cout << " Dear user, if you want do the encrypt from right to left, pleas enter 0,if you want do the encrypt from left to right, pleas enter 1." << std::endl;
	 int choice;
	 std::cout << "choice: ";
	 std::cin >> choice;
	 if (choice == 0) {
		 m_do_encrypt_left();
	 }
	 else if (choice == 1) {
		 m_do_encrypt_right();
	 }
 }

 /*left encrypt*/
void caeser_algorithm::Caeser_Algorithm::m_do_encrypt_left() {
	std::string text{};
	std::string tmp{};
	char ch;
	if (fin.is_open() && fout.is_open()) {
		std::getline(fin, text);
		for (int i = 0; i < text.length(); ++i) {
			if (text[i] >= 'a' && text[i] <= 'z') {
				ch = text[i];
				tmp += m_is_lowercase_encrypt_left(ch, m_key);
			}
			else if (text[i] >= 'A' && text[i] <= 'Z') {
				ch = text[i];
				tmp += m_is_uppercase_encrypt_left(ch, m_key);
			}
			else if (text[i] >= '0' && text[i] <= '9') {
				ch = text[i];
				tmp += m_is_number_encrypt_left(ch, m_key);
			}
			else {
				tmp += text[i];
			}
		}
		fout << tmp;
		tmp = "";
	}
}


char caeser_algorithm::Caeser_Algorithm::m_is_uppercase_encrypt_left(const char& ch, const int& num) {
	char str{};
	if (ch - num < 'A') {
		str = (ch - num) + 26;
		return str;
	}
	else {
		str = (ch - num);
		return str;
	}
}

char caeser_algorithm::Caeser_Algorithm::m_is_lowercase_encrypt_left(const char& ch, const int& num) {
	char str{};
	if (ch - num < 'a') {
		str = (ch - num) + 26;
		return str;
	}
	else {
		str = (ch - num);
		return str;
	}
}

char caeser_algorithm::Caeser_Algorithm::m_is_number_encrypt_left(const char& ch, const int& num) {
	char str{};
	if (ch - num < '0') {
		str = (ch - num) + 10;
		return str;
	}
	else {
		str = (ch - num);
		return str;
	}
}


/*right encrypt*/
void caeser_algorithm::Caeser_Algorithm::m_do_encrypt_right() {
	std::string text{};
	std::string tmp{};
	char ch;
	if (fin.is_open() && fout.is_open()) {
		std::getline(fin, text);
		for (int i = 0; i < text.length(); ++i) {
			if (text[i] >= 'a' && text[i] <= 'z') {
				ch = text[i];
				tmp += m_is_lowercase_encrypt_right(ch, m_key);
			}
			else if (text[i] >= 'A' && text[i] <= 'Z') {
				ch = text[i];
				tmp += m_is_uppercase_encrypt_right(ch, m_key);
			}
			else if (text[i] >= '0' && text[i] <= '9') {
				ch = text[i];
				tmp += m_is_number_encrypt_right(ch, m_key);
			}
			else {
				tmp += text[i];
			}
		}
		fout << tmp;
		tmp = "";
	}
}

char caeser_algorithm::Caeser_Algorithm::m_is_uppercase_encrypt_right(const char& ch, const int& num) {
	char str{};
	if (ch + num > 'Z') {
		str = (ch + num) - 26;
		return str;
	}
	else {
		str = (ch + num);
		return str;
	}
}

char caeser_algorithm::Caeser_Algorithm::m_is_lowercase_encrypt_right(const char& ch, const int& num) {
	char str{};
	if (ch + num > 'z') {
		str = (ch + num) - 26;
		return str;
	}
	else {
		str = (ch + num);
		return str;
	}
}

char caeser_algorithm::Caeser_Algorithm::m_is_number_encrypt_right(const char& ch, const int& num) {
	char str{};
	if (ch + num > '9') {
		str = (ch + num) - 10;
		return str;
	}
	else {
		str = (ch + num);
		return str;
	}
}

/*code dencrypt*/
void caeser_algorithm::Caeser_Algorithm::do_dencrypt() {
	std::cout << " Dear user, if you want do the dencrypt from right to left, pleas enter 0,if you want do the dencrypt from left to right, pleas enter 1." << std::endl;
	int choice;
	std::cout << "choice: ";
	std::cin >> choice;
	if (choice == 0) {
		m_do_dencrypt_left();
	}
	else if (choice == 1) {
		m_do_dencrypt_right();
	}
}

/*left dencrypt*/
void caeser_algorithm::Caeser_Algorithm::m_do_dencrypt_left() {
	std::string text{};
	std::string tmp{};
	char ch;
	if (fin.is_open() && fout.is_open()) {
		std::getline(fout, text);
		for (int i = 0; i < text.length(); ++i) {
			if (text[i] >= 'a' && text[i] <= 'z') {
				ch = text[i];
				tmp += m_is_lowercase_encrypt_right(ch, m_key);
			}
			else if (text[i] >= 'A' && text[i] <= 'Z') {
				ch = text[i];
				tmp += m_is_uppercase_encrypt_right(ch, m_key);
			}
			else if (text[i] >= '0' && text[i] <= '9') {
				ch = text[i];
				tmp += m_is_number_encrypt_right(ch, m_key);
			}
			else {
				tmp += text[i];
			}
		}
		fin << tmp;
		tmp = "";
	}
}

void caeser_algorithm::Caeser_Algorithm::m_do_dencrypt_right() {
	std::string text{};
	std::string tmp{};
	char ch;
	if (fin.is_open() && fout.is_open()) {
		std::getline(fout, text);
		for (int i = 0; i < text.length(); ++i) {
			if (text[i] >= 'a' && text[i] <= 'z') {
				ch = text[i];
				tmp += m_is_lowercase_encrypt_left(ch, m_key);
			}
			else if (text[i] >= 'A' && text[i] <= 'Z') {
				ch = text[i];
				tmp += m_is_uppercase_encrypt_left(ch, m_key);
			}
			else if (text[i] >= '0' && text[i] <= '9') {
				ch = text[i];
				tmp += m_is_number_encrypt_left(ch, m_key);
			}
			else {
				tmp += text[i];
			}
		}
		fin << tmp;
		tmp = "";
	}
}

