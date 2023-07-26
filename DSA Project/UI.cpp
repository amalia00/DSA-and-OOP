#include "UI.h"
#include<string>


UI::UI()
{
}

UI::UI(Controller c)
{
	this->ctrl = c;
}


UI::~UI()
{
}

void UI::Run()
{
	while (1) {
		std::string cmd;
		this->printUI();
		std::cout << "Give command: ";
		std::cin >> cmd;
		if (cmd == "1") {
			try {
				this->addCar();
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else if (cmd == "2") {
			std::cout << "Occupied spots: ";
			this->printOccupied();
		}
		else if (cmd == "3")
			this->removeCar();
		else if (cmd == "4")
			this->addCarToSpot();
		else if (cmd == "0")
			break;
		else
			std::cout << "\nInvalid command\n";
	}
}

void UI::printUI()
{
	std::cout << "\nAvailable commands:" << std::endl << "0.Exit" << std::endl << "1.Add a new subscription"<< std::endl << "2.Print all the subscriptions" << std::endl << "3.Delete a subscription" << std::endl << "4.Search for a subscription" << std::endl;
}

void UI::addCar()
{
	this->ctrl.parkCar();
}

void UI::printOccupied()
{
	this->ctrl.printOccupied();
}

void UI::addCarToSpot()
{
	std::cout << "\nList of free spots: ";
	this->ctrl.printFree();
	std::string cmd;
	std::cout << "\nPick the spot to park on: ";
	std::cin >> cmd;
	try {
		int i;
		i = std::stoi(cmd);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	int i = std::stoi(cmd);
	TComp e;
	e.value = i;
	try {
		this->ctrl.parkAtSpot(e);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void UI::removeCar()
{
	int i;
	std::cout << "Give the car number to be removed: ";
	std::cin >> i;
	TComp e;
	e.value = i;
	try {
		this->ctrl.removeCar(e);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << ",no car parked there" << std::endl;
	}
}
