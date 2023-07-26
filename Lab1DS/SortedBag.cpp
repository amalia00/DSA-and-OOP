#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>
//#include "CustomException.h"



SortedBag::SortedBag(Relation r) {
	//TODO - Implementation
	//constructor
	this->bagSize = 800;
	this->nrElems = 0;
	this->sb = new TComp[bagSize];
	this->rel = r;
}
#include<iostream>
using namespace std;
void SortedBag::print() const {
	for (int i = 0; i < this->nrElems; i++)
		std::cout << this->sb[i] << " ";
	std::cout << std::endl;
}


void SortedBag::add(TComp e) {
	//TODO - Implementation
	bool added = false;
	int i;
	for (i = this->nrElems; i > 0 && !added; i--)
	{
		if(rel(e,this->sb[i-1]))
			sb[i ] = sb[i-1];
		else
		{
			this->sb[i] = e;
			added = true;
		}
	}
	if (!added)
	{
		this->sb[i] = e;
	}
	this->nrElems++;
	
}
//best case Θ(1); worst case Θ(nrElems*2); 
void SortedBag::addOccurrences(int nr, TComp elem) {
	//extra operation
	if (nr <= 0)
	{
		throw exception();
	}
	for (int i = 0; i < nr; i++)
	{
		add(elem);
	}
}
//best case Θ(1); worst case Θ(nr); 
bool SortedBag::remove(TComp e) {
	//TODO - Implementation
	int index = 0;
	while (index < this->nrElems && sb[index]!=e)
	{
			index++;
	}
	if (index == this->nrElems)
	{
		return false;
	}
	else
	{
		for (int i = index; i < this->nrElems; i++)
		{
			sb[i] = sb[i + 1];
		}
		this->nrElems--;
		return true;
	}
}


bool SortedBag::search(TComp elem) const {
	//TODO - Implementation
	int l = 0, r = this->nrElems;
	while (l <= r ) {
		int mid = l + (r - l) / 2;

		if (this->sb[mid] == elem)
			return true;

		if (this->sb[mid] < elem)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;

}
//log2 (n)


int SortedBag::nrOccurrences(TComp elem) const {
	//TODO - Implementation
	int l = 0, r = this->nrElems;
	int poz = -1;
	while (l <= r && poz == -1) {
		int mid = l + (r - l) / 2;

		if (this->sb[mid] == elem)
			poz = mid;

		if (this->sb[mid] < elem)
			l = mid + 1;
		else
			r = mid - 1;
	}
	if (poz == -1)
		return 0;
	else {
		int i = poz;
		int count = 0;
		while (this->sb[i--] == elem)
			count++;
		while (this->sb[++poz] == elem)
			count++;
		return count;
	}
	
}
//Θ(log n)



int SortedBag::size() const {
	//TODO - Implementation
	return this->nrElems;
}


bool SortedBag::isEmpty() const {
	//TODO - Implementation
	if (this->nrElems == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	//TODO - Implementation
	delete[] this->sb;
}