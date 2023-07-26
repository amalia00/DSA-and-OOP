#include "SortedMap.h"



SortedMap::SortedMap()
{
}

SortedMap::SortedMap(BinarySearchTree d)
{
	this->data = d;
}


SortedMap::~SortedMap()
{
}

void SortedMap::setRootNull()
{
	this->data.setRoot(nullptr);
}

void SortedMap::init()
{
	BinarySearchTree* date = new BinarySearchTree();
	this->data = *date;
}

void SortedMap::insertElem(TComp elem)
{
	if (this->searchForElem(elem) == true)
		throw std::exception("Position already occupied");
	this->data.insert(elem);
}

bool SortedMap::searchForElem(TComp elem)
{
	BSTNode* n = this->data.search(elem);
	if (n != nullptr)
		return true;
	return false;
}

bool SortedMap::isEmpty()
{
	if (this->data.getRoot() == nullptr)
		return true;
	return false;
}

BSTIterator* SortedMap::iterator()
{
	BSTIterator* iter = new BSTIterator();
	iter->init(this->data);
	return iter;
}

void SortedMap::print()
{
	BSTIterator* iter = this->iterator();
	while (iter->valid() == true) {
		std::cout << iter->getCurrentVal().value << " ";
		iter->next();
	}
	std::cout << std::endl;
	delete(iter);
}

void SortedMap::remove(TComp elem)
{
	this->data.remove(this->data.getRoot(), elem);
}

BSTNode * SortedMap::getMin()
{
	if (this->isEmpty())
		throw std::exception("Empty set");
	return this->data.getMin(this->data.getRoot());
}

BSTNode * SortedMap::getMax()
{
	if (this->isEmpty())
		throw std::exception("Empty set");
	return this->data.getMax(this->data.getRoot());
}

BSTNode * SortedMap::getSuccessor(TComp elem)
{
	BSTNode* n = this->data.search(elem);
	if (n != nullptr)
		return this->data.getSuccessor(n);
	else
		return n;
}

BSTNode * SortedMap::getPredecessor(TComp elem)
{
	BSTNode* n = this->data.search(elem);
	if (n != nullptr)
		return this->data.getPredecessor(n);
	else
		return n;
}





