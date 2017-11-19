#include<iostream>
#include<vector>

using namespace std;


struct X{
	X() { cout << "调用构造函数X()" << endl; }
	X(const X &tmp) { cout <<"调用拷贝构造函数X(const X&)" << endl; }
	X& operator = (const X &tmp) { cout << "调用赋值运算" << endl; return *this; }
	~X() { cout << "析构函数" << endl; }
};


void f1(X x)
{
	
}

void f2(X &x)
{
	
}
int main()
{
	X x;
	
	cout << "非引用参数传递f1:" << endl;
	f1(x);
	cout << "-------------------------" << endl;
	
	cout << "引用参数传递f2:" << endl;
	f2(x);
	cout << "-------------------------" << endl;
	
	cout << "动态分配new:" << endl;
	X *p = new X;
	cout << "-------------------------" << endl;
	
	cout << "存放在容器中:" << endl;
	vector<X> vx;
	vx.push_back(x);
	cout << "-------------------------" << endl;
	
	cout << "释放动态对象:" << endl;
	delete p;
	cout << "-------------------------" << endl;
	
	cout << "各种初始化和赋值:" << endl;
	cout << "间接初始化：   " << endl;
	X x1 = x;
	cout << "直接初始化：   " << endl;
	X x2();//用了x这个对象，那么也是拷贝 
	cout << "赋值：         " << endl;
	x1 = x;
	cout << "-------------------------" << endl;
	
	
}
