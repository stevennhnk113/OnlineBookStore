//Steven Nguyen
//main.cpp
//Oct 4, 2014

#include "Member.h"
#include "Rating.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char welcome();

void goodbye();

int menu();

bool loadData(string &bfile, string &rfile, BookList &_books,
			  MemberList &_members, int &_count, int &_userCount);

void saveData(string &bfile, string &rfile, BookList &_books,
			  MemberList &_members, int &_bookount, int &_userCount);

void login(MemberList &_members, int &_userCount, int &login);

void logout(int &login);

int addMember(MemberList &_members, int _bookCount);

int addBook(BookList &_books, MemberList members, int &_userCount);

void viewRatings(MemberList &_members, BookList &_books,
				 int login, int _bookCount);

void rateABook(MemberList &_members, BookList &_books, int login,
			   int _bookCount);

void seeRecBooks(MemberList &_members, BookList &_books, int login,
				 int _bookCount, int _userCount);


const string BOOKF = "books.txt",
  RATINGF = "ratings.txt";

const char YES = 'y',
  NO = 'n';

const int NOTLOGIN = -1,
  INITIALRATING = 0,
  MOSTFAV = 5;

int main()
{
  string bFile, rFile;
  
  BookList books;
  MemberList members;
  
  char again;

  int menuChoice,
	bookCount = 0,
	userCount = 0,
	loginIndex = NOTLOGIN;

  bool done = false;
  
  again = welcome();
	
  while(again == YES){
	if(done == false)
	  done = loadData(bFile, rFile, books, members, bookCount, userCount);
	menuChoice = menu();
	
	switch (menuChoice){
	case 1: login(members, userCount, loginIndex);
	  break;
	case 2: logout(loginIndex);
	  break;
	case 3: userCount = addMember(members, bookCount);
	  break;
	case 4: bookCount = addBook(books, members, userCount);
	  bookCount++;
	  break;
	case 5: viewRatings(members, books, loginIndex, bookCount);
	  break;
	case 6: rateABook(members, books, loginIndex, bookCount);  
	  break;
	case 7: seeRecBooks(members, books, loginIndex, bookCount, userCount);
	  break;
	case 8: again = NO;
	  break;
	default: cout << "Unavailable Option. Please enter again"
				  << endl;
	}
  }
  saveData(bFile, rFile, books, members, bookCount, userCount);
  goodbye();
  return 0;
}

char welcome()
{
  char again;
  cout << endl << endl;
  cout << "    Welcome to the book rating wizard!!!" << endl;
  cout << "Do you want to use the book rating wizard?(y/n): ";
  cin >> again;
  cin.ignore();
  return again;
  
}

void goodbye()
{
  cout << endl << endl
	   << "Thank you for using this program!!!" << endl << endl;
}

int menu()
{
  int num;
  cout << endl << endl;
  cout << "Please choose what you want to do: " << endl
	   << "1.Login" << endl
	   << "2.Logout" << endl
	   << "3.Add a member" << endl
	   << "4.Add a new book" << endl
	   << "5.View your ratings" << endl
	   << "6.Rate a book" << endl
	   << "7.See recommended books" << endl
	   << "8.Quit the wizard" << endl;
  cout << "Enter here: ";
  cin >> num;
  cin.ignore();
  return num;
}

bool loadData(string &bfile, string &rfile, BookList &_books,
			  MemberList &_members, int &_bookCount, int &_userCount) 
{
  
  Book tempBook;
  Member tempMember;
  string tempName;
  
  int num;
  ifstream read;
  
  //Reading in the books.txt
  cout << "Please enter books file's name: ";
  cin >> bfile;
  cin.ignore();
  read.open(bfile);
  if(read.fail()){
	return false;
  }
  
  while(getline(read, tempName, ',')){
	tempBook.updateAuthor(tempName);
	getline(read, tempName);
	tempBook.updateName(tempName);
	
	_books.insert(tempBook);
  }
  _bookCo unt = _books.getCount();
  read.close();

  //Reading in the ratings.txt
  cout << "Please enter rating file's name: ";
  cin >> rfile;
  cin.ignore();
  read.open(rfile);
  if(read.fail()){
  return false;
  }
  
  while(getline(read, tempName)){
	tempMember.updateName(tempName);
	tempMember.updateAccName(tempName + "123");
	_userCount = _members.insert(tempMember);

	for(int i = 0; i < _bookCount; i++){
	  read >> num;
	  _members[_userCount-1].insertRating(num);
	}
	read.ignore();
	read.ignore();
  }
  _userCount = _members.getCount();
  read.close();  
  return true;
}

void saveData(string &bfile, string &rfile, BookList &_books,
			  MemberList &_members, int &_bookCount, int &_userCount)
{
  ofstream write;
  int num;
  write.open(bfile);
  for(int i = 0; i < _bookCount; i++){
	write << _books[i].getAuthorName() << ','OP
		  << _books[i].getBookName() << endl;
  }
  write.close();
  
  write.open(rfile);
  for(int i = 0; i < _userCount; i++){
	write << _members[i].getName() << endl;
	for(int j = 0; j < _bookCount; j++){
	  num = _members[i].getRating(j);
	  write << num << ' ';
	}
	write << endl;
  }
  write.close();  
}

