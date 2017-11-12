#include<iostream>

using namespace std;

void exchange(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int i = 100, j = 200;
	int *p1 = &i, *p2 = &j;
	exchange(p1, p2);
	cout << *p1 << p1 << endl;
	cout << *p2 << p2 << endl;
	return 0;	
 } 
