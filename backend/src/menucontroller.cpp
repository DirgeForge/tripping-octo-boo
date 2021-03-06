#include <iostream>

#include "../include/menucontroller.h"

/** 
* Working constructor.
* @param menuModel pointer to the MenuModel object to act as the model
* @param view pointer to the IViewable object to act as the view
*/
MenuController::MenuController(MenuModel * menuModel) :
 menuModel(menuModel)
{
}

/** 
* Returns the IItem object at index n.
* @param n index number
* @return pointer to an IItem object
*/
IItem * MenuController::at(int n) const
{
	return menuModel->at(n);
}

/**
* Adds the IItem object into the model.
* @param item pointer to an IItem object
*/
void MenuController::add(IItem* item)
{
	menuModel->add(item);
}

/**
* Removes the IItem object at index n.
* @param n index of the object to remove
*/
void MenuController::remove(int n)
{
	menuModel->remove(n);
}

/**
* Returns the number of IItem objects stored in the model.
* @return number of IItem objects
*/
int MenuController::getSize() const
{
	return menuModel->getSize();
}
void MenuController::addAllergen(int pos, const std::string& allergen)
{
	static_cast<FoodItem*>(menuModel->at(pos))->addAllergen(allergen);
}
/** 
* Resets the IItem object at index n.
* @param n the index of the object to reset
*/
void MenuController::reset(int n) const
{
	menuModel->at(n)->reset();
}

/**
* Prints all relevant info about the IItem objects to console.
*/
void MenuController::print() const
{
	for (int i = 0; i < menuModel->getSize(); i++)
	{
		IItem * item = menuModel->at(i);
		std::cout << item->getTitle() << " " << item->getCategory() << " " << item->getDesc() << " " << item->getImgPath() << std::endl;
	}
}
void MenuController::update()
{
    menuModel->~MenuModel();
    menuModel = new MenuModel;
}

MenuController::~MenuController()
{
    menuModel->~MenuModel();
}
