//Steven Nguyen
//testList.cpp
//Oct 3, 2014

#include "List.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  List one;
  for(int i = 0; i < 10; i++){
	one.insert(i);
  }
  one.display(10);

  

  

  return 0;
}
