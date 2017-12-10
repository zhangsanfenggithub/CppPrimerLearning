#include <utility>   

#include <iostream>
using std::cerr; using std::endl;

#include <set>
using std::set; 

#include <string>
using std::string; 

#include "Folder.h"

void swap(Message &lhs, Message &rhs)
{
	using std::swap;  

	for (auto f: lhs.folders) 
		f->remMsg(&lhs);
	for (auto f: rhs.folders) 
		f->remMsg(&rhs);

	swap(lhs.folders, rhs.folders);   
	swap(lhs.contents, rhs.contents); 

	for (auto f: lhs.folders) 
		f->addMsg(&lhs);
	for (auto f: rhs.folders) 
		f->addMsg(&rhs);
}

Folder::Folder(Folder &&f)
{
	move_Messages(&f);   
}

Folder& Folder::operator=(Folder &&f) 
{
	if (this != &f) {
		remove_from_Msgs();  
		move_Messages(&f);   
	}
	return *this;
}

void Folder::move_Messages(Folder *f)
{
	msgs = std::move(f->msgs); 
	f->msgs.clear();
	for (auto m : msgs) {  
		m->remFldr(f);     
		m->addFldr(this);  
	}
}

Message::Message(Message &&m): contents(std::move(m.contents))
{
	move_Folders(&m); 
}

Message::Message(const Message &m): 
    contents(m.contents), folders(m.folders) 
{
    add_to_Folders(m); 
}

Message& Message::operator=(Message &&rhs) 
{
	if (this != &rhs) {       /
		remove_from_Folders();
		contents = std::move(rhs.contents); 
		move_Folders(&rhs); 
	}
    return *this;
}

Message& Message::operator=(const Message &rhs)
{

    remove_from_Folders();    
    contents = rhs.contents;  
    folders = rhs.folders;    
    add_to_Folders(rhs);     
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

