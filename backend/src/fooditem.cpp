#include "../include/fooditem.h"

FoodItem::FoodItem() : Item()
{
}

FoodItem::FoodItem(const std::string & title, const std::string & desc, 
	const std::string & category, const std::string & imgpath)
: Item(title, desc, category, imgpath)
{
}

FoodItem::~FoodItem()
{
}