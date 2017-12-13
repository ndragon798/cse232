#include<iostream>
using std::cout; using std::endl;

#include<vector>
using std::vector;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include<string>
using std::string; using std::to_string;
#include<iomanip>
using std::boolalpha;
#include<cassert>
#include "proj10_package.h"
#include "proj10_knapsack.h"

int main(){

  cout << boolalpha;

  Package p(1,1);
  assert(p.weight_ == 1);
  assert(p.priority_ == 1);

  Knapsack ks(25,2);
  assert(ks.empty() == true);
  cout << ks.empty() <<endl;
  cout << ks.add(Package(10,10)) << endl;
  cout << ks.add(Package(10,10)) << endl;  
  cout << ks.add(Package(10,10)) << endl;
  cout << "Size:" << ks.size() << endl;
  cout << "Weight:" << ks.weight() << endl;
  cout << "Capacity:" << ks.capacity() << endl;
  cout << "Priority:" << ks.priority() << endl;
  cout << ks << endl;
  cout << ks.add(Package(2,10)) << endl;  
  cout << "Size:" << ks.size() << endl;
  cout << "Weight:" << ks.weight() << endl;
  cout << "Capacity:" << ks.capacity() << endl;
  cout << "Priority:" << ks.priority() << endl;
  
  cout << ks << endl;


  Knapsack copy_ks(ks);
  cout << "Copy: "<< copy_ks << endl;

  Knapsack ks2(15, 3);
  solve_KS("packages.txt", ks2);
  cout << ks2 << endl;
  cout << "Weight:"<<ks2.weight() << endl;
  cout << "Priority:"<<ks2.priority() << endl;
}
		 
