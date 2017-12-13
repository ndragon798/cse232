// author : Nathan Easton
// date : 10/16/17
// Project : 8
// Section:014
/*
Simulate circle collison.
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using std::ostringstream;
using std::setprecision;
using std::cout; using std::endl;using std::fixed;
#include "proj08_twod.h"

//Constructor for TWoD
TwoD::TwoD(double xval,double yval){
   x=xval;
   y=yval;
}

//Converts TwoD to string in a ostringstream returns a stream
string TwoD::to_string(){
    ostringstream oss;
    oss <<fixed<<setprecision(2)<< "("<<x<<", "<<y<<")";
    
    return oss.str();
}

//Takes in a TwoD and gets the difference between TwoD 1 and TwoD 2
//Returns a TwoD
TwoD TwoD::diff(TwoD second){
    return TwoD(x-second.x,y-second.y);
}
//Takes in a double returns a TwoD
TwoD TwoD::mult(double a){
    //Multiplies TwoD by a double
    return TwoD(x*a,y*a);
}
//Takes in a TwoD returns a TwoD
//Performs Dot Product multiplication on the TwoD
double TwoD::dot_product(TwoD second){
    return((x*second.x)+(y*second.y));
}

//Returns a double of the TwoD magnitude.
double TwoD::magnitude_squared(){
    return((x*x)+(y*y));
}

// int main(){
//     auto test=TwoD(1.00,2.00);
//     auto test2=TwoD(2.00,3.00);
    
//     auto test3=test.magnitude_squared();
//     cout<<(test3);
    
// }