#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<string>

using namespace std;


int main()
{
	ifstream is;
	//打开一个文件
	is.open("text.txt");
	string text;
	vector<string> s1;
	map<string,set<int> > wm;
	//存储文件 
	while(getline(is, text)){
		if(text == "q")
			break;
		s1.push_back(text);
		int n = s1.size() - 1;
		string s2;
		istringstream line(text);
		while(line >> s2)
			wm[s2].insert(n);
	}
	
	//查询 
	string target;
	cout << "enter the string you look for" << endl;
	cin >> target;
	auto loc = wm.find(target);
	if(loc != wm.end()){
		auto lines = loc->second;
		for(auto num : lines) 
		{
			cout << target << "出现在" << num + 1 << "行" << endl;
			cout << *(s1.begin() + num) << endl; 
		}
	}

//for(auto i = lines.begin(); lines != lines.end(); ++i)，采用这个方法就会编译出这个错误 
//	no match for 'operator!=' (operand types are 'std::set<int>' and 'std::set<int>::iterator {aka std::_Rb_tree_const_iterator<int>}')
	
}
