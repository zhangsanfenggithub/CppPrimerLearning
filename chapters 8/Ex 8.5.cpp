#include<iostream>
#include<sstream>
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

    string word;
    vector<string> text;
    while(in >> word){
    	text.push_back(word);
	}
//    while(getline(in,line) && line != "quit")
//    {
//    	istringstream lines(line);
//    	string word;
//    	while(lines >> word)
//    		text.push_back(word);
//	}
        

    in.close();

    vector<string>::iterator it = text.begin();
	for(vector<string>::iterator it = text.begin(); it != text.end(); ++it)
		cout << *it << endl;
    return 0;
}


