/*
StrBlob 共享底层的vector<string> 
StrBlobPtr 利用wptr来验证底层vector是否存在 
*/



#ifndef MY_STRBLOB1_H
#define MY_STRBLOB1_H
#include<vector>
#include<string>
#include<initializer_list>
#include<memory>
#include<stdexcept>

using namespace std;

//提前声明 
class StrBlobPtr; 

class StrBlob{
	friend class StrBlobPtr;
	public:
		typedef vector<string>::size_type size_type;
		StrBlob(): data(make_shared<vector<string>> ()) {	}
		StrBlob(initializer_list<string> il): data(make_shared<vector<string>> (il)) {	}
		//首尾元素的访问 
		StrBlobPtr begin();
		StrBlobPtr end();
		bool empty() const { return data->empty();}
		//添加和删除操作
		void push_back(const string &t);
		void pop_back();
		//元素访问，const重载 
		string& front();
		const string& front() const;
		string& back();
		const string& back() const;
				
	private:
		shared_ptr<std::vector<std::string>> data;
		//check检查是否越界 
		void check(size_type i, const std::string& msg) const; 
}; 

inline void StrBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}

inline void StrBlob::push_back(const string &t)
{
	return data->push_back(t);
}

inline void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}
//front
inline string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}
//back
inline string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

inline const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}
//size_t curr; sp_vec_str check() ; wptr
class StrBlobPtr{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);//判等器 
	public:
		StrBlobPtr(): curr(0) {		}
		StrBlobPtr(StrBlob &sb, size_t t = 0):
			wptr(sb.data), curr(t) {	}
		
		//为了对vector的遍历 定义了下面的函数和eq,neq 
		string& deref() const;
		StrBlobPtr& incr(); //前缀递增
		StrBlobPtr& decr(); //前缀递减 

		
	private:
		//若检查成功check返回一个指向vector的shared_ptr
		shared_ptr<vector<string>> 
		  check(size_t, const string& ) const;
		//保存一个weak_ptr，意味着底层vector可能会被销毁
		weak_ptr<vector<string>> wptr;
		size_t curr;//数组中当前的位置
};

inline shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();//检查vector是否存在 
	if(!ret)//检查存在 
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())//检查越界 
		throw out_of_range(msg);
	return ret;//存在返回指向vector的shared_ptr 
} 

inline string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];// (*p)是对象所指向的vector 
}

inline StrBlobPtr& StrBlobPtr::incr()
{
	//如果curr已经指向容器尾后位置，不能递增
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;  
}

inline StrBlobPtr& StrBlobPtr::decr()
{
	--curr;//如果curr为0递减后会造成一个非法的位置 
	check(-1, "decrement past begin of StrBlobPtr");
	return *this;
}
// strblob的begin
inline StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	//如果底层的vector是同一个
	if(l == r)
		return(!r || lhs.curr == rhs.curr);
	else
		return false;//指向不同的指针不可能相同 
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}

#endif 
