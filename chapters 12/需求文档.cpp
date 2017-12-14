#include<iostream>
需求：
	读入文件，能记住单词的出现的行数，出现的次数
	输出
		--提取单词出现的行号
		--行号升序
		--能够打印给定行号文本
	
	
	--vector<string> 存取文本，每行作为一个元素，需要打印时寻找行号
	--set保存行号，保证不重复且升序
	--map将单词和行号关联起来
	
	输入文件类TextQuery
	查询结果类QueryResult
	
	
设计类前尝试使用它，思考可能需要的操作

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);//用文件构造初始化
	string s;
	while(1){
		cout << "enter word to look for or enter q to quit" << endl;
		if(!(cin >> s) && s == "q") break;
		print(cout, tq.query(s));//输出函数以及tq所需要的查询操作 
	} 
 } 
