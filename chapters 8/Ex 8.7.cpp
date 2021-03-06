#include <iostream>
#include <fstream>
#include "Sales_data.h"

using namespace std;

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

int main(int argc, char *argv[])
{
	
	
	ifstream in("text.txt");
	if(!in){
		cerr << "无法打开输入文件" << endl;
		return -1; 
	}
	
	ofstream out("out.txt");
	if(!out){
		cerr << "无法打开输出文件" << endl;
		return -1;
	} 
	
	
	Sales_data total;
	if(read(in, total)){
		Sales_data trans;
		while(read(in, trans)){
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else{
				print(out, total);
				total = trans;
			}
		}
		print(out, total);
	}else
		cerr << "No data?" << endl;
		
} 
