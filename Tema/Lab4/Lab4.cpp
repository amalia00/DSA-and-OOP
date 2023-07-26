// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "turism.h"

Turism::Turism(float Tprice, int Tdate, int Tmonth, string Tdestination, string Ttype)
{
	price = Tprice;
	destination = Tdestination;
	type = Ttype;
	date = Tdate;
	month = Tmonth;
}
Turism::Turism()
{
	price= 0;
	date = 0;
	month = 0;
}
Turism::~Turism()
{
}
int Turism::GetDate() const
{
	return date;
}
int Turism::GetMonth() const
{
	return month;
}
float Turism::GetPrice() const
{
	return price;
}
string Turism::GetDestination() const
{
	return destination;
}
string Turism::GetType() const
{
	return type;
}
void Turism::SetDate(int TDate)
{
	date = TDate;
}
void Turism::SetMonth(int TMonth)
{
	month = TMonth;
}
void Turism::SetPrice(float Tprice)
{
	price = Tprice;
}
void Turism::SetDestination(string TDestination)
{
	destination = TDestination;
}
void Turism::SetType(string TType)
{
	type = TType;
}

