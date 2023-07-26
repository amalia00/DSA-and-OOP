#include "BSTNode.h"



BSTNode::BSTNode()
{
	left = nullptr;
	right = nullptr;
	TComp e;
	e.value = 0;
	info = e;
}

BSTNode::BSTNode(TComp e)
{
	left = nullptr;
	right = nullptr;
	info = e;
}


BSTNode::~BSTNode()
{
}

void BSTNode::setLeft(BSTNode *node)
{
	this->left = node;
}

void BSTNode::setRight(BSTNode *node)
{
	this->right = node;
}

void BSTNode::setInfo(TComp i)
{
	this->info = i;
}
