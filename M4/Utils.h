/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/2/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef UTILS_H
#define UTILS_H
#include<iostream>
namespace sdds {
    // Testing date values for application testing and debugging
    // these values must not change at submission time.
    const int sdds_testYear = 2023;
    const int sdds_testMon = 10;
    const int sdds_testDay = 9;

    class Utils {

        bool m_testMode = false;

    public:
        // this function will be used to get the current system date or the test date if m_testMode is true
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        // this function will return the number of days in a month based on the year
        // 1<=mon<=12  year: four digit number (example: 2023)
        int daysOfMon(int mon, int year)const;
        // Puts the system date in test mode, where getSystemDate() function will return 2023, 12, 09
        // or whatever the three constant test dates are set to
        void testMode(bool testmode = true);
        void alocpy(char*& destination, char* source);
        //int getInt(const char* prompt = nullptr);
        //int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);

    };
    extern Utils ut;  // provides global access to the ut instance in the Utils.cpp file
   /* std::istream& operator >>(std::istream& istr, Utils& utils);*/
}

#endif // !UTILS_H


