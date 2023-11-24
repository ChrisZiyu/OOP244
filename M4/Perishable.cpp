#define _CRT_SECURE_NO_WARNINGS
#include "Perishable.h"
#include"Date.h"
#include<iostream>
#include <limits>
#include<iomanip>
#include<cstring>
#include<fstream>
using namespace std;
namespace sdds {
	Perishable::Perishable()
	{
		m_instructions = nullptr;
		m_exp_date = Date();
	}
	Perishable::Perishable(const Perishable& other):Item(other)
	{
		if (this != &other &&m_sku!=0)
		{
			m_instructions = new char[strlen(other.m_instructions) + 1];
			strcpy(m_instructions, other.m_instructions);
			this->m_exp_date = other.m_exp_date;
		}
	}
	Perishable& Perishable::operator=(const Perishable& perishable)
	{
		(Item)*this=perishable;
		//Item per;
		//per = perishable;

		if (this!=&perishable)
		{
			/*delete[] m_instructions;*/
			m_instructions = new char[strlen(perishable.m_instructions) + 1];
			strcpy(m_instructions, perishable.m_instructions);
			this->m_instructions = perishable.m_instructions;
		}
		else {
			m_instructions = nullptr;
			m_exp_date=Date();
		}
		return *this;
	}
	const Date& Perishable::expiry() const
	{
		return m_exp_date;
	}
	void Perishable::setUnformatted()
	{
		m_exp_date.formatted(false);
	}
	//char* Perishable::readInstructions(ifstream& ifstr)
	//{
	//	ifstr.ignore();
	//	
	//	const int size = 1000;
	//	char tempInstructions[size];
	//	tempInstructions[0] = '\0';
	//	
	//	ifstr.getline(tempInstructions, size, '\t');
	//	if (tempInstructions[0] != '\0'&&tempInstructions!=nullptr) {
	//		ut.alocpy(m_instructions, tempInstructions);
	//	}
	//	else { m_instructions = nullptr; }

	//	return m_instructions;

	//}
	char* Perishable::readInstructions(istream& istr)
	{
		delete[] m_instructions;
		m_instructions = nullptr;
		const int size = 1000;
		char tempInstructions[size];
		tempInstructions[0] = '\0';
		//istr.clear();
		//istr.ignore();
		istr.get(tempInstructions, size, '\n');
		ut.alocpy(m_instructions, tempInstructions);
		

		return m_instructions;
	}

