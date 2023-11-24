/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/13/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef DATE_H
#define DATE_H
#include"Status.h"
#include "Utils.h"
namespace sdds {


	class Date {
		//year
		const int MAX_YEAR = 2030;
		const int CURRENT_YEAR = 2023;
		
		//date
		const int INVALID_DATE = 0;
		const int MONTH_THIRTEEN = 13;

		//day
		int FIRST_VALID_DAY = 1;
		int LAST_VALID_DAY = 31;

		//create instance of a class for the State of the date, It's known as composition or aggregation and is a way to represent a "has-a" relationship between classes.
		sdds::Status m_state;
		sdds::Utils ut;

		int year;//current year
		int month;//int 1 to 12
		int day;//1-31
		
		bool m_formatted;


		bool validDate();
		bool validDateWithParameters(int year, int month, int day);
		int uniqueValue() const;
	public:
		Date();
		Date(int year, int month, int day);
		bool operator =(const Date& other);
		bool operator ==(const Date& other) const;
		bool operator !=(const Date& other) const;
		bool operator <(const Date& other) const;
		bool operator >(const Date& other) const;
		bool operator <=(const Date& other) const;
		bool operator >=(const Date& other) const;
		//accessor
		const sdds::Status& state() const;
		//modifier
		Date& formatted(bool isFormatted);
		//check state of the object
		operator bool() const;
		std::ostream& write(std::ostream& COUT) const;
		std::istream& read(std::istream& CIN);
	};
	std::ostream& operator<<(std::ostream& os, const Date& date);
	std::istream& operator>>(std::istream& is, Date& date);
}
#endif // !DATE_H
