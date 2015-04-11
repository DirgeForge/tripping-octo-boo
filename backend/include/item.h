#ifndef ITEM_H
#define ITEM_H

#include <string>


/**
* ---- Item abstract class --------------------------------
*
* This class forms the basis for all menu objects that are
* "renderable" by the GUI.
*
* --------------------------------------------------------- 
*/
class Item
{
private:
	std::string title;
	std::string description;
	std::string category;
	std::string imgpath;

	int price;
	bool inSeason;

public:
	Item();
	Item(const std::string&, const std::string&, 
		const std::string&, const std::string&);
	virtual ~Item() = 0;

	void setTitle(std::string);
	void setDesc(std::string);
	void setCategory(std::string);

	std::string getTitle() const;
	std::string getDesc() const;
	std::string getCategory() const;
};

#endif