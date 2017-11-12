#ifndef TEXTQUERY_H
#define TEXTQUERY_H
 
#include <fstream>
#include<memory> 
#include<vector>
#include<string>
#include<set>
#include<map>

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

QueryResult TextQuery::query(const std::string &sought) const
{
	//如果没有找到sought，返回一个指向空set的sp 
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>); 
	//不用下标操作来避免在wm中添加sought 
	auto target = wm.find(sought);
	if(target == wm.end())
		return QueryResult(sought, nodata, file);
	else 
		return QueryResult(sought, target, file);
}

#endif 
