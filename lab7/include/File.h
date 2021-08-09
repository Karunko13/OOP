#pragma once
#include <iostream>
#include "Object.h"

class File:  public Object{
	
	private:

	public:
	File(std::string name);
	void print(std::ostream& stream, int gap = 0) const override;
};