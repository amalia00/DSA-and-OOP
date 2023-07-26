#pragma once
#include"TComp.h"
class BSTNode
{
private:
	BSTNode* left;
	BSTNode* right;
	TComp info;
public:
	BSTNode();
	BSTNode(TComp e);
	~BSTNode();
	BSTNode* getLeft() { return this->left; }
	BSTNode* getRight() { return this->right; }
	TComp getInfo() { return this->info; }
	void setLeft(BSTNode*);
	void setRight(BSTNode*);
	void setInfo(TComp);
};
