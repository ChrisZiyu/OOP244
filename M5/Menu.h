/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/11/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>
namespace sdds {
	class Menu {
		char* m_options;
		

	public:
		Menu(const char* options);
		unsigned int run() const;
		~Menu();
	};
}
#endif // !MENU_H
