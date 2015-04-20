#include "../include/menumodel.h"
#include "../include/menucontroller.h"
#include "../include/fooditem.h"
#include "../include/iviewable.h"
#include "../include/iobserver.h"
#include <iostream>
#include <fstream>
#include <sstream>

class ConsoleView : public IViewable
{
public:
	MenuModel * model;
	MenuController * control;
public:
	ConsoleView() 
	{
		// view -> control -> model
		model = new MenuModel;
		control = new MenuController(model, this);
		model->addObserver(this);
	}
	void update() override
	{
		for (int i = 0; i < model->getSize(); i++)
		{
			FoodItem * item = static_cast<FoodItem*>(model->at(i));
			std::cout << "testing [OBJ " << i << "] ----" << std::endl
				<< "    TITLE: " << item->getTitle() << std::endl
				<< " DESCRIPT: " << item->getDesc() << std::endl
				<< " CATEGORY: " << item->getCategory() << std::endl
				<< "  IMGPATH: " << item->getImgPath() << std::endl
				<< "ALLERGENS: ";
			for (int j = 0; j < item->getAllergens().size(); j++)
			{
				std::cout << item->getAllergens()[j] << " ";
			}
			std::cout << std::endl << std::endl;
		}
	}
	~ConsoleView() {}
};

int main()
{
	IViewable * view = new ConsoleView();
	MenuModel * cviewModel = static_cast<ConsoleView*>(view)->model;
	MenuController * cviewCont = static_cast<ConsoleView*>(view)->control;
	
	// notfy observers test
	std::cout << "\n=== notify observers test ===\n" << std::endl;
	cviewModel->notifyObservers();
	
	// add item test
	std::cout << "\n=== adding a new item ===\n" << std::endl;
	cviewCont->add(new FoodItem("fries", "absolutely horrid", "junk", "cancer.jpg")); 
	cviewCont->addAllergen(cviewCont->getSize() - 1, "everything");
	cviewModel->notifyObservers();
	
	// remove test
	std::cout << "\n=== removing fries ===\n" << std::endl;
	cviewCont->remove(cviewCont->getSize() - 1);
	cviewModel->notifyObservers();

	cviewModel->~MenuModel();
	system("Pause");
	return 0;
}