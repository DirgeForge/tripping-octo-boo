#include "../include/menu.h"
#include "../include/diningmenu.h"

Menu::Menu() : menu(NULL)
{
}

void Menu::toFood()
{
	menu.reset(DiningMenu::getInstance());
}

void Menu::toDrinks()
{

}

Item * Menu::at(int n) const
{
	return menu->at(n);
}

void Menu::add(Item * item)
{
	menu->add(item);
}

int Menu::getSize() const
{
	return menu->getSize();
}

std::string getCat() const
{
	return "to be implemented";
}