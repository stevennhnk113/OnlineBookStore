//Steven Nguyen
//List.cpp
//Oct 3, 2014

#include <iostream>
#include <string>
#include "List.h"
using namespace std;
List::List(int initialCap):size(initialCap)
{
  count = 0;
  arr = new ElementType[size];
}

List::List(const List &rhs)
{
  size = rhs.size;
  count = rhs.count;
  arr = new ElementType[size];
  for(int i = 0; i < count; i++)
	arr[i] = rhs.arr[i];
}

List& List::operator=(const List &rhs)
{
  if(this != &rhs){
	delete[] arr;
	size = rhs.size;
	count = rhs.count;
	arr = new ElementType[size];
	for(int i = 0; i < count; i++)
	  arr[i] = rhs.arr[i];
  }
  return *this;
}

ElementType& List::operator[](int index)
{
  return arr[index];
}

void List::insert(ElementType el)
{
  if(isFull())
	resize();

  arr[count++] = el;	
}

void List::resize()
{
  int tempSize ;
  tempSize = size*2;
  ElementType *temp = new ElementType[tempSize];
  for(int i = 0; i < size; i++)
	temp[i] = arr[i];
  delete[] arr;
  arr = temp;
  size = tempSize;
}

bool List::isFull()
{
  if(count == size)
	return true;
  else
	return false;
	
}

List::~List()
{
  delete[] arr;
}
