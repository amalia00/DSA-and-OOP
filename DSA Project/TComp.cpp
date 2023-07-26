#include "TComp.h"



TComp::TComp()
{
}


TComp::~TComp()
{
}

bool TComp::operator<(TComp a)
{
	if (this->value < a.value)
		return true;
	return false;
}

bool TComp::operator<=(TComp a)
{
	if (this->value <= a.value)
		return true;
	return false;
}

bool TComp::operator>=(TComp a)
{
	if (this->value >= a.value)
		return true;
	return false;
}

bool TComp::operator>(TComp a)
{
	if (this->value > a.value)
		return true;
	return false;
}

bool TComp::operator==(TComp a)
{
	if (this->value == a.value)
		return true;
	return false;
}
