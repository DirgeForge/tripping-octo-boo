#include "../include/menumodel.h"
#include "../include/menucontroller.h"
#include "../include/fooditem.h"
#include "../include/iviewable.h"
#include <iostream>

class ConsoleView : public IViewable
{
public:
	ConsoleView() {}
	void update() override
	{

	}
	~ConsoleView() {}
};

int main()
{
	// MenuModel - model
	// MenuController - control
	// ??? - view

	MenuModel * menu = new MenuModel();
	menu->initialize();
	IViewable * view = new ConsoleView();
	MenuController * controller = new MenuController(menu, view);
	controller->print();

	system("Pause");
	return 0;
}