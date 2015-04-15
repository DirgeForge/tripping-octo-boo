#include <iostream>

#include "../include/menu.h"
#include "../include/fooditem.h"

Menu::Menu()
{
	this->initialize();
}

void Menu::initialize()
{
	// todo: make this actually read stuff from a file and populate the vector
	items = std::vector<IItem*>(10);
	for (int i = 0; i < 10; i++)
	{
		items[i] = new FoodItem("fug", "item", "food", "food.jpg");
	}
}
IItem * Menu::at(int n) const
{
	return items[n];
}
void Menu::add(IItem* item)
{
	items.push_back(item);
}
void Menu::remove(int n)
{
	delete items[n];
	items.erase(items.begin() + n);
}
int Menu::getSize() const
{
	return items.size();
}

void Menu::addObserver(IObserver * o)
{
	observers.push_back(o);
}
void Menu::removeObserver(IObserver * o)
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
void Menu::notifyObservers()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->update();
	}
}

Menu::~Menu()
{

}