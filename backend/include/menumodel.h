#ifndef MENUMODEL_H
#define MENUMODEL_H

#include "imenu.h"
#include "iserializable.h"
#include <vector>
#include <memory>

class MenuModel : public IMenu, public ISerializable
{
private:
	
	std::vector<IObserver*> observers;
	std::vector<std::unique_ptr<IItem>> items;
	std::string filepath;
	std::shared_ptr<ISerializable> serializer;

public:
	MenuModel();
	
	void initialize() override;
	IItem * at(int) const override;
	void add(IItem*) override;
	void remove(int) override;

	int getSize() const override;
	std::string getFilePath() const;

	void setFilePath(const std::string&);

	void addObserver(IObserver *);
	void removeObserver(IObserver *);
	void notifyObservers();

	void serialize(std::ostream&, void*) override;
	void unserialize(std::istream&, void*) override;

	~MenuModel();
};

#endif