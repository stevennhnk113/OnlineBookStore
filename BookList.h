//Steven Nguyen
//BookList.h
//Oct 5, 2014

#include "Book.h"
#include <iostream>
#include <string>

#ifndef BOOKLIST_H
#define BOOKLIST_H
using namespace std;

class BookList
{
 public:
  typedef Book ElementType;
  BookList(int initialCap = INITIALCAP);
  BookList(const BookList &rhs);
  BookList& operator=(const BookList &rhs);
  //ostream& operator<<(ostream &out, const Book &rhs);
  ElementType& operator[](int index);
  void insert(ElementType el);
  //Pre: none
  //Post: none
  ~BookList();
 private:
  void resize();
  bool isFull();  

  static const int INITIALCAP = 50;
  int size,
	count;
  ElementType *arr;
};

#endif
