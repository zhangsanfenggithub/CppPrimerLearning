#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    static int sn;

public:
    Employee () { mysn = sn++; }
    Employee (const string &s) { name = s; mysn = sn++; }
	Employee (Employee &e) { name = e.name; mysn = sn++; }
    Employee& operator=(Employee &rhs) { name = rhs.name; return *this; }
    const string &get_name() { return name; }
    int get_mysn() { return mysn; }

private:
    string name;
    int mysn;
};
//没有拷贝构造函数的时候 f函数的参数 无论是不是引用对结果没有影响 
//存在拷贝构造的时候 参数是引用 结果为:0，1，2； 参数不是引用结果为3，4，5 
int Employee::sn = 0;

void f(Employee &s)
{
    cout << s.get_name() << ":" << s.get_mysn() << endl;
}

int main(int argc, char **argv)
{
    Employee a("赵"), b = a, c;
    c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
