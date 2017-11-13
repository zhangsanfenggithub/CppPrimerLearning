#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include<string>


class Sales_data{
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	public:
		//���캯�� 
		Sales_data() = default;
		Sales_data(std::string &b) :
			bookNo(b) { } 
		Sales_data(std::string &b, double r, unsigned int u) : 
			bookNo(b), revenue(r), units_sold(u) { }
		Sales_data(std::istream &);
		
		//Sales_data�Ĳ��� 
		std::string isbn() const { return bookNo;}
		Sales_data& combine(const Sales_data&);
		 
	private:
		std::string bookNo;//��� 
		double revenue;//���� 
		unsigned int units_sold;//���� 
		
}; 

std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif
