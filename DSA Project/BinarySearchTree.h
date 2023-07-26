#pragma once
#include"BSTNode.h"
class BinarySearchTree
{
private:
	BSTNode* root;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void setRoot(BSTNode*);
	BSTNode* getRoot() { return this->root; }
	bool searchRec(BSTNode* node, TComp e);
	bool sr(TComp e);
	//recursive
	BSTNode* search(TComp e);
	BSTNode* insertNode(BSTNode* node,TComp e);
	BSTNode* parent(BSTNode*);
	BSTNode* getMin(BSTNode* node);
	BSTNode* getMax(BSTNode* node);
	BSTNode* getSuccessor(BSTNode* node);
	BSTNode* getPredecessor(BSTNode* node);
	void insert(TComp e);
	void remove(BSTNode* node,TComp e);
};

