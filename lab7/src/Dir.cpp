#include "Dir.h"

Dir::Dir(std::string name): Object(name){}

void Dir::operator +=(Object* base)
{
	objVector.push_back(base);
}

void Dir::print(std::ostream& stream,int gap) const
{

	Object::print(stream,gap);
	stream<<" (DIR)\n";

	for(Object* object : objVector)
	{
		object->print(stream, gap + 1);
	}
}
	
Dir::~Dir()
{
std::cout<<"Deleting Dir: "<<getName()<<std::endl;

	for(Object* object : objVector)
	{
		std::cout<<"About to delete "<<object->getName()<<std::endl;
		delete object;
	}

	objVector.clear();
}

Object* Dir::get(std::string name)
{
	for(Object* object : objVector)
	{
		if(object->getName() == name) return object;

		Dir* subdirectory;
		if((subdirectory = dynamic_cast<Dir*>(object)))
		{
			Object* result = subdirectory->get(name);
			if(result != nullptr) return result;
		}
	}
	return nullptr;
}

Dir* Dir::findDir(std::string name){

for(Object* object : objVector)
	{
		Dir* subdirectory;
		if((subdirectory = dynamic_cast<Dir*>(object)))
		{
			if(subdirectory->getName() == name) return subdirectory;

			Dir* result = subdirectory->findDir(name);
			if(result != nullptr) return result;
		}
	}
	return nullptr;
}

void Dir::add(Object* base)
{
	*this += base;
}
