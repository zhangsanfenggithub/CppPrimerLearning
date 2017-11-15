#include<iostream>
#include<vector>

using namespace std;


struct X{
	X() { cout << "���ù��캯��X()" << endl; }
	X(const X &tmp) { cout <<"���ÿ������캯��X(const X&)" << endl; }
	X& operator = (const X &tmp) { cout << "���ø�ֵ����" << endl; return *this; }
	~X() { cout << "��������" << endl; }
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
	
	cout << "�����ò�������" << endl;
	f1(x);
	cout << "-------------------------" << endl;
	
	cout << "���ò�������" << endl;
	f2(x);
	cout << "-------------------------" << endl;
	
	cout << "��̬����" << endl;
	X *p = new X;
	cout << "-------------------------" << endl;
	
	cout << "�����������" << endl;
	vector<X> vx;
	vx.push_back(x);
	cout << "-------------------------" << endl;
	
	cout << "�ͷŶ�̬����" << endl;
	delete p;
	cout << "-------------------------" << endl;
	
	cout << "���ֳ�ʼ���͸�ֵ" << endl;
	X x1 = x;
	X x2(x);
	x1 = x;
	cout << "-------------------------" << endl;
	
	
}
