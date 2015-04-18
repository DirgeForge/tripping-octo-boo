#ifndef FOODITEM_H
#define FOODITEM_H

#include "iitem.h"
#include "iserializable.h"
#include <vector>

class FoodItem : public IItem, public ISerializable
{
private:
	std::vector<std::string> allergens;
	std::string title;
	std::string desc;
	std::string category;
	std::string imgpath;

public:
	FoodItem();
	FoodItem(const std::string& title, const std::string& description, const std::string& category, const std::string& imgPath);
	void setTitle(const std::string &) override;
	void setDesc(const std::string &) override;
	void setCategory(const std::string &) override;
	void setImgPath(const std::string &);


	std::string getTitle() const override;
	std::string getDesc() const override;
	std::string getCategory() const override;
	std::string getImgPath() const override;

	void reset() override;

	std::ostream& operator<<(std::ostream& out, const FoodItem& thisobj) const override;
	std::istream& operator>>(std::istream& in, FoodItem& thisobj) override;
	~FoodItem();
};

#endif