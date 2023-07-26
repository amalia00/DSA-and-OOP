#pragma once
#include"Controller.h"
class UI
{
private:
	Controller ctrl;
public:
	UI();
	UI(Controller);
	~UI();
	void Run();
	void printUI();
	void addCar();
	void printOccupied();
	void addCarToSpot();
	void removeCar();
};

