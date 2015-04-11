#include "../include/diningmenu.h"
#include "../include/fooditem.h"
#include <iostream>

int main()
{
	for (int i = 0; i < 10; i++)
	{
		FoodItem * dish = new FoodItem();
		DiningMenu::getInstance()->add(dish);
	}

	for (int i = 0; i < DiningMenu::getInstance()->getSize(); i++)
	{
		std::cout << DiningMenu::getInstance()->at(i)->getTitle() << " ";
	}


	return 0;
}