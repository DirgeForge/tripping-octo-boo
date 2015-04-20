#include "../include/fooditem_serialize.h"
#include "../include/fooditem.h"

void FoodItem_Serialize::serialize(std::ostream& out, void* fooditem)
{
	FoodItem * f = static_cast<FoodItem*>(fooditem);
	out << "TITLE " << f->getTitle()
		<< " DESC " << f->getDesc()
		<< " CATEGORY " << f->getCategory()
		<< " IMGPATH " << f->getImgPath()
		<< " ALLERGENS ";
	for (size_t i = 0; i < f->getAllergens().size(); i++)
	{
		out << f->getAllergens()[i] << " , ";
	}
	out	<< " END" << std::endl;
}

void FoodItem_Serialize::unserialize(std::istream& in, void* fooditem)
{
	FoodItem * f = static_cast<FoodItem*>(fooditem);
	std::string token;
	std::string tokenOrder[] = { "TITLE", "DESC", "CATEGORY", "IMGPATH", "ALLERGENS", "END" };
	std::string buffer[] = { "", "", "", "", "" };
	int i = 0;
	while (in >> token && i < f->numTokens - 1)
	{
		while (token != tokenOrder[i + 1])
		{
			buffer[i] += token + " ";
			in >> token;
		}
		i++;
	}

	while (in >> token && token != "END")
	{
		f->getAllergens().push_back(token);
	}
}

FoodItem_Serialize::~FoodItem_Serialize()
{

}