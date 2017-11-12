#ifndef TEXTQUERY_H
#define TEXTQUERY_H
 
#include <fstream>
#include<memory> 
#include<vector>
#include<string>
#include<set>
#include<map>
#include"QueryResult.h"

class QueryResult;
class TextQuery{
	public:
		using line_no = std::vector<std::string>::size_type;//为什么放在public里面 
		TextQuery(std::ifstream& infile);//构造函数
		QueryResult query(const std::string&) const; 
	private:
		std::shared_ptr<std::vector<std::string>> file;//下标 到 一行文本的映射 
		std::map<std::string,
			std::shared_ptr<std::set<line_no>>> wm;//单词 到 Set的映射 

};



#endif 
