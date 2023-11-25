/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/13/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef STATUS_H
#define STATUS_H
#include <iostream>
namespace sdds {
	class Status {
		char* description{};
		int statusCode{};
	public:
		Status() {}
		Status(char* desc,int status);
		~Status();
		Status(const Status& other);
		void setStatus(int status);
		void setStatus(const char* status);
		int getStatus() const;//dont modify
		const char* getDescription()const;
		operator int() const;
		operator const char* () const;
		operator bool() const;
		/*Status& operator=(const Status& other);*/
		Status& operator=(const char* newDesc);
		Status& operator=(const int newStatus);
		Status& clear();
		
		//bool hasCode()const;
		//bool hasDesc() const;
	};
	std::ostream& operator <<(std::ostream& ostr, const Status& status);
}
#endif // !STATUS_H
