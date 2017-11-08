/*
StrBlob ����ײ��vector<string> 
StrBlobPtr ����wptr����֤�ײ�vector�Ƿ���� 
*/



#ifndef MY_STRBLOB1_H
#define MY_STRBLOB1_H
#include<vector>
#include<string>
#include<initializer_list>
#include<memory>
#include<stdexcept>

using namespace std;

//��ǰ���� 
class StrBlobPtr; 

class StrBlob{
	friend class StrBlobPtr;
	public:
		typedef vector<string>::size_type size_type;
		StrBlob(): data(make_shared<vector<string>> ()) {	}
		StrBlob(initializer_list<string> il): data(make_shared<vector<string>> (il)) {	}
		//��βԪ�صķ��� 
		StrBlobPtr begin();
		StrBlobPtr end();
		bool empty() const { return data->empty();}
		//��Ӻ�ɾ������
		void push_back(const string &t);
		void pop_back();
		//Ԫ�ط��ʣ�const���� 
		string& front();
		const string& front() const;
		string& back();
		const string& back() const;
				
	private:
		shared_ptr<std::vector<std::string>> data;
		//check����Ƿ�Խ�� 
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
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);//�е��� 
	public:
		StrBlobPtr(): curr(0) {		}
		StrBlobPtr(StrBlob &sb, size_t t = 0):
			wptr(sb.data), curr(t) {	}
		
		//Ϊ�˶�vector�ı��� ����������ĺ�����eq,neq 
		string& deref() const;
		StrBlobPtr& incr(); //ǰ׺����
		StrBlobPtr& decr(); //ǰ׺�ݼ� 

		
	private:
		//�����ɹ�check����һ��ָ��vector��shared_ptr
		shared_ptr<vector<string>> 
		  check(size_t, const string& ) const;
		//����һ��weak_ptr����ζ�ŵײ�vector���ܻᱻ����
		weak_ptr<vector<string>> wptr;
		size_t curr;//�����е�ǰ��λ��
};

inline shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();//���vector�Ƿ���� 
	if(!ret)//������ 
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret->size())//���Խ�� 
		throw out_of_range(msg);
	return ret;//���ڷ���ָ��vector��shared_ptr 
} 

inline string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];// (*p)�Ƕ�����ָ���vector 
}

inline StrBlobPtr& StrBlobPtr::incr()
{
	//���curr�Ѿ�ָ������β��λ�ã����ܵ���
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;  
}

inline StrBlobPtr& StrBlobPtr::decr()
{
	--curr;//���currΪ0�ݼ�������һ���Ƿ���λ�� 
	check(-1, "decrement past begin of StrBlobPtr");
	return *this;
}
// strblob��begin
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
	//����ײ��vector��ͬһ��
	if(l == r)
		return(!r || lhs.curr == rhs.curr);
	else
		return false;//ָ��ͬ��ָ�벻������ͬ 
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}

#endif 
