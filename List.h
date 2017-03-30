//Steven Nguyen
//List.h
//Oct 3, 2014

#include <iostream>
#include <string>
#ifndef LIST_H
#define LIST_H
using namespace std;

typedef int ElementType;

class List
{
 public:
  List(int initialCap = INITIALCAP);
  List(const List &rhs);
  List& operator=(const List &rhs);
  ElementType& operator[](int index);
  void insert(ElementType el);
  void display(int count);
  
  ~List();
 private:
  void resize();
  bool isFull();  

  static const int INITIALCAP = 50;
  int size,
	count;
  ElementType *arr;
};

#endif
