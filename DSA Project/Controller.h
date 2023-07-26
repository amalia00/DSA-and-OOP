#pragma once
#include"SortedMap.h"
class Controller
{
private:
	SortedMap sm;
	int CapMaxim;
public:
	Controller();
	Controller(SortedMap, int);
	~Controller();
	void parkCar();
	void printOccupied();
	void printFree();
	bool isFull();
	void parkAtSpot(TComp e);
	void removeCar(TComp e);
};

