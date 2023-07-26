#ifndef TURISM_H
#define TURISM_H


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Turism
{

private:
	float price;
	int date;
	int month;
	string destination;
	string type;
public:
	string GetType() const;

	string GetDestination() const;

	float GetPrice() const;

	int GetDate() const;

	int GetMonth() const;

	void SetDate(int);

	void SetMonth(int);

	void SetType(string);

	void SetDestination(string);

	void SetPrice(float);

	Turism(float, int, int, int, string, string);

	Turism();

	~Turism();

};
#endif // !TURISM_H