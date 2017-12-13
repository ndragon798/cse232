#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<fstream>
using std::ifstream;
#include<utility>
using std::pair;

#include "proj07_functions.h"

int main (){
  map<vector<double>, string> m;
  // ifstream f("little.txt");
  ifstream f("iris.data.txt");
  read_data(m, 4, f);
  print_map(m, cout);
  auto start = m.begin();
  auto follow = next(start, 1);
  cout << distance(start->first, follow->first, 4) << endl;
  auto result = k_neighbors(m, start->first, 3);
  cout << "test: " << pair_to_string(*m.begin() ) << endl;
  print_map(result, cout);
  cout << "Accuracy for first: "<<test_one(m, *(m.begin() ), 3) << endl;
  cout << "Accuracy for all: " << test_all(m, 3) << endl;
}
