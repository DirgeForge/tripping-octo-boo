#ifndef MENUMODEL_H
#define MENUMODEL_H

#include "imenu.h"
#include <vector>

class MenuModel : public IMenu
{
private:
	std::vector<IObserver*> observers;
	std::vector<IItem*> items;

public:
	MenuModel();
	
	void initialize() override;
	IItem * at(int) const override;
	void add(IItem*) override;
	void remove(int) override;
	int getSize() const override;

	void addObserver(IObserver *);
	void removeObserver(IObserver *);
	void notifyObservers();

	~MenuModel();
};

#endif