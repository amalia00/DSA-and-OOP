#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>;

using namespace std;

FixedCapBiMap::FixedCapBiMap(int capacity) {
	if (capacity <= 0) {
		throw exception();
	}
	this->capacity = capacity;
	this->nrPairs = 0;
	this->elements = new TElem[capacity];
}
//Theta(1)

FixedCapBiMap::~FixedCapBiMap() {
	delete[] this->elements;
}
//Theta(1)

bool FixedCapBiMap::add(TKey c, TValue v) {
	if (this->capacity == this->nrPairs) {
		throw exception();
	}
	int index = 0;
	int count = 0;
	while (count < 2 && index < this->nrPairs) {
		if (this->elements[index].first == c) {
			count++;
		}
		index++;
	}
	if (count == 2) {
		return false;
	}
	else {
		this->elements[this->nrPairs].first = c;
		this->elements[this->nrPairs].second = v;
		this->nrPairs++;
		return true;
	}
}
//Best case: Theta(1)
//Worst case: Theta(nrPairs) => total complexity: O(nrPairs)

ValuePair FixedCapBiMap::search(TKey c) const {
	ValuePair returnedValue;
	returnedValue.first = NULL_TVALUE;
	returnedValue.second = NULL_TVALUE;

	int count = 0;
	int index = 0;
	while (count < 2 && index < this->nrPairs)
	{
		if (this->elements[index].first == c)
		{
			if (count == 0) {
				returnedValue.first = this->elements[index].second;
			}
			else {
				returnedValue.second = this->elements[index].second;
			}
			count++;
		}
		index++;
	}
	return returnedValue;
}
//Best case: Theta(1)
//Worst case: Theta(nrPairs) => total complexity: O(nrPairs)

bool FixedCapBiMap::remove(TKey c, TValue v) {
	int index = 0;
	bool found = false;
	while (index < this->nrPairs && found == false)
	{
		if (this->elements[index].first == c && this->elements[index].second == v)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}
	if (found == false) {
		return false;
	}
	else {
		this->elements[index] = this->elements[this->nrPairs - 1];
		this->nrPairs--;
		return true;
	}
}
//Best case: Theta(1)
//Worst case: Theta(nrPairs) => total complexity: O(nrPairs)

ValuePair FixedCapBiMap::removeKey(TKey k) {
	ValuePair removeValue;
	removeValue = this->search(k);
	index = 0;
	if(removeValue.first != NULL_TVALUE)
	{
		this->remove(k, removeValue.first);
	}
	if (removeValue.second != NULL_TVALUE)
	{
		this->remove(k, removeValue.second)
	}
	return removeValue;
	}


int FixedCapBiMap::size() const {
	return this->nrPairs;
}
//Theta(1)

bool FixedCapBiMap::isEmpty() const {
	if (this->nrPairs == 0) {
		return true;
	}
	else {
		return false;
	}
}
//Theta(1)

bool FixedCapBiMap::isFull() const {
	if (this->nrPairs == this->capacity)
	{
		return true;
	}
	else {
		return false;
	}
}
//Theta(1)

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}
//Theta(1)



