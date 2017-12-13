#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using std::ostringstream;
using std::setprecision;
using std::cout; using std::endl;using std::fixed;
#include "lab09_vector.h"

string vec_to_str(MathVector &v){
    ostringstream oss;
    oss <<fixed<<setprecision(2)<<v.x<<":"<<v.y;
    
    return oss.str();
}

MathVector::MathVector(long xval,long yval){
   x=xval;
   y=yval;
}

MathVector MathVector::add(const MathVector &v){
    return MathVector(x+v.x,y+v.y);
}
MathVector MathVector::mult(long k){
    return MathVector(x*k,y*k);
}
long MathVector::mult(const MathVector &v){
    return ((x*v.x)+(y*v.y));
}
double MathVector::magnitude(){
    return sqrt(((x*x)+(y*y)));
}

// int main(){
//     auto m=MathVector(1,2);
//     auto v=m.add(MathVector(2,3));
//     cout<<vec_to_str(v);
// }