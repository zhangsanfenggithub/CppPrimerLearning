#include<iostream>
#include<stdexcept>
using namespace std;

istream &f(istream &in)
{
	int num;
	while(in >> num ,!in.eof())
	{
	//	cout << "1";
		if(in.bad())
			throw runtime_error("IO error");
		if(in.fail()){
			cerr << "Wrong data please try again!"<< endl;
			in.clear();
			in.ignore(100,'\n');
			continue;
		}
		cout << "clear success" << endl;
		in.clear();
	}
	return in;
	
}

int main()
{
	cout << "Please enter some number:"<< endl;
	f(cin);
	return 0;
}