	ostream& Perishable::displayExpiryDate(ostream& ostr) const
	{
		m_exp_date.write(ostr);
		return ostr;
	}
	istream& Perishable::readExpiryDate(istream& istr)
	{
		if (istr)
		{
			cout << "Expiry date (YYMMDD): ";
			istr.clear();
			istr.ignore();
			m_exp_date.read(istr);
			/*displayExpiryDate(cout);*/
			
			
		}
		return istr;
	}
	int Perishable::readSku(istream& istr)
	{
		//Override readSKU function to only receive SKU numbers between 10000 and 39999 (only SKUs starting with digits 1 to 3)
		int sku;
		bool isValid = false;
		cout << "SKU: ";
		do {

			istr >> sku;
			if (istr.fail())
			{
				istr.clear();
				istr.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Integer, retry: ";
			}
			else if (sku < 10000 || sku>39999) {
				cout << "Value out of range [10000<=val<=39999]: ";
			}
			else { isValid = true; }

			/*cout << endl;*/
		} while (!isValid);
		m_sku = sku;
		return sku;


		return 0;
	}
	ofstream& Perishable::save(ofstream& ofstr) const
	{
		// If the Perishable item is in a good state
		if (*this)
		{
			Item::save(ofstr);
			
			if (m_instructions && m_instructions[0]!='\t')
			{
				ofstr << '\t';
				ofstr << m_instructions<<'\t';
			}
			else if (m_instructions && m_instructions[0]!='\0')
			{
				/*ofstr << '\t';*/
				ofstr << m_instructions << '\t';
			}
			//setUnformatted(); change it in a place where theres no const defined
			ofstr << m_exp_date;//check if need of endl
		}
		return ofstr;

		//it will call the save of the Base class.
		//	writes a tab
		//	writes the handling instructions, if handling instructions exist and the attribute is not empty.
		//	writes a tab
		//	writes an unformatted copy of the expiry date
	}
	ifstream& Perishable::load(ifstream& ifstr)
	{

		Item::load(ifstr);
		//readInstructions(ifstr);
		ifstr.ignore();

		const int size = 1000;
		char tempInstructions[size];
		tempInstructions[0] = '\0';

		ifstr.getline(tempInstructions, size, '\t');
		if (tempInstructions[0] != '\t' && tempInstructions != nullptr) {
			ut.alocpy(m_instructions, tempInstructions);
		}
		else { m_instructions = nullptr; }


		ifstr.ignore();
		ifstr >> m_exp_date;
		ifstr.ignore();
		if (ifstr.fail())
		{
			status.clear();
			status.setStatus("Input file stream read (perishable) failed!");
		}
		/*ifstr.fail();*/
		return ifstr;
	}
	ostream& Perishable::display(ostream& ostr) const
	{
	//	if the Perishable Item is in a bad state, the state is printed
	//		otherwise if linear
	//		the display of the base class is called
	//		if handling instructions are not null and not empty a single asterisk('*') is printed otherwise a single space(' ') is printed.
	//			the expiry date is printed
	//			if not linear
	//				prints "Perishable "
	//				displays the base class
	//				prints "Expiry date: "
	//				printed the expiry date(formatted)
	//				if the handling instructions attribute is not null and is not empty "Handling Instructions: " and the content of the instructions are printed
	//					A new line is printed.
		if (ostr)
		{
			double purchaseFund = 0.0;
			if (Item::linear())
			{
				Item::display(ostr);
				if (m_instructions != nullptr && m_instructions[0] != '\0')
				{
					ostr << "*";
					displayExpiryDate(cout);
				}
				else if(m_instructions[0]=='\t') {
					ostr << " ";
					displayExpiryDate(cout);
				}
			}
			else {
				char* itemDesc = getItemDesc();
				int needQty = qtyNeeded();
				int qtyOnHand = qty();
				double price = getPrice();
				ostr << "Perishable AMA Item:" << endl;
				ostr << m_sku << ": " << itemDesc << endl;
				ostr << "Quantity Needed: " << needQty << endl;
				ostr << "Quantity Available: " << qtyOnHand << endl;
				ostr << "Unit Price: $" << setw(4) << fixed << setprecision(2) << price << endl;
				if (qtyOnHand == 0)
				{
					purchaseFund = price * needQty;
				}
				if (qtyOnHand > 1)
				{
					purchaseFund = ((price * needQty) - qtyOnHand * price);
				}
				ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << purchaseFund << endl;
				ostr << "Expiry date: "; displayExpiryDate(cout); ostr << endl;//here working
				if (m_instructions != nullptr && m_instructions[0] != '\0') {
					ostr << "Handling Instructions: " << m_instructions<<endl;
				}
			}
		}
		else { ostr << "Bad state"; }

		return ostr;
	}
	istream& Perishable::read(std::istream& istr)
	{
		/*The read of the base class is called
			the handling instructions memory is deleted and the attribute is set to null
			prompts : "Expiry date (YYMMDD): "
			the expiry date is read
			newline is ignored
			prompts : "Handling Instructions, ENTER to skip: "
			peeks and if the very first character is not '\n' it will read the instructions dynamically into the instructions attribute.otherwise, nothing is read and the attribute remains null.
			if the istream object is in a fail state, it will set the state of the Perishable Item to "Perishable console date entry failed!".*/
		if (istr)
		{
			//readSku(istr);
			Item::read(istr);
			readExpiryDate(istr);
			istr.clear();
			istr.ignore();
			cout << "Handling Instructions, ENTER to skip: ";
			if (istr.peek()!='\n')
			{
				readInstructions(istr);//might need to add wordspace for the output in file
				
			}
			else if (istr.peek()=='\n')
			{
				m_instructions = new char[2];
				strcpy(m_instructions, " ");
			}
			else { m_instructions = nullptr; }

			

		}
		else {
			status.clear();
			status.setStatus("Perishable console date entry failed!");
		}
		return istr;
	}
}