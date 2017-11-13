#include <iostream>
#include "Sales_data.h"

using namespace std;

//流初始化Sales_data 
Sales_data::Sales_data(istream &is)
{
	double price = 0.0;
	is >> bookNo >> price >> units_sold;//读入书号，单价，销量 
	revenue = price * units_sold;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.revenue << " "   << item.units_sold;
	return os;
}
