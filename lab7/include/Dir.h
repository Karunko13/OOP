#pragma once
#include <vector>
#include"Object.h"

//słowo kluczowe final gwarantuje ze po klasie dir nie bedzie mozna dziedziczyc 
class Dir final: public Object{

	private:

	std::vector <Object*> objVector;

	public:

	Dir(std::string name);

	void operator +=(Object* base);

	void print(std::ostream& stream,int gap = 0) const override;

	Object *get(std::string name);

	Dir *findDir(std::string name);

	void add(Object* base);

	~Dir();
};