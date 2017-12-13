#include<iostream>
using std::ostream;

using std::cout; using std::endl;

#include "proj10_package.h"

ostream& operator <<(ostream& out, Package& p){
    out<<p.weight_<<":"<<p.priority_;
    return out;
}

bool package_compare(const Package &p1,const Package &p2){
    // auto p1rat=(p1.priority_/p1.weight_)
    return((p1.priority_/p1.weight_)>(p2.priority_/p2.weight_));
}

// int main(){
//     Package p(10,10);
//     cout<<p;
// }