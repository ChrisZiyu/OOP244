/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/28/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include"Item.h"
#include"Date.h"
#include<iostream>
#include<fstream>
namespace sdds {
	class Perishable :public Item {
		char* m_instructions{};
		Date m_exp_date{ Date() };

	public:
		Perishable();
		Perishable(const Perishable& other);
		Perishable& operator=(const Perishable& perishable);
		virtual ~Perishable() { delete[] m_instructions; }

		const Date& expiry()const;
		void setUnformatted();
		ostream& displayExpiryDate(ostream& ostr)const;
		istream& readExpiryDate(istream& istr);
		//char* readInstructions(ifstream& ifstr);//might be needed later
		char* readInstructions(istream& istr);//might be needed later
		//overrides
		int readSku(std::istream& istr)override;//can receive numbers between 10000 and 39999
		ofstream& save(std::ofstream& ofstr)const override;
		ifstream& load(std::ifstream& ifstr)override;
		ostream& display(std::ostream& ostr)const override;
		istream& read(std::istream& istr) override;

		operator bool()const {
			return m_exp_date.getYear();
		}
	};
}
#endif // !PERISHABLE_H
