#include<iostream>
#include<memory>
#include<cstring>
#include<vector>

using namespace std;

char* func1(char *c1, char *c2)
{
	char *p = new char[50];
	int i = 0;
	for(i = 0; i < strlen(c1); ++i)
		p[i] = c1[i];
	for(int j = i ; j - i < strlen(c2); ++j)
		p[j] = c2[j-i];
		return p; 
}


int main(int argc, char **argv)
{
	//char
	char c1[20] = "Hello";
	char c2[30] = "world";
	for(int i = 0; i < strlen(func1(c1, c2)); ++i)
		cout << func1(c1, c2)[i] << endl;
	char *p = func1(c1, c2);
	//string
	string s1 = "bilibili";
	string s2 = "ganbei";
	string s3 = s1 + s2; 
	strcpy(p, s3.c_str());
	cout << p << endl;
	
	delete [] p;
	return 0;
} 
