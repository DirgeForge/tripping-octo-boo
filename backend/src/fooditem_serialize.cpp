#include "../include/fooditem_serialize.h"
#include "../include/fooditem.h"

void FoodItem_Serialize::serialize(std::ostream& out, void* fooditem)
{
	FoodItem * f = static_cast<FoodItem*>(fooditem);
	out << "TITLE " << f->getTitle()
		<< " DESC " << f->getDesc()
		<< " CATEGORY " << f->getCategory()
		<< " IMGPATH " << f->getImgPath()
        << " PRICE " << f->getPrice()
        << " INSEASON " << f->getInSeason()
        << " DISCOUNT " << f->getDiscount()
		<< " ALLERGENS ";
	for (size_t i = 0; i < f->getAllergens().size(); i++)
	{
		out << f->getAllergens()[i] << " ";
	}
	out	<< "END" << std::endl;
	out.flush();
}

void FoodItem_Serialize::unserialize(std::istream &in, void* fooditem)
{
	FoodItem * f = static_cast<FoodItem*>(fooditem);
	std::string token;
    std::string tokenOrder[] = { "TITLE", "DESC", "CATEGORY", "IMGPATH", "PRICE", "INSEASON", "DISCOUNT", "ALLERGENS", "END" };
    std::string buffer[] = { "", "", "", "", "", "", "" };

	int i = 0;
	in >> token;
	while (i < f->numTokens - 1 && in >> token)
	{
		while (token != tokenOrder[i + 1])
		{
            buffer[i] += token;
			in >> token;
		}
		i++;
	}

	// ugh
	f->setTitle(buffer[0]);
	f->setDesc(buffer[1]);
    f->setCategory(std::stoi(buffer[2]));
	f->setImgPath(buffer[3]);
    f->setPrice(std::stoi(buffer[4]));
    if (buffer[5] == "1")
        f->setInSeason(true);
    else
        f->setInSeason(false);
    f->setDiscount(std::stoi(buffer[6]));

	while (in >> token && token != "END")
	{
		f->addAllergen(token);
	}


}

FoodItem_Serialize::~FoodItem_Serialize()
{

}
