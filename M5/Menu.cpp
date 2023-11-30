/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/13/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include"AidMan.h"
#include<limits>
#include <cstring>
using namespace std;
namespace sdds {

	Menu::Menu(const char* options)
	{
		if (options == nullptr)
		{
			m_options = nullptr;
		}
		if (strlen(options) > 15)
		{
			m_options = nullptr;
		}
		if (options != nullptr)
		{
			if (strlen(options) == 20) { m_options = nullptr; }
			else {

				delete[] m_options;

				m_options = new char[strlen(options) + 1];
				strcpy(m_options, options);
			}
		}
		//maybe will be used later
		//if (options != nullptr)
		//{
		//	for (size_t i = 0; i < strlen(options); i++)
		//	{
		//		if (options[i]=='\t')
		//		{
		//			m_size++;
		//		}
		//	}
		//	if (m_size<=15)
		//	{
		//		m_options = new char[strlen(options) + 1];
		//		strcpy(m_options, options);
		//	}
		//}

	}

	unsigned int  Menu::run() const
	{
		
		const char* prompt = "> ";
		int i = 0;
		int m = 7;
		int m_value = 0;
		
		
		if (m_options)
		{
			
			size_t sequenceNumber = 1;
						
			for (size_t i = 0; i < strlen(m_options); i++) {
				if (m_options[i] != '\t') {
					cout << sequenceNumber << "- ";
					while (m_options[i] != '\t' && m_options[i] != '\0') {
						cout << m_options[i++];
					}
					cout << endl;
					sequenceNumber++;
				}
			}
			cout << "---------------------------------\n"
				<< "0- Exit\n";


			m_value = ut.getint(i, m, prompt);
		}
		else cout << "Invalid Menu!\n";
		return m_value;
		//return unsigned int dont change the state of the menu
	}



	Menu::~Menu()
	{
		delete[] m_options;
	}

}
