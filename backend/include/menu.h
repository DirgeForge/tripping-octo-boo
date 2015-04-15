#ifndef MENU_H
#define MENU_H

#include "imenu.h"
#include "iitem.h"
#include <vector>

class Menu : public IMenu
{
private:
	std::vector<IObserver*> observers;
	std::vector<IItem*> items;

public:
	Menu();
	
	void initialize() override;
	IItem * at(int) const override;
	void add(IItem*) override;
	void remove(int) override;
	int getSize() const override;

	void addObserver(IObserver *);
	void removeObserver(IObserver *);
	void notifyObservers();

	~Menu();
};

#endif