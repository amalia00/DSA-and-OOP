#include "BSTIterator.h"
#include<iostream>


BSTIterator::BSTIterator()
{

}


BSTIterator::~BSTIterator()
{
}

void BSTIterator::init(BinarySearchTree& bst)
{
	BSTNode* node = bst.getRoot();
	while (node != nullptr) {
		stack.push(node);
		node = node->getLeft();
	}
	if (stack.isEmpty() == false)
		this->current = stack.top();
	else
		this->current = nullptr;
}

bool BSTIterator::valid()
{
	if(this->current == nullptr)
		return false;
	else
		return true;
}

void BSTIterator::next()
{
	BSTNode * node = this->stack.pop();
	if (node->getRight() != nullptr) {
		node = node->getRight();


		while (node != nullptr) {
			stack.push(node);
			node = node->getLeft();
		}
	};
	if (stack.isEmpty() == false)
		this->current = stack.top();
	else
		this->current = nullptr;

}
