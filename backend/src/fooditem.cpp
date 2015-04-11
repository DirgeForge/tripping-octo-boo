#include "../include/fooditem.h"

FoodItem::FoodItem() : Item::Item()
{
}

FoodItem::FoodItem(const std::string & title, const std::string & desc, 
	const std::string & category, const std::string & imgpath)
: Item::Item(title, desc, category, imgpath)
{
}

FoodItem::~FoodItem()
{
}