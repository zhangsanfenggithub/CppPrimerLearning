#include<iostream>

using namespace std;

class numbered{
public:
	int seq;
	
	numbered() { mysn = seq++; }
	numbered(numbered &nb) { mysn = seq++; }
	int mysn;
}; 


void f(numbered x)
{
	cout << x.mysn << endl;	
} 

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
