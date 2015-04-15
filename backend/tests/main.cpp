#include "../include/menumodel.h"
#include "../include/menucontroller.h"
#include "../include/fooditem.h"
#include <iostream>

int main()
{
	// MenuModel - model
	// MenuController - control
	// ??? - view

	MenuModel * menu = new MenuModel();
	menu->initialize();
	MenuController * controller = new MenuController(menu);
	controller->print();

	system("Pause");
	return 0;
}