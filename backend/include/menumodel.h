#ifndef MENUMODEL_H
#define MENUMODEL_H

#include "imenu.h"
#include <vector>
#include <memory>

class MenuModel : public IMenu
{
private:
	std::vector<IObserver*> observers;
	std::vector<std::unique_ptr<IItem>> items;
	std::string filepath;

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

	~MenuModel();
};

#endif