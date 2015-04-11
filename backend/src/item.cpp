#include "../include/item.h"

Item::Item() : title("n/a"), description("n/a")
{

}

Item::Item(std::string title, std::string desc, std::string category) 
: title(title), description(desc), category(category)
{

}

Item::~Item()
{
}

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