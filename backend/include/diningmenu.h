#ifndef DININGMENU_H
#define DININGMENU_H

#include "item.h"
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
class DiningMenu : public Item
{
private:
	static DiningMenu * inst;
	std::vector<Item*> items;

	DiningMenu();
	DiningMenu(const DiningMenu&);
	DiningMenu& operator=(const DiningMenu&);

public:
	static DiningMenu * getInstance();

	void add(Item *);
	void remove(Item *);
	Item * at(int);

	int getSize() const;
	int getCapacity() const;
};

#endif