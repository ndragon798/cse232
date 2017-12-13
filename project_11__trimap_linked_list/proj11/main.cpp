#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::swap;
#include<string>
using std::string;

#include "proj11_trimap.h"

int main(){

TriMap<long,long> m1;
m1.insert(2,20);
m1.insert(1,10);
m1.insert(4,40);
m1.insert(3,30);

TriMap<long, long> m2;
m2 = m1;
m2.insert(5,50);
m2.remove(4);

ostringstream oss1;
cout << m1<<endl;
string s1 = oss1.str();
string ans1 = "1:10:1, 2:20:0, 3:30:3, 4:40:2";
// ASSERT_EQ(s1,ans1);

ostringstream oss2;
cout << m2;
string s2 = oss2.str();
string ans2 = "1:10:1, 2:20:0, 3:30:2, 5:50:3";
// ASSERT_EQ(s2,ans2);


}