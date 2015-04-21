#include "../include/fooditem.h"
#include "../include/fooditem_serialize.h"

FoodItem::FoodItem()
{
	allergens.clear();
}

FoodItem::FoodItem(const std::string & title, const std::string & desc,
    int category, const std::string& imgpath, double price, double discount, bool inSeason) :
    title(title), desc(desc), category(category), imgpath(imgpath), price(price), discount(discount), inSeason(inSeason)
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
void FoodItem::setCategory(int category)
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
void FoodItem::setInSeason(bool inSeason)
{
    this->inSeason = inSeason;
}
void FoodItem::setPrice(double price)
{
    this->price = price;
}
void FoodItem::setDiscount(double discount)
{
    this->discount = discount;
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
int FoodItem::getCategory() const
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
bool FoodItem::getInSeason() const
{
    return inSeason;
}
double FoodItem::getPrice() const
{
    return price;
}
double FoodItem::getDiscount() const
{
    return discount;
}


// ---- end of getters ----

/**
* Resets all data members. 
*/
void FoodItem::reset()
{
	title = "";
	desc = "";
    category = FoodItem::DINNER;
	imgpath = "";
	allergens.clear();
}


FoodItem::~FoodItem()
{
}
