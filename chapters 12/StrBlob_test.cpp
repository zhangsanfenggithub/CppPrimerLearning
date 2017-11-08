#include<iostream>
#include"My_StrBlob1.h"
using namespace std;

//验证StrBlob是否能共享底层数据 
int main(int argc, char **argv)
{
	StrBlob b1;
	{
		StrBlob b2 = {"bili","bili","ganbei"};
		b1 = b2;
		b2.push_back("boy next door");	
	}
	StrBlob b3 = b1;
	cout << b3.front() << " " << b3.back() << endl;
	const StrBlob b4 = b1;
	cout << b4.front() << " " << b4.back() << endl;
	for(StrBlobPtr i = b1.begin(); neq(i, b1.end()); i.incr())
		cout << i.deref() << endl;
	return 0;

} 
