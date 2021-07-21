#include "StringBack.h"
#include <iostream>
#include <utility>
#include <cstring>
StringBack::StringBack(const char* str)
{
	_size=strlen(str);
	_data=new char[_size+1];
	memcpy(_data,str,_size);
}

StringBack::StringBack(const StringBack& org)
{
	_size=org._size;
	_data=new char[_size+1];
	strcpy(_data,org._data);
}

StringBack::StringBack(StringBack&& org)
{ 

	//_size = std::__exchange(org._size,0);
	//_prev = std::__exchange(org._prev,nullptr);
	//_data = std::__exchange(org._data,nullptr);
  _size = org._size;
  _next = org._next;
  _data = org._data;

  org._size = 0;
  org._next = nullptr;
  org._data = nullptr;


}

void StringBack::operator-=(StringBack* next)
{
	if(_next == nullptr) 
	{
		_next = next;
	}
	else 
	{
		*_next -= next;
	}
}

void StringBack::operator-=(const char* string)
{
	*this -= StringBack(string);
}

void StringBack::operator-=(StringBack&& next)
{
	StringBack* text = new StringBack(std::move(next));
	*this -= text;
}


void StringBack::operator=(StringBack&& org)
{ 
	_size = org._size;
  _next = org._next;
  _data = org._data;

  org._size = 0;
  org._next = nullptr;
  org._data = nullptr;
}

int StringBack::size() const
{	
  if(_next != nullptr)
	{
	return _size+_next->size();
	}
	else
	{
		return _size;
	}
}



int StringBack::fragments() const
{
		if(_next != nullptr){
	return 1+_next->fragments();
	}
	else
	{
		return 1;
	}

}


std::ostream& operator<<(std::ostream& out,const StringBack& str)
{
	if(str._data==nullptr)
	{
		return out;
	}
	else if(str._next==nullptr) 
	{
		return out<<str._data;
	}
	else return out<<*str._next<<str._data;
}

const StringBack& StringBack::fragment(unsigned index) const
{
	if(index == 0) return *this;
	else return _next->fragment(index - 1);
}

const char* StringBack::str() const
{
	return _data;
}

StringBack::~StringBack()
{
	delete [] _data;
	_size=0;
	delete _next;
  //std::cout<<"check desct"<<std::endl;
}