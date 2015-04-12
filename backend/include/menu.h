#include "imenu.h"
#include <memory>

class Menu : public IMenu
{
private:
	static IMenu * menu;
	Menu(const Menu&);
	Menu& operator=(const Menu&);

public:
	Menu();
	virtual ~Menu() {}
	void toFood();
	void toDrinks();

	Item * at(int) const override;
	void add(Item *) override;
	void remove(Item *) override;
	int getSize() const override;
	std::string getCat() const override;
};