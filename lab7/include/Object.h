#pragma once
#include <iostream>

class Object{

	protected:
	std::string _objName;

	public:
	Object(const std::string objName);
	virtual ~Object(){}
	virtual void print(std::ostream& stream,int gap = 0) const;
	std::string getName() const;
	private:

};

std::ostream& operator<<(std::ostream& stream, const Object& base);