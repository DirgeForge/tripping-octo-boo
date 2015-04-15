#ifndef OBSERVER_H
#define OBSERVER_H

#include "iobserver.h"

class Observer :public IObserver
{
public:
	Observer();
	void update() override;
	~Observer();
};

#endif