#define _CRT_SECURE_NO_WARNINGS
#include "MyFlower.h"
#include<string>
#include<string.h>

int MyFlower::CREATED_COUNT = 0;
int MyFlower::LIVING_COUNT = 0;

MyFlower::MyFlower()
{
	m_name_lenght = 100;
	m_name = new char[m_name_lenght];
	m_age = 0;
	m_name[0] = '\0';
	CREATED_COUNT++;
	LIVING_COUNT++;
}

MyFlower::MyFlower(const char* name)
{

	int size = strlen(name);
	m_name_lenght = 2 * size;
	m_age = size;
	m_name = new char[m_name_lenght];
	strcpy(m_name, name);
	CREATED_COUNT++;
	LIVING_COUNT++;
}

MyFlower::MyFlower(const MyFlower& other)
{
	m_name_lenght = other.m_name_lenght;
	m_age = other.m_age;
	m_name = new char[m_name_lenght];
	strcpy(m_name, other.m_name);
	CREATED_COUNT++;
	LIVING_COUNT++;
}

MyFlower::~MyFlower()
{
	delete[] m_name;
	m_name_lenght = 0;
	m_age = 0;
	CREATED_COUNT++;
	LIVING_COUNT--;
}
void MyFlower::setName(char* name)
{
	strcpy(m_name,name);
}
int MyFlower::NameLenght() const
{
	return m_name_lenght;
}
void MyFlower::setNameLenght(int lenght)
{
	m_name_lenght = lenght;
}

int MyFlower::age() const
{
	return m_age;
}

void MyFlower::setAge(int age)
{
	m_age = age;
}

bool MyFlower::operator<(const MyFlower& b) const
{
	if (m_age < b.m_age) return true;
	else return false;
}

MyFlower& MyFlower::operator=(const MyFlower& other)
{
	if (this == &other)
		return *this;

	m_age = other.m_age;
	m_name_lenght= other.m_name_lenght;

	if (m_name != nullptr)
	{
		delete[] m_name;
		m_name = nullptr;
	}
	m_name= new char[m_name_lenght];
	strcpy(m_name, other.m_name);
	return *this;
}

MyFlower MyFlower::operator+(const MyFlower& other)
{
	MyFlower greater;
	if (m_age > other.m_age) return m_name;
	else return other.m_name;
}

ostream& operator<<(ostream& stream, const MyFlower& str)
{
	stream << str.m_name;
	return stream;
}
