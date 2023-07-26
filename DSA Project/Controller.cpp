#include "Controller.h"



Controller::Controller()
{
}

Controller::Controller(SortedMap sos,int CapMaxim)
{
	this->sm = sos;
	this->CapMaxim = CapMaxim;
}


Controller::~Controller()
{
}

void Controller::parkCar()
{
	if (this->isFull())
		throw std::exception("Full, can't park any more cars");
	BSTIterator* it = new BSTIterator();
	it->init(this->sm.getBST());
	if (it->valid() == false) {
		TComp e;
		e.value = 1;
		this->sm.insertElem(e);
	}
	else if (sm.getMin()->getInfo().value > 1) {
		TComp e;
		e.value = 1;
		this->sm.insertElem(e);
	}
	else {
		if (sm.getSuccessor(it->getCurrentVal()) == nullptr) {
			TComp e;
			e.value = it->getCurrentVal().value+1;
			this->sm.insertElem(e);
		}
		else {
			while (sm.getSuccessor(it->getCurrentVal())->getInfo().value - it->getCurrentVal().value == 1) {
				it->next();
				if (sm.getSuccessor(it->getCurrentVal()) == nullptr)
					break;
			}
			TComp e;
			e.value = it->getCurrentVal().value + 1;
			this->sm.insertElem(e);
		}
	}

}

void Controller::printOccupied()
{
	this->sm.print();
}

void Controller::printFree()
{
	
	BSTIterator* iter = this->sm.iterator();
	if (iter->valid() == false)
		for (int i = 1; i <= this->CapMaxim; i++)
			std::cout << i <<" ";
	else {
		BSTNode* max = this->sm.getMax();
		BSTNode* min = this->sm.getMin();
		for (int i = 1; i <min->getInfo().value; i++)
			std::cout << i << " ";
		while (iter->valid() == true) {
			iter->next();
			if (iter->getCurrent() != nullptr)
				for (int i = sm.getPredecessor(iter->getCurrentVal())->getInfo().value+1; i < iter->getCurrentVal().value; i++)
					std::cout << i << " ";
		}
		for (int i = max->getInfo().value+1; i <= this->CapMaxim; i++)
			std::cout << i << " ";
		std::cout << std::endl;
	}
	delete(iter);
}

bool Controller::isFull()
{
	BSTIterator* it = new BSTIterator();
	it->init(this->sm.getBST());
	int i = 0;
	if (it->valid() == false)
		return false;
	else
		while (it->valid()) {
			it->next();
			i++;
		}
	if (i < this->CapMaxim)
		return false;
	return true;
}

void Controller::parkAtSpot(TComp e)
{
	if (e.value > CapMaxim || e.value<1)
		throw std::exception("We don't have that spot");
	this->sm.insertElem(e);
}

void Controller::removeCar(TComp e)
{
	this->sm.remove(e);
}
