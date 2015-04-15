#ifndef IMENUCONTROLLER_h
#define IMENUCONTROLLER_H

#include "iitem.h"

class IMenuController
{
public:
	virtual IItem * at(int) const = 0;
	virtual void add(IItem*) = 0;
	virtual void remove(int) = 0;
	virtual int getSize() const = 0;

	virtual void reset(int) const = 0;

	virtual ~IMenuController(){}
};

#endif