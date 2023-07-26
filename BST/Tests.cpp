#include "Tests.h"
#include "assert.h"

Tests::Tests()
{


}

Tests::~Tests()
{
}

void Tests::runTests()
{
	this->testAdd();
	this->testDelete();
}

void Tests::testAdd()
{
	Map smap;
	smap.add("ana", "002");
	//assert(smap.printAll() == ["Ana", "002"]);
	//assert(smap.printAll() == ["ioana", "00454"]);
	smap.add("alex","0448");
	smap.deleteNode("Ana");
	//assert(smap.printAll() == ["alex", "0448"]);
	smap.add("alex","0448");
	try {
		smap.add("alex", "0448");
	}
	catch (std::exception& e) {}
}

void Tests::testDelete()
{
	Map smap;
	smap.add("Ionut", "0078");
	//assert(smap.printAll() == ["Ionut", "0078"]);
	smap.add("Ana", "7898");
	smap.deleteNode("Ionut");
	//assert(smap.printAll()== ["Ana", "7898"]);
	smap.add("Ama", "5551454");
	smap.deleteNode("Ama");

	try { this->smap.deleteNode("Marius"); }
	catch (std::exception& e) {}
}



