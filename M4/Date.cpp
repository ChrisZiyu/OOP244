/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/2/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iomanip>
#include "Date.h"

namespace sdds {
	bool Date:: validDate() {
		
		if (year<CURRENT_YEAR|| year> MAX_YEAR)
		{
			m_state= "Invalid year in date";
			m_state.setStatus(1);
			return false;
		}
		if (month <= INVALID_DATE || month >= MONTH_THIRTEEN)
		{
			m_state = "Invalid month in date";
			m_state.setStatus(2);
			return false;
		}
		//if (day<FIRST_VALID_DAY || day >LAST_VALID_DAY)
		//{

		//	m_state = "Invalid day in date";
		//	m_state.setStatus(3);
		//	return false;

		//}
		//else if (day >= FIRST_VALID_DAY || day <= LAST_VALID_DAY)
		//{
		//	if (day == LAST_VALID_DAY && month == 2 || day == LAST_VALID_DAY && month == 4 || day == LAST_VALID_DAY && month == 6 || day == LAST_VALID_DAY && month == 9 || day == LAST_VALID_DAY && month == 11)
		//	{
		//		m_state = "Invalid day in date";
		//		m_state.setStatus(3);
		//		return false;
		//	}
		//	else if (day==29 && month==2 && year==25)
		//	{
		//		m_state = "Invalid day in date";
		//		m_state.setStatus(3);
		//		return false;
		//	}
		//}
		int maxDay = ut.daysOfMon(month, year);
		if (day < FIRST_VALID_DAY || day > maxDay) {
			m_state = "Invalid day in date";
			m_state.setStatus(3);
			return false;
		}
		return true;
	}
	bool Date::validDateWithParameters(int year, int month, int day)
	{

		if (year<CURRENT_YEAR || year> MAX_YEAR)
		{
			m_state = "Invalid year in date";
			m_state.setStatus(1);
			return false;
		}
		if (month <= INVALID_DATE || month >= MONTH_THIRTEEN)
		{
			m_state = "Invalid month in date";
			m_state.setStatus(2);
			return false;
		}
		int maxDay = ut.daysOfMon(month, year);
		if (day < FIRST_VALID_DAY || day > maxDay) {
			m_state = "Invalid day in date";
			m_state.setStatus(3);
			return false;
		}
		return true;
	}
	int Date::uniqueValue() const
	{
		return year * 372 + month * 31 + day;
	}
	Date::Date()
	{
		int m_year=2023;
		int m_month=12;
		int m_day=9;
		//ut.getSystemDate(&m_year, &m_month, &m_day);//change for later might come on exam!!!
		year = m_year;
		month = m_month;
		day = m_day;
		m_formatted = true;
	}
	Date::Date(int f_year, int f_month, int f_day)
	{
		validDateWithParameters(f_year, f_month, f_day);
		if (f_year!=0 && f_month !=0 && f_day !=0)
		{
			this->year = f_year;
			this->month = f_month;
			this->day = f_day;
			m_formatted = true;
			
		}

	}
	bool Date::operator=(const Date& other)
	{
		if (this != &other) {
			// Copy non-const member variables
			this->year = other.year;
			this->month = other.month;
			this->day = other.day;
			this->m_formatted = other.m_formatted;
		}
		return *this;
	}
	bool Date::operator==(const Date& other) const
	{
		return uniqueValue()==other.uniqueValue();
	}
	bool Date::operator!=(const Date& other) const
	{
		return uniqueValue() != other.uniqueValue();
	}
	bool Date::operator<(const Date& other) const
	{
		return uniqueValue() < other.uniqueValue();
	}
	bool Date::operator>(const Date& other) const
	{
		return uniqueValue() > other.uniqueValue();
	}
	bool Date::operator<=(const Date& other) const
	{
		return uniqueValue() <= other.uniqueValue();
	}
	bool Date::operator>=(const Date& other) const
	{
		return uniqueValue() >= other.uniqueValue();
	}
	const sdds::Status& Date::state() const
	{
		return m_state;
	}
	Date& Date::formatted(bool isFormatted)
	{
		m_formatted = isFormatted;
		return *this;
	}
	Date::operator bool() const
	{
		return m_state;
	}
	std::ostream& Date::write(std::ostream& COUT) const
	{
		if (m_formatted)
		{			  //10000000
			// Print as YYYY/MM/DD with zero-padded month and day
			COUT << year << '/' << std::setw(2) << std::setfill('0') << month << '/' << std::setw(2) << std::setfill('0') << day;
		}
		else {		  //100000
			// Print as YYMMDD with zero-padded month and day
			COUT << std::setw(2) << std::setfill('0') << (year % 100) << std::setw(2) << std::setfill('0') << month << std::setw(2) << std::setfill('0') << day;
		}
		return COUT;
	}

	std::istream& Date::read(std::istream& CIN)
	{
		int receivedDate;
		/*CIN >> receivedDate;*/
		if (!(CIN >> receivedDate)) {
			// Input is not a valid integer
			
			CIN.setstate(std::ios::failbit);
			m_state = "Invalid date value";
			return CIN;
		}
		//format MMDD
		if (receivedDate>=1000 && receivedDate<=9999)
		{
			year = 2023;
			month = receivedDate / 100;
			day = receivedDate % 100;
			/*year += 2000;*/
		}
		else if (receivedDate >=100000 && receivedDate <= 999999)
		{												  
			year = receivedDate / 10000;
			month = (receivedDate / 100) % 100;
			day = receivedDate % 100;
			year += 2000;
		}
		if (receivedDate <100)
		{
			year = 2023;
			month = 0;
			day = receivedDate % 100;
			/*year += 2000;*/
		}
		if (!validDate())
		{
			CIN.setstate(std::ios::badbit);
		}
		return CIN;
	}


	std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		return date.write( os);
	}
	std::istream& operator>>(std::istream& is, Date& date)
	{
		 date.read(is);
		return is;
	}
}



