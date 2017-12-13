#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<vector>
using std::vector;

#include "proj06_functions.h"

int main (){
//   cout << boolalpha;
//   string rule;
//   vector<int> v, temp;

//   // basic testing
//   cout << vector_to_string({1,0,1,0,1,0}) << endl;
  cout << to_binary(30) << endl;
//   cout << next_val({0,1,0}, "00011110") << endl;  // rule 30
//   cout << next_val({0,1,0}, "01011010") << endl;  // rule 90
//   read_vector(v, "inf.txt");
//   cout << vector_to_string(v) << endl;
//   v = {0,0,0,0,1,0,0,0,0};
//   temp = one_iteration(v, "00011110");  // rule 30
//   cout << vector_to_string(temp) << endl;

//   // let's see how she runs!
//   vector<int> v2(21,0);
//   v2[10] = 1;
//   rule = to_binary(60);
//   cout << rule << endl;
//   for(int i=0; i<10; ++i){
//     cout << pretty_print(v2) << endl;
//     //cout << vector_to_string(temp) << endl;    
//     v2 = one_iteration(v2, rule);
//   }


}
