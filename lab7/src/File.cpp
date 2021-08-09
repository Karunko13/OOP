#include "File.h"

File::File(std::string name): Object(name){}


void File::print(std::ostream& stream, int gap) const
{
	Object::print(stream, gap);
	stream<<" (FILE)\n";
}
