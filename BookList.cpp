//Steven Nguyen
//BookList.cpp
//Oct 5, 2014

#include <iostream>
#include <string>
#include "BookList.h"
#include "Book.h"
using namespace std;

BookList::BookList(int initialCap):size(initialCap)
{
  count = 0;
  arr = new ElementType[size];
}

BookList::BookList(const BookList &rhs)
{
  size = rhs.size;
  count = rhs.count;
  arr = new ElementType[size];
  for(int i = 0; i < count; i++)
	arr[i] = rhs.arr[i];
}

BookList& BookList::operator=(const BookList &rhs)
{
  if(this != &rhs){
	delete[] arr;
	size = rhs.size;
	count = rhs.count;
	arr = new BookList::ElementType[size];
	for(int i = 0; i < count; i++)
	  arr[i] = rhs.arr[i];
  }
  return *this;
}

/*ostream& BookList::operator<<(ostream &out, const Book &rhs)
{
  rhs.display(out);
  return out;
  }*/

BookList::ElementType& BookList::operator[](int index)
{
  return arr[index];
}

void BookList::insert(ElementType el)
{
  if(isFull())
	resize();

  arr[count++] = el;	
}

void BookList::resize()
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

bool BookList::isFull()
{
  if(count == size)
	return true;
  else
	return false;
	
}

BookList::~BookList()
{
  delete[] arr;
}
