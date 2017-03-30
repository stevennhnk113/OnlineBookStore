//Steven Nguyen
//Member.h
//Oct 2, 2014

#include "Rating.h"
#include <string>
#include <iostream>

#ifndef MEMBER_H
#define MEMBER_H
using namespace std;

class Member
{
 public:
  Member(string _name = "unknown", string _accName = "unknown");
  Member(const Member &rhs);
  Member& operator=(const Member &rhs);
  void updateName(string _name);
  //Pre: must be a string
  //Post: none
  void updateAccName(string _accName);
  //Pre: must be a string
  //Post: none
  void insertRating(int _rate);
  //Pre: rates must be 5, 3, 0, -3, or -5
  //Post: none
  void changeRating(int _rate, int _index);
  //Pre: rates must be 5, 3, 0, -3, or -5
  //Post: none
  int getRating(int index);
  //Pre: index must be smaller than number of user
  //Post: none
  string getName()const;
  //Pre: none
  //Post: none
  string getAccName()const;
  //Pre: none
  //Post: none
 private:
  string name,
	accName;
  Rating userRating;
};
#endif

#ifndef MEMBERLIST_H
#define MEMBERLIST_H
using namespace std;

class MemberList
{
 public:
  typedef Member ElementType;
  MemberList(int initialCap = INITIALCAP);
  MemberList(const MemberList &rhs);
  MemberList& operator=(const MemberList &rhs);
  ElementType& operator[](int index);
  int insert(ElementType el);
  //Pre: none
  //Post: array has 1 or more book instances
  int getCount()const;
  //Pre: none
  //Post: none
  ~MemberList();
 private:
  void resize();
  bool isFull();

  static const int INITIALCAP = 50;
  int size,
	count;
  ElementType *arr;
};

#endif
