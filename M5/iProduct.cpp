/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "iProduct.h"

namespace sdds {
	std::istream& operator>>(std::istream& istr, iProduct& p) {
		return p.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, iProduct& p) {
		return p.display(ostr);
	}
}