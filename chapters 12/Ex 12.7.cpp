#include<iostream>
#include<vector>
#include<memory>

using namespace std;

shared_ptr<vector<int>> new_spVecInt(void)
{
	return make_shared<vector<int>> ();
}

void read_ints(shared_ptr<vector<int>> spv)
{
	int v;
	while(cin >> v)
		spv->push_back(v);
} 

void printf_spVecInt(shared_ptr<vector<int>> spv)
{
	for(const auto &i : *spv)//此处为何解引用？ 
		cout << i << endl;
	//如果不解引用就会[Error] no matching function for call to 'begin(std::shared_ptr<std::vector<int> >&)' 
}

int main()
{
	shared_ptr<vector<int>> spv = new_spVecInt();
	read_ints(spv);
	printf_spVecInt(spv);
	return 0;
}
