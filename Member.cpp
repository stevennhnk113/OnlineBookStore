//Steven Nguyen
//Member.cpp
//Oct 3, 2014

#include "Rating.h"
#include "Member.h"
#include <string>
#include <iostream>
using namespace std;


Member::Member(string _name, string _accName)
  :name(_name), accName(_accName){}

Member::Member(const Member &rhs)
{
  name = rhs.name;
  accName = rhs.accName;
  userRating = rhs.userRating;
}

Member& Member::operator=(const Member &rhs)
{
  if(this != &rhs){
	name = rhs.name;
	accName = rhs.accName;
	userRating = rhs.userRating;
  }
  return *this;
}

void Member::updateName(string _name)
{
  name = _name;
}
void Member::updateAccName(string _accName)
{
  accName = _accName;
}

void Member::insertRating(int _rate)
{
  userRating.insert(_rate);
}

void Member::changeRating(int _rate, int _index)
{
  userRating.change(_rate, _index); 
}

int Member::getRating(int index)
{
  return userRating[index];
}

string Member::getName()const
{
  return name;
}

string Member::getAccName()const
{
  return accName;
}

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

int MemberList::getCount()const
{
  return count;
}

MemberList::~MemberList()
{
  delete[] arr;
}
