#pragma once
#include "Animal.h"
#include <iostream>

class Sheep : public Animal
{
private:
	
public:
	std::string _state = "nieostrzyzona";

	Sheep(std::string name) : Animal(name) {}
	
	void print()const override
	{
		std::cout << "-";
		std::cout << "Owca " << name() <<" "<< _state << std::endl;
	}
	void shear()
	{
		_state = "ostrzyzona";
	}
	~Sheep()
	{
		std::cout << "-";
		std::cout << "Owca " << name() << " " << _state << " wraca do zagrody" << std::endl;
	};
};

class Horse : public Animal
{
private:
public:
	Horse(std::string name) : Animal(name) {}
	
	void print()const override
	{
		std::cout << "-";
		std::cout << "Kon " << name()<< std::endl;
	}
	~Horse() 
	{
		std::cout << "-";
		std::cout << "Kon " << name() << " " << "wraca do stajni" << std::endl;
	};
};

class Cow : public Animal
{
private:
public:
	Cow(std::string name) : Animal(name) {}
	void print()const override
	{
		std::cout << "-";
		std::cout << "Krowa " << name() << std::endl;
	}
	~Cow()
	{
		std::cout << "-";
		std::cout << "Krowa " << name() << " " << "wraca do obory" << std::endl;
	}
};