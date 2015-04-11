#include "../include/fooditem.h"

FoodItem::FoodItem() : Item::Item()
{
}

FoodItem::FoodItem(std::string title, std::string desc, std::string category)
: Item::Item(title, desc, category)
{
}

FoodItem::~FoodItem()
{
}