void login(MemberList &_members, int &_userCount, int &login)
{
  string userName;
  int index = 0;

  if(login != NOTLOGIN){
	cout << "You have already log in." << endl
		 << "Please press enter to continue...";
	cin.ignore();
	return;
  }	
  
  cout << endl << endl;
  cout << "Please enter your user name: " << endl
	   << "Hints: in case you do not know your username, " << endl
	   << "       it maybe your name with 123 at the end, " << endl
	   << "       for example: John123" << endl
	   << "Enter here: ";
  cin >> userName;
  cin.ignore();
  
  //Finding the user name
  while(index < _userCount && userName != _members[index].getAccName())
	index++;

  if(index == _userCount){
	cout << "User name does not exist..." << endl
		 << "Press enter to continue...";
	cin.ignore();
	login = -1;
	return;
  }

  login = index;
  cout << "Login done..." << endl
	   << "Press enter to continue...";
  cin.ignore();
}

void logout(int &login)
{
  cout << endl << endl;
  if(login == NOTLOGIN){
	cout << "You are not loging in..." << endl
		 << "Please press enter to continue...";
	cin.ignore();
  }else{
	login = NOTLOGIN;
	cout << "Logout done..." << endl
		 << "Please press enter to continue...";
	cin.ignore();
  }
}
int addMember(MemberList &_members, int _bookCount)
{
  string name,
	accName;
  Member tempMember;

  cout << endl << endl;
  cout << "Adding member..." << endl
	   << "Please enter member's name: ";
  getline(cin, name);
  tempMember.updateName(name);

  cout << "Please enter member's login user name: ";
  getline(cin, accName);
  tempMember.updateAccName(accName);
  cout << "Added member." << endl;

  //Giving this new member 0 ratings for all the books
  for(int i = 0; i < _bookCount; i++){
	tempMember.insertRating(INITIALRATING);
  }
  _members.insert(tempMember);
  return _members.getCount();
}

int addBook(BookList &_books, MemberList members, int &_userCount)
{
  Book tempBook;  
  string name,
	author,
	iSBN;
  int year;

  cout << endl << endl;
  cout << "Adding book..." << endl
	   << "please enter book's name: ";
  getline(cin, name);
  cout << "Please enter author's name: ";
  getline(cin, author);
  cout << "Please enter ISBN number: ";
  getline(cin, iSBN);
  cout << "Please enter year published: ";
  cin >> year;
  cin.ignore();

  tempBook.updateName(name);
  tempBook.updateAuthor(author);
  tempBook.updateISBN(iSBN);
  tempBook.updateYear(year);
  _books.insert(tempBook);

  //Giving all the member 0 rating for this new book
  for(int i = 0; i < _userCount; i++){
	members[i].insertRating(INITIALRATING);
  }
  return _books.getCount();
}

void viewRatings(MemberList &_members, BookList &_books,
				 int login, int _bookCount)
{
  int num;
  if(login == NOTLOGIN){
	cout << "You are not loging in..., please login" << endl
		 << "Press enter to continue..";
	cin.ignore();
	return;
  }
  cout << "Your rating is: " << endl;
  for(int i = 0; i < _bookCount; i++){
	num = _members[0].getRating(i);
	cout << num << '.' << _books[i].getName()
		 << endl;
  }  
}

void rateABook(MemberList &_members, BookList &_books, int login, int _bookCount)
{
  int num,
	rate;
  if(login == NOTLOGIN){
	cout << "You are not loging in..., please login" << endl
		 << "Press enter to continue..";
	cin.ignore();
	return;
  }
  
  cout << "Please choose a book by it order number..." << endl;
  for(int i = 0; i < _bookCount; i++){
	cout << i+1 << '.' << _books[i].getAuthorName()
		 << ", " << _books[i].getBookName() << endl;
  }
  
  cout << "Enter here: ";
  cin >> num;
  cout << "How do you want to rate that book..." << endl
	   << " 5: Really Like it!" << endl
	   << " 3: Liked it!" << endl
	   << " 1: ok - neither hot nor cold about it" << endl
	   << " 0: Haven't read it" << endl
	   << "-3: Didn't like it" << endl
	   << "-5: Hated it!" << endl
	   << "Enter here: ";
  cin >> rate;
  cin.ignore();
  _members[login].changeRating(rate, num-1);
  cout << "Rating complete...";
}

void seeRecBooks(MemberList &_members, BookList &_books, int login,
				 int _bookCount, int _userCount)
{
  int num1 = 0,
	num2 = 0,
	index;

  if(login == NOTLOGIN){
	cout << "You are not loging in..., please login" << endl
		 << "Press enter to continue..";
	cin.ignore();
	return;
  }
    
  //Looking for the user who have the most similar ratings
  for(int i = 0; i < _userCount; i++){
	if(login != i){
	  for(int j = 0; j < _bookCount; j++){
		num1 += _members[login].getRating(j)
		  * _members[i].getRating(j);
	  }
	}
	if(num1 > num2){
	  index = i;
	  num2 = num1;
	  num1 = 0;
	}else
	  num1 = 0;
  }
  
  //Searching for most favorite book
  cout << endl
	   << "Here you are..." << endl;
  
  for(int i = 0; i < _bookCount; i++){
	if(_members[index].getRating(i) == MOSTFAV)
	  cout << _books[i].getName() << endl;	
  }
}

