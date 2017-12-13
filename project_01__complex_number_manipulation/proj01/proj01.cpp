#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;

int main(){
    //declaring varibles;
    double real_one,real_two,img_one,img_two;
    
    cin>> real_one >> img_one >>real_two >> img_two;
    //adding;
    cout << fixed << setprecision (2)<< real_one+real_two << " + " << img_one+img_two << "i"<<endl;
    //subtraction;
    cout << fixed << setprecision (2)<< real_one-real_two << " + " << img_one-img_two << "i"<<endl;
    //multiplying;
    cout << fixed << setprecision (2)<< ((real_one*real_two)-(img_one*img_two)) << " + " << ((img_one*real_two)+(real_one*img_two)) << "i"<<endl;
    //dividing;
    cout << fixed << setprecision (2)<< ((real_one*real_two)+(img_one*img_two))/((real_two*real_two)+(img_two*img_two)) << " + " << ((img_one*real_two)-(real_one*img_two))/((real_two*real_two)+(img_two*img_two)) << "i"<<endl;
    
    
    

}