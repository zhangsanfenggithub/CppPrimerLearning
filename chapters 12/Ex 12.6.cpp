#include<iostream>
#include<vector>

using namespace std;

vector<int>* new_vecInt(void)//返回的是一个vector<int>的指针的类型 
{
	return new (nothrow) vector<int>;
}

void read_ints(vector<int> *pv)
{
	int v;
	while(cin >> v)
	{
		pv->push_back(v);
	}
}

void print_vecInt(vector<int> *pv)
{
	for(const auto &i: *pv)
		cout << i << endl;//范围for的操作器不用解引用 
}

int main(int argc, char **argv)
{
	vector<int> *pv = new_vecInt();
	if(!pv){
		cout << "内存不足！" << endl;
		return -1; 
	}
	read_ints(pv);
	print_vecInt(pv);
	delete pv;
	pv = nullptr;
	return 0;
}
