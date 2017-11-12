#ifndef QUERYRESULT_H
#define QUERTRESULT_H

#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>

class QueryResult{
	friend std::ostream& print(std::ostream&, const QueryResult&);
	public:
			
		typedef std::vector<std::string>::size_type line_no;
		QueryResult(std::string s,
					std::shared_ptr<std::set<line_no>> num,
					std::shared_ptr<std::vector<std::string>> f):
			sought(s), lines(num), file(f)	{ }
			 			
	private:
		std::string sought;//查询的单词 
		std::shared_ptr<std::set<line_no>> lines;//行号 
		std::shared_ptr<std::vector<std::string>> file; //输入的文件 
};

std::ostream &print(std::ostream&, const QueryResult&);

#endif
