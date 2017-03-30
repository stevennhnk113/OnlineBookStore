//Steven Nguyen
//RatingList.cpp
//Oct 5, 2014

#include <iostream>
#include <string>
#include "Rating.h"

using namespace std;
Rating::Rating(int initialCap):size(initialCap)
{
  count = 0;
  arr = new ElementType[size];
}

Rating::Rating(const Rating &rhs)
{
  size = rhs.size;
  count = rhs.count;
  arr = new ElementType[size];
  for(int i = 0; i < count; i++)
	arr[i] = rhs.arr[i];
}

Rating& Rating::operator=(const Rating &rhs)
{
  if(this != &rhs){
	delete[] arr;
	size = rhs.size;
	count = rhs.count;
	arr = new Rating::ElementType[size];
	for(int i = 0; i < count; i++)
	  arr[i] = rhs.arr[i];
  }
  return *this;
}

Rating::ElementType& Rating::operator[](int index)
{
  return arr[index];
}

void Rating::insert(ElementType el)
{
  if(isFull())
	resize();

  arr[count++] = el;
}

void Rating::resize()
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

bool Rating::isFull()
{
  if(count == size)
	return true;
  else
	return false;
}

void Rating::change(ElementType rate, int index)
{
  arr[index] = rate;
}

Rating::~Rating()
{
  delete[] arr;
}
