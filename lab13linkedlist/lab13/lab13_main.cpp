#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;

#include "lab13_singlelink.h"

int main () {

  SingleLink<string>sl;
  sl.append_back("hello");
  sl.append_back("hello1");
  sl.append_back("hello2");
  sl.append_back("hello3");
  cout << sl << endl;
  // write test code below
  
}
