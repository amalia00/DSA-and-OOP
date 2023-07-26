#include "TRelation.h"



TRelation::TRelation()
{
}


TRelation::~TRelation()
{
}

bool TRelation::Compare(TComp a, TComp b)
{
	if (a < b)
		return true;
	return false;
}

