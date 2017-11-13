#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;


int main()
{
    ifstream in("data.txt");
    if(!in){
        cerr << "无法打开文件" << endl;
        return -1;
    }

    string line;
    vector<string> text;
    while(getline(in,line) && line != "quit")
        text.push_back(line);

    in.close();

    vector<string>::iterator it = text.begin();
	for(vector<string>::iterator it = text.begin(); it != text.end(); ++it)
		cout << *it << endl;
    return 0;
}


