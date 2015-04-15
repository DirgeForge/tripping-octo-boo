#include <iostream>

#include "../include/menucontroller.h"

MenuController::MenuController(Menu * menu) : menu(menu)
{
	menu->initialize();
}
IItem * MenuController::at(int n) const
{
	return menu->at(n);
}
void MenuController::add(IItem* item)
{
	menu->add(item);
}
void MenuController::remove(int n)
{
	menu->remove(n);
}
int MenuController::getSize() const
{
	return menu->getSize();
}

void MenuController::reset(int n) const
{
	menu->at(n)->setCategory("");
	menu->at(n)->setDesc("");
	menu->at(n)->setTitle("");
	menu->at(n)->setImgPath("");
}
void MenuController::print() const
{
	for (size_t i = 0; i < menu->getSize(); i++)
	{
		IItem * item = menu->at(i);
		std::cout << item->getTitle() << " " << item->getCategory() << " " << item->getDesc() << " " << item->getImgPath() << std::endl;
	}
}

MenuController::~MenuController()
{

}