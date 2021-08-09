#include "Object.h"

Object::Object(const std::string objName)
{
	_objName=objName;
}
//operator << wywoluje metode print,a ta dziala rekursywnie
std::ostream& operator<<(std::ostream& stream, const Object& base)
{
	base.print(stream);
	return stream;
}

std::string Object::getName() const{
	return _objName;
}

void  Object::print(std::ostream& stream,int gap) const
{
	for(unsigned a = 0; a < gap; a++) 
		{
			stream<<"\t";
		}
	stream<<_objName;
}