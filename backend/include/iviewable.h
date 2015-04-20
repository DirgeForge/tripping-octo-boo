#ifndef IVIEWABLE_H
#define IVIEWABLE_H

#include "iobserver.h"

class IViewable : public IObserver
{
public:
	
    virtual ~IViewable() {}
};

#endif
