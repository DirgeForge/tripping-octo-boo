#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <iostream>

class ISerializable
{
public:
	virtual ostream& operator<<(std::ostream& out, const ISerializable thisobj) const = 0;
	virtual istream& operator>>(std::istream& in, ISerializable thisobj) = 0;
	static int numTokens;
	virtual ~ISerializable() {}
};

#endif