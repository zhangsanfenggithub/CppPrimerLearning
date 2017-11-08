#include<iostream>
#include<memory>
#include<string>


using namespace std;

int main()
{
	string s;
	allocator<string> a;
	auto const p = a.allocate(100);
//	auto q = p;
	string *q = p;
	while(cin >> s && q != p + 100){
		a.construct(q++, s);
//		uninitialized_copy(s.begin(), s.end(), q++);
	}
	const size_t size = q - p;
	for(size_t i = 0; i < size; i++)
		cout << p[i] << endl;
	while(q != p)
		a.destroy(--q);
	a.deallocate(p, 100);
	
	return 0;
}
