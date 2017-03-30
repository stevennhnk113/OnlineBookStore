//Steven Nguyen
//MemberList.cpp
//Oct 5, 2014

#include <iostream>
#include <string>
#include "MemberList.h"

using namespace std;
MemberList::MemberList(int initialCap):size(initialCap)
{
  count = 0;
  arr = new ElementType[size];
}

MemberList::MemberList(const MemberList &rhs)
{
  size = rhs.size;
  count = rhs.count;
  arr = new MemberList::ElementType[size];
  for(int i = 0; i < count; i++)
	arr[i] = rhs.arr[i];
}

MemberList& MemberList::operator=(const MemberList &rhs)
{
  if(this != &rhs){
	delete[] arr;
	size = rhs.size;
	count = rhs.count;
	arr = new MemberList::ElementType[size];
	for(int i = 0; i < count; i++)
	  arr[i] = rhs.arr[i];
  }
  return *this;
}

MemberList::ElementType& MemberList::operator[](int index)
{
  return arr[index];
}

int MemberList::insert(ElementType el)
{
  if(isFull())
	resize();

  arr[count++] = el;
  return count;
}

void MemberList::resize()
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

bool MemberList::isFull()
{
  if(count == size)
	return true;
  else
	return false;
	
}

MemberList::~MemberList()
{
  delete[] arr;
}

//void MemberList::display(int index, int books)
//{
//arr[index].getRating(books);
//}
