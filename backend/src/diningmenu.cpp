#include "../include/diningmenu.h"

DiningMenu * DiningMenu::inst = NULL;

DiningMenu::DiningMenu()
{
}
DiningMenu::DiningMenu(const DiningMenu & other)
{
}
DiningMenu& DiningMenu::operator=(const DiningMenu & other)
{
}

/** ---- getInstance ----
* Returns an instance of the DiningMenu object.
* ### THIS SHOULD RETURN THE SAME INSTANCE EVERY TIME ###
*/
DiningMenu * DiningMenu::getInstance()
{
	if (inst == NULL)
		inst = new DiningMenu;
	return inst;
}

/** ---- add ----
* Adds an item into the items vector.
* @param item Point to the item object to be added
*/
void DiningMenu::add(Item * item)
{
	items.push_back(item);
}

/**
* ---- remove ----
* Deletes the Item from the items vector.
* @param item Pointer to the item object to be removed
*/
void DiningMenu::remove(Item * item)
{
	int pos = 0;
	while (pos < items.size())
	{
		if (item == items[pos])
		{
			delete item;
			items.erase(items.begin() + pos);
			pos = items.size();
		}
		pos++;
	}
}

int DiningMenu::getSize() const
{
	return items.size();
}

int DiningMenu::getCapacity() const
{
	return items.capacity();
}