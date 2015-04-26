#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/menumodel.h"
#include "../include/fooditem.h"
#include "../include/fooditem_serialize.h"
#include <QString>
#include <QCoreApplication>

MenuModel::MenuModel() : filepath("C:/PirateSoft/MenuDB.txt")
{
    // SHOULD CHANGE TO APP DIR DOESN'T ????????
    //QString qs(QCoreApplication::applicationDirPath());
    //filepath = qs.toStdString() + "C:/PirateSoft/MenuDB.txt";


    FoodItem_Serialize fItemS;
    serializer = std::make_shared<FoodItem_Serialize>( fItemS);
    this->initialize();
}

/**
* Initializes the model from serialized files containing various information.
* The model default pathname is: fooditems.txt
*
*/
void MenuModel::initialize()
{
	std::ifstream f(filepath);
	while (f.good())
	{
        std::string line;
        getline(f, line);
        std::istringstream objdata(line);
		if (isalpha(objdata.peek()))
		{
			IItem * item = new FoodItem;
            unserialize(objdata, item);
			items.push_back(std::unique_ptr<IItem>(item));
		}
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
	return &*items[n];
}

/**
* Adds the given IItem object into the model.
* @param item the pointer to the item to be added
*/
void MenuModel::add(IItem* item)
{
	items.push_back(std::unique_ptr<IItem>(item));
}

/**
* Removes the object at the given location.
* @param index number of the object to be removed 
*/
void MenuModel::remove(int n)
{
	items[n].release();
	items.erase(items.begin() + n);
}

/**
* Returns total number of IItem objects stored in the model.
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
std::string MenuModel::getFilePath() const
{
	return filepath;
}

/** 
* Changes the filepath for all serialization operations to the argument.
* @param filepath name of the new file to use for serializations
*/
void MenuModel::setFilePath(const std::string& filepath)
{
	this->filepath = filepath;
}

/**
* Subscribes the given observer to this model.
* @param o pointer to the IObserver object that wants to be notified
*/
void MenuModel::addObserver(IObserver * o)
{
	observers.push_back(o);
}

/**
* Unsubscribes the given observer from this model. 
* @param o pointer to the IObserver object that wants to unsubscribe
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
* Delegates serialization to the serializer object.
* @param out ostream reference
* @param thisobj pointer to the object to be serialized
*/
void MenuModel::serialize(std::ostream& out, void* thisobj)
{
	serializer->serialize(out, thisobj);
}

/**
* Delegates unserialization to the serializer object.
* @param in istream reference from which the data is to be extracted
*
*/
void MenuModel::unserialize(std::istream& in, void* thisobj)
{
	serializer->unserialize(in, thisobj);
}

/**
* Destructor - it *should* serialize all changes before destruction.
*/
MenuModel::~MenuModel()
{
	std::ofstream f;
	f.open(filepath, std::ios::trunc);
	for (size_t i = 0; i < items.size(); i++)
	{
		void * item = &*items[i];
		serialize(f, item);
		items[i].release();
	}
	f.flush();
	f.close();
}
