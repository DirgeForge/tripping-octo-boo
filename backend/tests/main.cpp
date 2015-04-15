#include "../include/menu.h"
#include "../include/menucontroller.h"
#include "../include/fooditem.h"
#include <iostream>

int main()
{
	// Menu - model
	// MenuController - control
	// ??? - view

	Menu * menu = new Menu();
	menu->initialize();
	MenuController * controller = new MenuController(menu);
	controller->print();

	system("Pause");
	return 0;
}