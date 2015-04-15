#ifndef IMENU_H
#define IMENU_H

#include "iobserver.h"
#include "iitem.h"

class IMenu
{
public:
	virtual void initialize() = 0;
	virtual IItem * at(int) const = 0;
	virtual void add(IItem*) = 0;
	virtual void remove(int) = 0;
	virtual int getSize() const = 0;

	virtual void addObserver(IObserver *) = 0;
	virtual void removeObserver(IObserver *) = 0;
	virtual void notifyObservers() = 0;

	virtual ~IMenu() {}
};

#endif
