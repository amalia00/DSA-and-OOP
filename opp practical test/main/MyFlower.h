#pragma once
#include<istream>
#include<ostream>
using namespace std;
class MyFlower
{
public:
	MyFlower();
	MyFlower(const char* name);
	MyFlower(const MyFlower& other);
	~MyFlower();
	void setName(char* name);
	int NameLenght() const;
	void setNameLenght(int lenght);

	int age() const;
	void setAge(int age);
	friend ostream& operator<<(ostream& stream, const MyFlower& str);
	bool operator <(const MyFlower& b) const;
	MyFlower& operator=(const MyFlower& other);
	MyFlower operator +(const MyFlower& other);

	static int getLivingCount()
	{
		return LIVING_COUNT;
	}
	static int getCreatedCount()
	{
		return CREATED_COUNT;
	}
private:
	char* m_name;
	unsigned int m_name_lenght;
	unsigned int m_age;
	static int CREATED_COUNT;
	static int LIVING_COUNT;
};

