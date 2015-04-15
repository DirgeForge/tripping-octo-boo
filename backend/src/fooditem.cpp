#include "../include/fooditem.h"

FoodItem::FoodItem()
{
}

FoodItem::FoodItem(const std::string & title, const std::string & desc, 
	const std::string & category, const std::string& imgpath) :
	title(title), desc(desc), category(category), imgpath(imgpath)
{
}

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

FoodItem::~FoodItem()
{
}