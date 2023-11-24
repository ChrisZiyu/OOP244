/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/2/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef AIDMAN_H
#define AIDMAN_H
#include"Menu.h"
#include "Date.h"
namespace sdds {
	class AidMan {
		char* fileName;
		Menu mainMenu;
		Date c_date;
		unsigned int menu() const;
	public:
		AidMan(const char* file);
		AidMan(const AidMan& other) = delete;
		AidMan& operator=(const AidMan& other) = delete;
		~AidMan();

		void run();

	};

}
#endif // !AIDMAN_H

