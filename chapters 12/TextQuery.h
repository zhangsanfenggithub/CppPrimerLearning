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
		using line_no = std::vector<std::string>::size_type;//Ϊʲô����public���� 
		TextQuery(std::ifstream& infile);//���캯��
		QueryResult query(const std::string&) const; 
	private:
		std::shared_ptr<std::vector<std::string>> file;//�±� �� һ���ı���ӳ�� 
		std::map<std::string,
			std::shared_ptr<std::set<line_no>>> wm;//���� �� Set��ӳ�� 

};



#endif 
