#ifndef MY_SCREEN_H
#define MY_SCREEN_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Screen{
	public:
		typedef std::string::size_type size_t;
		Screen() = default;
		Screen(size_t ht, size_t wd, char c):
			height(ht), width(wd), contents(ht * wd, c) {	}
		Screen& move(size_t r, size_t c);
		Screen& set(size_t r, size_t c, char t);
		Screen& set(char t);
		void display();
		//move() display set(c) set(size_t)
		
	private:
		size_t curror;
		size_t height, width;
		std::string contents;
		
};

inline Screen& Screen::move(size_t r, size_t c)
{
	size_t row = width * r + c;
	curror = row;
	return *this;
}

Screen& Screen::set(char t)
{
	contents[curror] = t;
	return *this;
}

Screen& Screen::set(size_t r, size_t c, char t)
{
	size_t row = r * width + c;
	contents[row] = c;
	return *this;
}

void Screen::display() 
{
	for(int i = 0; i < contents.size(); ++i)
		std::cout<< contents[i];
	std::cout << std::endl;
}

#endif
 
