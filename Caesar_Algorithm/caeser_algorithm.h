/**
 * @file caeser_alghorithm.h
 * this file defines the class  caeser_alghorithm
 */

#ifndef CAESER_ALGORITHM_H
#define CAESER_ALGORITHM_H

#include <fstream>

namespace caeser_algorithm {
	class Caeser_Algorithm {
	public:
		Caeser_Algorithm();
		~Caeser_Algorithm();

	public:
		void set_key();
		const int get_key() const;
		void do_encrypt();
		void do_dencrypt();

	private:
		void m_do_encrypt_left();
		void m_do_encrypt_right();// chem arel
		char m_is_uppercase_encrypt_left(const char& ch, const int& num);
		char m_is_lowercase_encrypt_left(const char& ch, const int& num);
		char m_is_number_encrypt_left(const char& ch, const int& num);
		char m_is_uppercase_encrypt_right(const char& ch, const int& num);
		char m_is_lowercase_encrypt_right(const char& ch, const int& num);
		char m_is_number_encrypt_right(const char& ch, const int& num);
		void m_do_dencrypt_left();
		void m_do_dencrypt_right();
		int m_key{};
		std::fstream fin;
		std::fstream fout;
	};
}
#endif //CAESER_ALGORITHM_H

