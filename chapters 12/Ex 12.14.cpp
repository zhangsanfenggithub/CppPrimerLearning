#include<iostream>
#include<memory>

using namespace std;

struct destination{
};
struct connection{
};
connection connect(destination &pd)
{
	cout << "������" << endl;
	connection p;
	return p;
}

void disconnect(connection c)
{
	cout << "�ر�����" << endl;
}

void f1(destination &d)
{
	connection c = connect(d);//cannot convert 'destination' to 'destination*' for argument '1' to 'connection connect(destination*)'
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f2(destination &d)
{
	connection c = connect(d);
	shared_ptr<connection> p(&c, end_connection);
}

int main()
{
	destination d;
	f1(d);
	f2(d);
	return 0;
}

