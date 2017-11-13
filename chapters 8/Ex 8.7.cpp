#include<iostream>
#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 3){
		cerr << "给出输入，输出文件名" << endl;
		return -1;
	}
	
	
	ifstream in(argv[1]);
	if(!in){
		cerr << "无法打开输入文件" << endl;
		return -1; 
	}
	
	ofstream out(argv[2]);
	if(!out){
		cerr << "无法打开输出文件" << endl;
		return -1;
	} 
	
	
	Sales_data total;
	if(read(in, total)){
		Sales_data trans;
		while(read(in, trans)){
			if(total.isbn() == trans.isbn())
				total.comblie(trans);
			else{
				print(out, total);
			}
		}
		print(out, total);
	}else
		cerr << "No data?" << endl;
		
} 
