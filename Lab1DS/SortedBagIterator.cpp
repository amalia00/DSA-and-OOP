#include "SortedBagIterator.h"
#include "SortedBag.h"
//#include "CustomException.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//TODO - Implementation
	this->current = 0;
}
//Θ(1);
TComp SortedBagIterator::getCurrent() {
	//TODO - Implementation
	if(!this->valid())
		throw exception();
	return bag.sb[this->current];
	//return NULL_TCOMP;
}
//Θ(1);
bool SortedBagIterator::valid() {
	//TODO - Implementation
	if (this->current < this->bag.nrElems)
	{
		return true;
	}
	return false;
}
//Θ(1);
void SortedBagIterator::next() {
	//TODO - Implementation
	if (this->current == this->bag.nrElems)
	{
		throw exception();
	}
	else 
	{
		this->current++;
	}
}
//Θ(1);
void SortedBagIterator::first() {
	//TODO - Implementation
	this->current = 0;
}
//Θ(1); 