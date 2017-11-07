#include<iostream>
#include<memory>
#include<cstring>
#include<string> 

using namespace std;

const int BASIC = 10;
const int EXTENTION = 50;
int main(int argc, char **argv)
{
	string s1;
	char *p = new char[100];
	int i;
	while(cin >> s1 && s1 != "#"){
		if(s1.size() + strlen(p) <= 100)
			strcat(p, s1.c_str());
	}
	cout << p << endl;
	delete [] p;
	return 0;
	
} 
