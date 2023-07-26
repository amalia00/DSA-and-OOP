#include "Tests.h"
#include<assert.h>


Tests::Tests()
{
	this->sm.init();
}


Tests::~Tests()
{
}

void Tests::runTests()
{
	this->testAdd();
	this->testMax();
	this->testMin();
	this->testPred();
	this->testSucc();
	this->testSeRec();
	this->testRemove();
	this->testSR();
}

void Tests::testAdd()
{
	TComp e;
	e.value = 10;
	TComp e2;
	e2.value = 2;
	TComp e3;
	e3.value = 3;
	TComp e4;
	e4.value = 7;
	TComp e5;
	e5.value = 4;
	TComp e6;
	e6.value = 11;
	TComp e7;
	e7.value = 16;
	TComp e8;
	e8.value = 1;
	sm.insertElem(e);
	assert(sm.searchForElem(e) == true);
	assert(sm.searchForElem(e2) == false);
	sm.insertElem(e2);
	assert(sm.searchForElem(e2) == true);
	sm.insertElem(e3);
	try {
		sm.insertElem(e3);
	}
	catch (std::exception& e){}
	sm.insertElem(e4);
	sm.insertElem(e5);
	sm.insertElem(e6);
	sm.insertElem(e7);
	sm.insertElem(e8);
}

void Tests::testMax()
{
	this->sm.getMax();
	assert(this->sm.getMax()->getInfo().value == 16);
}

void Tests::testMin()
{
	this->sm.getMin();
	assert(this->sm.getMin()->getInfo().value == 1);
}

void Tests::testPred()
{
	TComp e;
	e.value = 10;
	BSTNode* node;
	this->sm.getPredecessor(e);
	node = this->sm.getPredecessor(e);
	assert(node->getInfo().value == 7);
	e.value = 1;
	this->sm.getPredecessor(e);
	assert(this->sm.getPredecessor(e) == nullptr);
}

void Tests::testSucc()
{
	TComp e;
	e.value = 2;
	this->sm.getSuccessor(e);
	assert(this->sm.getSuccessor(e)->getInfo().value == 3);
	e.value = 16;
	this->sm.getSuccessor(e);
	assert(this->sm.getSuccessor(e) == nullptr);
	e.value = 3;
	this->sm.getSuccessor(e);
}

void Tests::testRemove()
{
	TComp e;
	e.value = 8;
	this->sm.insertElem(e);
	e.value = 4;
	TComp e2;
	e2.value = 2;
	TComp e3;
	e3.value = 3;
	TComp e4;
	e4.value = 10;
	TComp e5;
	e5.value = 100;
	assert(this->sm.searchForElem(e) == true);
	this->sm.remove(e);
	assert(this->sm.searchForElem(e) == false);
	e.value = 8;
	this->sm.remove(e);
	assert(this->sm.searchForElem(e2) == true);
	this->sm.remove(e2);
	assert(this->sm.searchForElem(e2) == false);
	this->sm.remove(e3);
	this->sm.remove(e4);
	e.value = 11;
	this->sm.remove(e);
	e.value = 16;
	this->sm.remove(e);
	e.value = 7;
	this->sm.remove(e);
	e.value = 1;
	this->sm.remove(e);
	e.value = 5;
	this->sm.insertElem(e);
	e.value = 6;
	this->sm.insertElem(e);
	e.value = 5;
	this->sm.remove(e);
	e.value = 3;
	this->sm.insertElem(e);
	e.value = 5;
	this->sm.insertElem(e);
	e.value = 3;
	this->sm.remove(e);
	e.value = 5;
	this->sm.remove(e);
	e.value = 8;
	this->sm.insertElem(e);
	e.value = 7;
	this->sm.insertElem(e);
	e.value = 8;
	this->sm.remove(e);
	e.value = 4;
	this->sm.insertElem(e);
	e.value = 2;
	this->sm.insertElem(e);
	e.value = 4;
	this->sm.remove(e);
	try { this->sm.remove(e5); }
	catch (std::exception& e) {}
}

void Tests::testSeRec()
{
	TComp e;
	e.value = 1;
	this->sm.getBST().sr(e);
	e.value = 100;
	this->sm.getBST().sr(e);
}

void Tests::testSR()
{
	this->sm.setRootNull();
	assert(this->sm.getBST().getRoot() == nullptr);
}
