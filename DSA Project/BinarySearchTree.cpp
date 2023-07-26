#include "BinarySearchTree.h"
#include<iostream>


BinarySearchTree::BinarySearchTree()
{
	this->root = nullptr;
}


BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::setRoot(BSTNode* rut)
{
	this->root = rut;
}

bool BinarySearchTree::searchRec(BSTNode * node, TComp e)
{
	if (node == nullptr)
		return false;
	else if (node->getInfo() == e)
		return true;
	else if (node->getInfo() < e)
		return searchRec(node->getRight(), e);
	else
		return searchRec(node->getLeft(), e);
}

bool BinarySearchTree::sr(TComp e)
{
	return this->searchRec(this->root, e);
}

BSTNode* BinarySearchTree::search(TComp e)
{
	BSTNode* currentNode = this->root;
	bool found = false;
	while (currentNode != nullptr && found != true) {
		if (currentNode->getInfo() == e)
			found = true;
		else if (currentNode->getInfo() < e)
			currentNode = currentNode->getRight();
		else
			currentNode = currentNode->getLeft();
	}
	return currentNode;
}

BSTNode* BinarySearchTree::insertNode(BSTNode * node, TComp e)
{
	if (node == nullptr) 
		node = new BSTNode(e);
	else if (node->getInfo() >= e)
		node->setLeft(insertNode(node->getLeft(), e));
	else
		node->setRight(insertNode(node->getRight(), e));
	return node;
}

BSTNode * BinarySearchTree::parent(BSTNode *node)
{
	BSTNode* parnt = this->root;
	if(parnt == node)
		return nullptr;
	else {
		while (parnt != nullptr && parnt->getLeft() != node && parnt->getRight() != node)
			if (parnt->getInfo() >= node->getInfo())
				parnt = parnt->getLeft();
			else
				parnt = parnt->getRight();
		return parnt;
	}
}

BSTNode * BinarySearchTree::getMin(BSTNode *node)
{
	BSTNode* currentNode = node;
	while (currentNode->getLeft() != nullptr)
		currentNode = currentNode->getLeft();
	return currentNode;
}

BSTNode * BinarySearchTree::getMax(BSTNode *node)
{
	BSTNode* currentNode = node;
	while (currentNode->getRight() != nullptr)
		currentNode = currentNode->getRight();
	return currentNode;
}

BSTNode * BinarySearchTree::getSuccessor(BSTNode * node)
{
	
	if (node->getRight() != nullptr) {
		BSTNode* succ = node->getRight();
		while (succ->getLeft() != nullptr)
			succ = succ->getLeft();
		return succ;
	}
	else {
		BSTNode* parnt = parent(node);
		while (parnt != nullptr && parnt->getLeft() != node) {
			node = parnt;
			parnt = this->parent(node);
		}
		return parnt;
	}
}

BSTNode * BinarySearchTree::getPredecessor(BSTNode * node)
{
	if (node->getLeft() != nullptr) {
		BSTNode* pred = node->getLeft();
		while (pred->getRight() != nullptr)
			pred = pred->getRight();
		return pred;
	}
	else {
		BSTNode* parnt = parent(node);
		while (parnt != nullptr && parnt->getRight() != node) {
			node = parnt;
			parnt = this->parent(node);
		}
		return parnt;
	}
}

void BinarySearchTree::insert(TComp e)
{
	if (this->root == nullptr)
		this->root = new BSTNode(e);
	else
		insertNode(this->root, e);
}

void BinarySearchTree::remove(BSTNode* node,TComp e)
{
	if (node == nullptr)
		throw std::exception("Value not found");
	else if (node->getInfo() > e)
		remove(node->getLeft(), e);
	else if (node->getInfo() < e)
		remove(node->getRight(), e);
	else if (node == root && node->getLeft() != nullptr && node->getRight() == nullptr) {
		root = node->getLeft();
		delete(node);
	}
	else if ((node == root && node->getLeft() == nullptr && node->getRight() != nullptr)) {
		root = node->getRight();
		delete(node);
	}
	else if (node == root && node->getLeft() == nullptr && node->getRight() == nullptr) {
		root = nullptr;
		delete(node);
	}
	else if (node->getLeft() == nullptr && node->getRight() == nullptr) {
		BSTNode* parnt = this->parent(node);
		if (parnt->getLeft() == node)
			parnt->setLeft(nullptr);
		else
			parnt->setRight(nullptr);
		delete(node);
	}
	else if (node->getLeft() == nullptr && node->getRight() != nullptr) {
		BSTNode* parnt = this->parent(node);
		if(parnt->getLeft() == node)
			parnt->setLeft(node->getRight());
		else
			parnt->setRight(node->getRight());
		delete(node);
	}
	else if (node->getLeft() != nullptr && node->getRight() == nullptr) {
		BSTNode* parnt = this->parent(node);
		if (parnt->getLeft() == node)
			parnt->setLeft(node->getLeft());
		else
			parnt->setRight(node->getLeft());
		delete(node);
	}
	else {
		BSTNode* minim = this->getMin(node->getRight());
		TComp aux = node->getInfo();
		node->setInfo(minim->getInfo());
		minim->setInfo(aux);
		remove(minim, e);
	}
}
