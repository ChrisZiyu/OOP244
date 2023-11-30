/*
*****************************************************************************

Full Name  : Christian Ziyu Ukiike
Student ID#: 139915219
Email      : czukiike-santos-delp@myseneca.ca
Date of completion    : 11/16/23

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "iProduct.h"
#include"Status.h"
#include"Utils.h"
using namespace std;
namespace sdds {

	class Item :public iProduct {
		double m_price;
		int m_qtyOnHand;
		int m_neededQty;
		char* m_item_desc;
		bool m_isLinear;

	protected:
		Status status;
		int m_sku;
		//create a query called linear that returns the linear flag of the Item
		bool linear() const;

	public:
		//The Item has a default constructor that sets all the attributes to zero, nullptr and false.
		Item();
		Item(const Item& other);
		Item& operator=(const Item& other);
		void clear();
		~Item();

		//getters
		char* getItemDesc()const;
		double getPrice()const;
		//virtual public query iProduct overrides
		//-------------------------------------------------------------
		//	the qtyNeeded method returns the needed - quantity attribute
		int qtyNeeded()const override;
		//	the qty method returns the on - hand quantity attribute
		int qty()const override;
		//	the double conversion operator overload returns the price
		operator double()const override;
		//	the boolean conversion operator overload returns the state of the object being good.
		operator bool()const override;

		int readSku(std::istream& istr)override;
		char* readDesc(istream& istr);
		int readQtyNeeded(istream& istr);
		int readQtyInHand(istream& istr);
		double readPrice(istream& istr);

		char* FileReadDesc(ifstream& ifstr);
		//virtual public modifier iProduct overrides
		int operator-=(int qty) override;
		int operator+=(int qty) override;
		void linear(bool isLinear) override;
		bool operator==(int sku)const override;
		bool operator==(const char* description)const override;
		ofstream& save(std::ofstream& ofstr)const override;
		ifstream& load(std::ifstream& ifstr)override;
		ostream& display(std::ostream& ostr)const override;
		istream& read(std::istream& istr) override;


	};

}
#endif // !ITEM_H
