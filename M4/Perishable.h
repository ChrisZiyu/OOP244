#ifndef PERISHABLE_H
#define PERISHABLE_H
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
