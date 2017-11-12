#include<iostream>
using std::cout; using std::cin; using std::cerr; using std::endl;

#include<fstream>
using std::ifstream;

#include<string>
using std::string;

#include <cstdlib>  // for EXIT_FAILURE

#include "TextQuery.h"

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
