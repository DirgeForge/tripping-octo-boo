#include <iostream>
#include <sstream>
#include "../include/menumodel.h"
#include "../include/fooditem.h"

MenuModel::MenuModel() : filepath("fooditems.txt")
{
	this->initialize();
}

/**
* Initializes the model from serialized files containing various information.
* The model default pathname is: fooditems.txt
*/
void MenuModel::initialize()
{
	std::ifstream f(filepath);
	while (f.good())
	{
		std::string line = f.getline();
		istringstream objdata(line);
		
		items.push_back(new FoodItem);
		objdata >> items[items.size() - 1];
	}
	f.close();
}

/**
* Returns the pointer to the IItem object at the given position.
* @param n the position
* @return IItem pointer at the given location
*/
IItem * MenuModel::at(int n) const
{
	return items[n];
}

/**
* Adds the given IItem-compatible object into the model.
* @param item the pointer to the item to be added
*/
void MenuModel::add(IItem* item)
{
	items.push_back(item);
}

/**
* Removes the object at the given location.
* @param index number of the object to be removed 
*/
void MenuModel::remove(int n)
{
	delete items[n];
	items.erase(items.begin() + n);
}

/**
* Returns total number of IItem-compatible objects stored in the model.
* @return size of the IItem* vector
*/
int MenuModel::getSize() const
{
	return items.size();
}

/**
* Returns the filepath for all serialization operations.
* @return the name of the file (usually plaintext)
*/
std::string MenuModel::getFilePath()
{
	return filepath;
}

/** 
* Changes the filepath for all serialization operations to the argument.
* @param filepath name of the new file to use for serializations
*/
void MenuModel::setFilePath(std::string filepath)
{
	this->filepath = filepath;
}

/**
* Subscribes the given observer to this model.
* @param o pointer to the IObserver-compatible object that wants to be notified
*/
void MenuModel::addObserver(IObserver * o)
{
	observers.push_back(o);
}

/**
* Unsubscribes the given observer from this model. 
* @param o pointer to the IObserver-compatible object that wants to unsubscribe
*/
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

/**
* Notifies all observers subscribed to this model.
*/
void MenuModel::notifyObservers()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->update();
	}
}

/**
* Destructor - it *should* serialize all changes before destruction.
*/
MenuModel::~MenuModel()
{
	std::ofstream f(filepath);
	for (size_t i = 0; i < items.size(); i++)
	{
		f << items[i];
	}
	f.close();
}