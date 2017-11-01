#include<iostream>
#include<vector>

using namespace std;

vector<int>* new_vecInt(void)//���ص���һ��vector<int>��ָ������� 
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
		cout << i << endl;//��Χfor�Ĳ��������ý����� 
}

int main(int argc, char **argv)
{
	vector<int> *pv = new_vecInt();
	if(!pv){
		cout << "�ڴ治�㣡" << endl;
		return -1; 
	}
	read_ints(pv);
	print_vecInt(pv);
	delete pv;
	pv = nullptr;
	return 0;
}
