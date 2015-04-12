#ifndef DININGMENU_H
#define DININGMENU_H

#include "item.h"
#include "imenu.h"
#include <vector>

/**
* ---- DiningMenu class -----------------------------------
*
* This class contains multiple objects that extend the Item
* abstract class, and will act as a database of sorts for
* the GUI to access dining menu items from.
*
* ---------------------------------------------------------
*/
class DiningMenu : public IMenu
{
private:
	static DiningMenu * inst;
	std::vector<Item*> items;

	DiningMenu();
	DiningMenu(const DiningMenu&);
	DiningMenu& operator=(const DiningMenu&);
	~DiningMenu();

public:
	static DiningMenu * getInstance();

	void add(Item *) override;
	void remove(Item *) override;
	Item * at(int) const override;
	std::string getCat() const override;
	int getSize() const override;
	int getCapacity() const;
};

#endif