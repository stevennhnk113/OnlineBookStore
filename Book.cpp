//Steven Nguyen
//Book.cpp
//Oct 2, 2014

#include "Rating.h"
#include "Member.h"
#include "Book.h"
#include <string>

Book::Book(string bookName, string authorName, string iSBNnumber, int _year)
{
  name = bookName;
  author = authorName;
  iSBN = iSBNnumber;
  year = _year;
}

Book::Book(const Book &rhs)
{
  name = rhs.name;
  iSBN = rhs.iSBN;
  author = rhs.author;
  year = rhs.year;  
}

Book& Book::operator=(const Book &rhs)
{
  if(this != &rhs){
	name = rhs.name;
	iSBN = rhs.iSBN;
	author = rhs.author;
	year = rhs.year;
  }
  return *this;
}

void Book::updateName(string _name)
{
  name = _name;
}

void Book::updateAuthor(string _author)
{
  author = _author;
}
void Book::updateISBN (string _iSBN)
{
  iSBN = _iSBN;
}

void Book::updateYear (int _year)
{
  year = _year;
}

string Book::getName()const
{
  string book;
  book = author + ", " + name;
  return book;
}

string Book::getBookName()const
{
  return name;
}
string Book::getAuthorName()const
{
  return author;
}

  
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

BookList::ElementType& BookList::operator[](int index)
{
  return arr[index];
}

int BookList::insert(ElementType el)
{
  if(isFull())
	resize();

  arr[count++] = el;
  return count;
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

int BookList::getCount()const
{
  return count;
}

BookList::~BookList()
{
  delete[] arr;
}
