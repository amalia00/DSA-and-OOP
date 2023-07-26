#pragma once
#include"BinarySearchTree.h"
#include"DynamicArray.h"
class BSTIterator
{
private:
	BSTNode *current;
	DynamicArr<BSTNode*> stack;
public:
	BSTIterator();
	~BSTIterator();
	BSTNode* getCurrent() { return this->current; }
	void init(BinarySearchTree& bst);
	TComp getCurrentVal() { return this->current->getInfo(); }
	bool valid();
	void next();
};

