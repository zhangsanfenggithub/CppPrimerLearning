#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include<vector>
#include<string>
#include<memory>
#include<initializer_list>
#include<stdexcept>

using namespace std;

class StrBlob{
	public:
		typedef vector<string>::size_type size_type;
		StrBlob();
		StrBlob(initializer_list<string> il);
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		//添加和删除元素
		void push_back(const string &t);
		void pop_back();
		//元素访问
		string& front();
		const string& front() const;
		string& back();
		const string& back() const;
		
		 
	private:
		shared_ptr<vector<string>> data;
		//如果data[i]异常抛出异常 
		void check(size_type i, const std::string &msg) const;
};

//构造函数
StrBlob::StrBlob(): data(make_shared<vector<string>>())	{	}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {	}

void StrBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}

void StrBlob::push_back(const string &t)
{
	return data->push_back(t);
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}
//front
string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}
//back
string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

#endif 
 
