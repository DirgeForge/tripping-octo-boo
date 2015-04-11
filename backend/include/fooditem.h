#ifndef FOODITEM_H
#define FOODITEM_H

#include "item.h"
#include <vector>

class FoodItem : public Item
{
private:
	std::vector<std::string> allergens;
public:
	FoodItem();
	FoodItem(std::string, std::string, std::string);
	~FoodItem();
};

#endif