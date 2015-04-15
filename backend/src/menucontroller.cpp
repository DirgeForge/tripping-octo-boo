#include <iostream>

#include "../include/menucontroller.h"

MenuController::MenuController(MenuModel * menuModel) : menuModel(menuModel)
{
	menuModel->initialize();
}
IItem * MenuController::at(int n) const
{
	return menuModel->at(n);
}
void MenuController::add(IItem* item)
{
	menuModel->add(item);
}
void MenuController::remove(int n)
{
	menuModel->remove(n);
}
int MenuController::getSize() const
{
	return menuModel->getSize();
}

void MenuController::reset(int n) const
{
	menuModel->at(n)->setCategory("");
	menuModel->at(n)->setDesc("");
	menuModel->at(n)->setTitle("");
	menuModel->at(n)->setImgPath("");
}
void MenuController::print() const
{
	for (size_t i = 0; i < menuModel->getSize(); i++)
	{
		IItem * item = menuModel->at(i);
		std::cout << item->getTitle() << " " << item->getCategory() << " " << item->getDesc() << " " << item->getImgPath() << std::endl;
	}
}

MenuController::~MenuController()
{

}