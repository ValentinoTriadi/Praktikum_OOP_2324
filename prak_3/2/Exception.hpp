#ifndef CUSTOM_EXCEPTION_HPP
#define CUSTOM_EXCEPTION_HPP

#include <exception>
using namespace std;

struct KayuTidakCukupException : public exception  {
	const char* what() const throw() {
		return "Kayu tidak cukup";
	}
};

struct PekerjaTidakCukupException : public exception  {
	const char* what() const throw() {
		return "Pekerja tidak cukup";
	}
};

struct GuldenTidakCukupException : public exception  {
	const char* what() const throw() {
		return "Gulden tidak cukup";
	}
};

#endif