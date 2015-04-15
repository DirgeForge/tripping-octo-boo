#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "imenucontroller.h"
#include "menu.h"
//#include "../../main.cpp"

class MenuController : public IMenuController
{
private:
	Menu * menu;
	//GraphicsView * view;

public:
	//MenuController(Menu*);
	MenuController(Menu *);
	IItem * at(int) const;
	void add(IItem*);
	void remove(int) ;
	int getSize() const ;

	void reset(int) const;
	void print() const;

	~MenuController();

};

#endif