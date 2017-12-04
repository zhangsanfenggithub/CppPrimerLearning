#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { }  // 拷贝构造函数
    HasPtr& operator=(const HasPtr&);  // 拷贝赋值运算符
    HasPtr& operator=(const string&);  // 赋予新string，此处也没考虑到 
    string& operator*();       // 重载解引用没想到·· 
    ~HasPtr();
private:
    string *ps;
    int i;
};

HasPtr::~HasPtr()
{
    delete ps; 		// 释放string内存
}

inline HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newps = new string(*rhs.ps); // 考虑到自赋情况需要delete ps原本的内存 
    delete ps;					
    ps = newps;				
    i = rhs.i; 				
    return *this; 			
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}

int main(int argc, char **argv)
{
    HasPtr h("hi mom!");
    HasPtr h2(h);  // 行为类值，h2、h3和h指向不同string
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    return 0;
}
