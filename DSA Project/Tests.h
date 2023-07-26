#pragma once
#include"UI.h"
class Tests
{
	SortedMap sm;
public:
	Tests();
	~Tests();
	void runTests();
	void testAdd();
	void testMax();
	void testMin();
	void testPred();
	void testSucc();
	void testRemove();
	void testSeRec();
	void testSR();
};

