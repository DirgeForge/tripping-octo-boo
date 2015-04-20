#ifndef FOODITEM_H
#define FOODITEM_H

#include "iitem.h"
#include "iserializable.h"
#include <vector>
#include <memory>

class FoodItem : public IItem
{
private:
	std::vector<std::string> allergens;
	std::string title;
	std::string desc;
	std::string category;
	std::string imgpath;

public:
	static const int numTokens = 5;
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

	std::vector<std::string> getAllergens() const;
	
	void reset() override;

	~FoodItem();
};

#endif
