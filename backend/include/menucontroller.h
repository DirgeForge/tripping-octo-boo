#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "imenucontroller.h"
#include "menumodel.h"
#include "iviewable.h"
#include "fooditem.h"

class MenuController : public IMenuController
{
private:
	MenuModel * menuModel;



public:
    MenuController(MenuModel*);
    //MenuController(MenuModel *, IViewable *);
	IItem * at(int) const override;
	void add(IItem*) override;
	void remove(int) override;
	int getSize() const override;
	void addAllergen(int, const std::string&);

	void reset(int) const override;
	void print() const;

	~MenuController();

};

#endif
