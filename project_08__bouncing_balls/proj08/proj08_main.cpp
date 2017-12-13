// author : Nathan Easton
// date : 10/16/17
// Project : 8
// Section:014
/*
Simulate circle collison.
*/
#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<string>
using std::string;

#include "proj08_twod.h"
#include "proj08_ball.h"

int main (){
  cout << boolalpha;
  Ball b1 (1, {1, 1}, {1, 0}, 1);
  Ball b2 (1, {2, 1}, {-1, 0}, 1);
  Ball b3 (1, {1,5}, {-1,-1}, 1);
  cout << b1.to_string() << endl;
  cout << b1.contact_ball(b2) << endl;
  cout << b1.velocity.dot_product(b2.velocity) << endl;
//   TwoD d1 = b1.update_velocity_ball(b2);
//   cout << d1.to_string() << endl;
  cout << b3.contact_wall(10,10) << endl;
  TwoD d2 = b3.update_velocity_wall(10,10);
  cout << d2.to_string() << endl;
  Ball b4 (3, {9,2}, {1,1}, 1);
  cout << b4.to_string() << endl;
  d2 = b4.update_velocity_wall(10,10);
  cout << d2.to_string() << endl;
  Ball b5(1, {5,5}, {0,0}, 1);
  Ball b6(1, {7,7}, {0,-1}, 1);

//   cout << "====" << endl;
//   cout << "First: "<<b5.to_string() << endl;
//   cout << "Second: "<< b6.to_string() << endl;
//   TwoD new_v = b5.update_velocity_ball(b6);
//   cout << new_v.to_string() << endl;
//   new_v = b6.update_velocity_ball(b5);
//   cout << new_v.to_string() << endl;  
}
