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
    int category;
    std::string imgpath;
    bool inSeason;
    double price;
    double discount;

public:
    //Category Const
    static const int BEVERAGES = 0;
    static const int APPETIZERS = 1;
    static const int SOUPS = 2;
    static const int DINNER = 3;
    static const int LUNCH = 4;
    static const int BREAKFAST = 5;
    static const int DESSERTS = 6;
    static const int KIDS = 7;

    static const int numTokens = 8;
	FoodItem();
    FoodItem(const std::string& title, const std::string& description, int category, const std::string& imgPath,
             double price, double discount, bool inSeason);
    void setTitle(const std::string &) override;
    void setDesc(const std::string &) override;
    void setCategory(int) override;
    void setImgPath(const std::string &);
    void setInSeason(bool);
    void setPrice(double);
    void setDiscount(double);
	void addAllergen(const std::string&);



    std::string getTitle() const override;
    std::string getDesc() const override;
    int getCategory() const override;
    std::string getImgPath() const override;
    bool getInSeason() const;
    double getPrice() const;
    double getDiscount() const;

	std::vector<std::string> getAllergens() const;
	
	void reset() override;

	~FoodItem();
};

#endif
