#ifndef IITEM_H
#define IITEM_H

#include <string>

class IItem
{

public:
	virtual ~IItem() {}

	virtual void setTitle(const std::string &) = 0;
	virtual void setDesc(const std::string &) = 0;
    virtual void setCategory(int) = 0;
	virtual void setImgPath(const std::string &) = 0;

	virtual std::string getTitle() const = 0;
	virtual std::string getDesc() const = 0;
    virtual int getCategory() const = 0;
	virtual std::string getImgPath() const = 0;

	virtual void reset() = 0;
};

#endif
