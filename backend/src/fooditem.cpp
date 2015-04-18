#include "../include/fooditem.h"

FoodItem::FoodItem()
{
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

/**
* Static variable for ISerializable objects - number of data members in the object
*/
int FoodItem::numTokens = 5;

/**
* stream << operator overload.
* Outputs the FoodItem object into the stream as a series of human-readable plaintext.
*
* @param out 	ostream reference
* @param thisobj this object's reference
* @return ostream reference
*/
std::ostream& FoodItem::operator<<(std::ostream& out, const FoodItem& thisobj) const
{
	out << "TITLE " << title << " CATEGORY " << category << " DESC " << desc << " IMG " << imgpath;
	out << " ALLERGENS ";
	for (size_t i = 0; i < allergens.size(); i++)
	{
		out << allergens[i] << " ";
	}
	out << "END" << std::endl;
	return out;
}

/**
* stream >> operator overload.
* Fetches data from the input and stores them into the FoodItem object.
* The data *should* come in the following order:
* TITLE CATEGORY DESCRIPTION IMGPATH ALLERGENS
*
* @param in  	istream reference
* @param thisobj this object's reference
* @return istream reference
*/
std::istream& FoodItem::operator>>(std::istream& in, FoodItem& thisobj)
{
	this->reset();
	std::string ordering[numTokens + 1] = {"TITLE", "CATEGORY", "DESC", "IMG", "ALLERGENS", "END"};
	std::string * buffer[] = {&title, &category, &desc, &imgpath};
	std::string token;

	int i = 0;
	in >> token;	// this should eat the "TITLE" string
	while (in >> token && i < numTokens - 1)
	{
		while (token != ordering[i + 1])
		{
			*buffer[i] += token + " ";
			in >> token;
		}
		i++;
	}
	if (token == ordering[numTokens - 1]) // special case for vectors (ALWAYS DO VECTORS LAST)
	{
		while (in >> token && token != ordering[numTokens])
		{
			allergens.push_back(token);
		}
	}
	return in;
}

FoodItem::~FoodItem()
{
}