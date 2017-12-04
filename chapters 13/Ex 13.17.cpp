#include <iostream>
using namespace std;

class numbered
{
private:
    static int seq;
public:
    numbered () { mysn = seq++; }
    int mysn;
};

int numbered::seq = 0;
// 修改f函数的参数类型 会导致不同的结果 
//分别是numbered s ; const numbered &s; numbered &s; 
void f(numbered s)
{
    cout << s.mysn << endl;
}

int main(int argc, char **argv)
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
