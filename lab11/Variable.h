#pragma once

#include <string>
#include <iostream>
#include <vector>

class VirtualVariable
{	
protected:
	std::string _name;
public:

	VirtualVariable(std::string name) : _name(name) {}

	virtual void Print() const = 0;
	
	virtual ~VirtualVariable() {};
};

template<typename T>
class Variable : public VirtualVariable
{
protected:
	T _value;
public:
	Variable(std::string name, T value) : VirtualVariable(name), _value(value) {}

	virtual void Print() const override
	{
		std::cout << _name << ": " << _value << std::endl;
	}

	inline void SetValue(T value)
	{
		_value = value;
	}

	~Variable() {}
};

using VariableDouble = Variable<double>;
using VariableInt = Variable<int>;
using VariableFloat = Variable<float>;
using VariableChar = Variable<char>;
using VariableBool = Variable<bool>;

template<typename T>
class VariableWithUnits : public Variable<T>
{
public:
	VariableWithUnits(std::string name, T value, std::string units) : Variable<T>(name, value), _units(units) {}

	virtual void Print() const override
	{
		std::cout << this->_name << ": " << this->_value << " [" << _units << "]" << std::endl;
	}

	~VariableWithUnits() {}

private:
	std::string _units;
};


class ArrayOfVariables
{
public:
	ArrayOfVariables(unsigned maxSize) :_maxSize(maxSize) {}

	template<typename T>
	Variable<T>* CreateAndAdd(std::string name, T value)
	{
		Variable<T>* var = new Variable<T>(name, value);
		_variables.push_back(var);
		return var;
	}

	void Print() const
	{
		for (VirtualVariable* var : _variables)
		{
			var->Print();
		}
	}

	~ArrayOfVariables()
	{
		for (VirtualVariable* var : _variables)
		{
			delete var;
		}
	}

private:
	unsigned _maxSize;
	std::vector<VirtualVariable*> _variables;
};
