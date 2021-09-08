#pragma once
#include "Animals.h"
#include "Animal.h"
#include <iostream>
#include <vector>

class Meadow
{
private:
	std::vector<std::unique_ptr<Animal>> meadowVec;
public:
	Meadow() = default;
	void add(std::unique_ptr<Animal> myPtr)
	{
		meadowVec.push_back(std::move(myPtr));
	}
	void print(std::string val= "Zwierzeta na lace")
	{
		std::cout << val<< std::endl;
		for (auto& x : meadowVec)
		{
			
			x->print();
		}
	}
	void countNames()
	{	
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		for (auto& x : meadowVec)
		{	

			if (x->name() == "Beata")
			{
				a++;
			}
			else if(x->name() == "Bernadeta")
			{
				b++;
			}
			else if (x->name() == "Krasula")
			{
				c++;
			}
			else if (x->name() == "Mucka")
			{
				d++;
			}
			else if(x->name() == "Rafal")
			{
				e++;
			}
		}
		std::cout << "Beata: " << a << std::endl;
		std::cout << "Bernadeta: " <<b << std::endl;
		std::cout << "Krasula: " << c << std::endl;
		std::cout << "Mucka: " << d << std::endl;
		std::cout << "Rafal: " << e << std::endl;
	}
	
	std::vector<Sheep*> getSheepHerd()
	{
		std::vector<Sheep*> temp;
		for (auto& x : meadowVec)
		{

			if (dynamic_cast<Sheep*>(&(*x)))
			{
				temp.push_back(dynamic_cast<Sheep*>(&(*x)));
			}
		}
		return temp;
	}
};

