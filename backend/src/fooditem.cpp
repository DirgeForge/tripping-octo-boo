#include "../include/fooditem.h"
#include "../include/fooditem_serialize.h"

FoodItem::FoodItem()
{
	allergens.clear();
}

FoodItem::FoodItem(const std::string & title, const std::string & desc, 
	const std::string & category, const std::string& imgpath) :
	title(title), desc(desc), category(category), imgpath(imgpath)
{

}

// ==== setters ====

void FoodItem::setTitle(const std::string & title)
{
	this->title = title;
}
void FoodItem::setDesc(const std::string & desc)
{
	this->desc = desc;
}
void FoodItem::setCategory(const std::string & category)
{
	this->category = category;
}
void FoodItem::setImgPath(const std::string & imgpath)
{
	this->imgpath = imgpath;
}
void FoodItem::addAllergen(const std::string& allergen)
{
	allergens.push_back(allergen);
}
// ---- end of setters ----

// ==== getters ====

std::string FoodItem::getTitle() const
{
	return title;
}
std::string FoodItem::getDesc() const
{
	return desc;
}
std::string FoodItem::getCategory() const
{
	return category;
}
std::string FoodItem::getImgPath() const
{
	return imgpath;
}
std::vector<std::string> FoodItem::getAllergens() const
{
	return allergens;
}

// ---- end of getters ----

/**
* Resets all data members. 
*/
void FoodItem::reset()
{
	title = "";
	desc = "";
	category = "";
	imgpath = "";
	allergens.clear();
}


FoodItem::~FoodItem()
{
}
