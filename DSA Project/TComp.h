#pragma once
class TComp
{
public:
	TComp();
	~TComp();
	int value;
	bool operator<(TComp a);
	bool operator<=(TComp a); 
	bool operator>=(TComp a);
	bool operator>(TComp a);
	bool operator==(TComp a);
};

