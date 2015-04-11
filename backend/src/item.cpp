#include "../include/item.h"

Item::Item() : title("n/a"), description("n/a"), category("n/a"), imgpath("n/a")
{

}

Item::Item(const std::string & title, const std::string & desc, 
	const std::string & category, const std::string & imgpath) 
: title(title), description(desc), category(category), imgpath(imgpath)
{

}

Item::~Item()
{
}

// ---- setters -------------------------------------------
void Item::setTitle(std::string s)
{
	title = s;
}

void Item::setDesc(std::string s)
{
	description = s;
}

void Item::setCategory(std::string s)
{
	category = s;
}

// ---- getters -------------------------------------------
std::string Item::getTitle() const
{
	return title;
}

std::string Item::getDesc() const
{
	return description;
}

std::string Item::getCategory() const
{
	return category;
}