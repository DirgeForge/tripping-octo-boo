#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <iostream>
#include <string>

class ISerializable
{
public:
	static int numTokens;
	virtual void serialize(std::ostream&, void*) = 0;
	virtual void unserialize(std::istream&, void*) = 0;
	virtual ~ISerializable() {}
	
};

#endif
