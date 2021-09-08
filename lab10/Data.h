#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Data
{
private:
	std::vector<double> _dataVec;
	std::string _name;
public:
	Data() = default;
	Data(std::string name, std::vector<double> vec)
	{
		_name = name;
		_dataVec = vec;
	}
	void print() const
	{	
		std::cout << _name << ":    ";
		for (auto& x : _dataVec)
		{
			std::cout << x << "     ";
		}
		std::cout << std::endl;
	}
	inline const std::vector<double>& getNumbers() const
	{
		return _dataVec;
	}

};