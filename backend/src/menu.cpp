#include <iostream>

#include "../include/menumodel.h"
#include "../include/fooditem.h"

MenuModel::MenuModel()
{
	this->initialize();
}

void MenuModel::initialize()
{
	// todo: make this actually read stuff from a file and populate the vector
	items = std::vector<IItem*>(10);
	for (int i = 0; i < 10; i++)
	{
		items[i] = new FoodItem("fug", "item", "food", "food.jpg");
	}
}
IItem * MenuModel::at(int n) const
{
	return items[n];
}
void MenuModel::add(IItem* item)
{
	items.push_back(item);
}
void MenuModel::remove(int n)
{
	delete items[n];
	items.erase(items.begin() + n);
}
int MenuModel::getSize() const
{
	return items.size();
}

void MenuModel::addObserver(IObserver * o)
{
	observers.push_back(o);
}
void MenuModel::removeObserver(IObserver * o)
{
	size_t i = 0;
	while (i < observers.size())
	{
		if (observers[i] == o)
		{
			delete observers[i];
			observers.erase(observers.begin() + i);
			i = observers.size();
		}
		else
		{
			i++;
		}
	}
}
void MenuModel::notifyObservers()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->update();
	}
}

MenuModel::~MenuModel()
{

}