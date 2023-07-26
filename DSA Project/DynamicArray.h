#pragma once
#include"BSTNode.h"

typedef BSTNode* TElement;
template <typename T>
class DynamicArr {

	T* elems;
	int size;
	int capacity;
public:
	DynamicArr(int capacity = 10);
	// default constructor for a DynamicArray

	DynamicArr(const DynamicArr& v);
	// copy constructor for a DynamicArray

	~DynamicArr();
	// destructor for a DynamicArray
	bool isEmpty();
	TElement top();
	//function which checks wheter the dynamic array is empty or not
	void push(const TElement& e);
	//add function for the DynamicArray (stack)
	TElement pop();
	//pop function for the DynamicArray (stack)
	TElement* getAllElems() const;
	DynamicArr& operator=(const DynamicArr a);
	int getSize() const;

private:
	void resize(double num = 2);
	// Resizes the current DynamicArray, multiplying its capacity by a given number (real number).
};
template <typename T>
DynamicArr<T>::DynamicArr(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}
template <typename T>
DynamicArr<T>::DynamicArr(const DynamicArr & v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}
template <typename T>
DynamicArr<T>::~DynamicArr()
{
	delete[] this->elems;
}
template<typename T>
inline bool DynamicArr<T>::isEmpty()
{
	if (this->size == 0)
		return true;
	return false;
}
template<typename T>
inline TElement DynamicArr<T>::top()
{
	return this->elems[this->size-1];
}
template <typename T>
void DynamicArr<T>::push(const TElement & e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}
template <typename T>
TElement DynamicArr<T>::pop()
{
	TElement e = this->elems[this->size - 1];
	this->size--;
	return e;
}

template <typename T>
int DynamicArr<T>::getSize() const
{
	return this->size;
}
template <typename T>
DynamicArr<T> & DynamicArr<T>::operator=(const DynamicArr a)
{
	if (this == &a)
		return *this;

	this->size = a.size;
	this->capacity = a.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = a.elems[i];

	return *this;
}
template <typename T>
TElement * DynamicArr<T>::getAllElems() const
{
	return this->elems;
}

template <typename T>
void DynamicArr<T>::resize(double num)
{
	this->capacity *= static_cast<int>(num);

	T* aux = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];

	delete[] this->elems;
	this->elems = aux;
}