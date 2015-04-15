#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "imenucontroller.h"
#include "menumodel.h"
#include "iviewable.h"
//#include "../../main.cpp"

class MenuController : public IMenuController
{
private:
	MenuModel * menuModel;
	IViewable * view;
	//GraphicsView * view;

public:
	//MenuController(MenuModel*);
	MenuController(MenuModel *);
	IItem * at(int) const;
	void add(IItem*);
	void remove(int) ;
	int getSize() const ;

	void reset(int) const;
	void print() const;

	~MenuController();

};

#endif
