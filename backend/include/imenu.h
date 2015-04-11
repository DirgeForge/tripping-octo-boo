#ifndef IMENU_H
#define IMENU_H

#include "item.h"
#include <string>

class IMenu
{
public:
	virtual Item * at(int) const = 0;
	virtual void add(Item *) = 0;
	virtual int getSize() const = 0;
	virtual std::string getCat() const = 0;

	virtual ~IMenu() {}
};

#endif
