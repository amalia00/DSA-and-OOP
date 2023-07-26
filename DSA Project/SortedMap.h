#pragma once
#include"BinarySearchTree.h"
#include"TRelation.h"
#include"BSTIterator.h"
#include<iostream>
class SortedMap
{
private:
	BinarySearchTree data;
public:
	SortedMap();
	SortedMap(BinarySearchTree d);
	~SortedMap();
	BinarySearchTree getBST() { return this->data; }
	void setRootNull();
	void init();
	void insertElem(TComp elem);
	bool searchForElem(TComp elem);
	bool isEmpty();
	BSTIterator* iterator();
	void print();
	void remove(TComp elem);
	BSTNode* getMin();
	BSTNode* getMax();
	BSTNode* getSuccessor(TComp elem);
	BSTNode* getPredecessor(TComp elem);
};

