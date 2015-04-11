#include "imenu.h"
#include <memory>

class Menu : public IMenu
{
private:
	static shared_ptr<IMenu> menu;
	Menu(const Menu&);
	Menu& operator=(const Menu&);

public:
	Menu();
	virtual ~Menu() {}
	void toFood();
	void toDrinks();

	Item * at(int) const override;
	void add(Item *) override;
	int getSize() const override;
	std::string getCat() const override;
};