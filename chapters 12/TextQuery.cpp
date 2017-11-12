#include "TextQuery.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using namespace std;

TextQuery::TextQuery(ifstream &is): file(new vector<string>) 
{
	string line;
	while(getline(is,line)){
		file->push_back(line);
		int n = file->size() - 1;
		string word;
		istringstream ss(line);
		while(ss >> word){
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>);
			lines->insert(n); 
		}
	}
}

QueryResult TextQuery::query(const std::string &sought) const
{
	//如果没有找到sought，返回一个指向空set的sp 
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>); 
	//不用下标操作来避免在wm中添加sought 
	auto target = wm.find(sought);
	if(target == wm.end())
		return QueryResult(sought, nodata, file);
	else 
		return QueryResult(sought, target->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " "<< endl;

    // print each line in which the word appeared
	for (auto num : *qr.lines) // for every element in the set 
		// don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") " 
		   << *(qr.file->begin() + num) << endl;

	return os;
}

void runQuery(ifstream &infile)
{
	TextQuery tq(infile);
	while(true){
		string s;
		if(!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s));
	}
}

int main(int argc, char **argv)
{
	ifstream infile;
	if(argc < 2 || !(infile.open(argv[1]), infile))
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	runQuery(infile);
	return 0;
}

