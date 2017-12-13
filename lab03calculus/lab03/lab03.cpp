#include <iostream>
#include<iomanip>

using std::cout; 
using std::cin; 
using std::endl; 
using std::fixed;
using std::setprecision;

double fn(double x){//Takes in double x returns f(x)
    return (-6*(x*x))+(5*x)+3;
}
double integral(double x){//takes in double x returns f(x)
    return((-2*(x*x*x)) +((5.0/2.0)*(x*x))+(3*x));
}
double trapeizoid(double a,double b,long n){
    //Takes in double a,b and long n returns sum of area of n traps;
    
    double total=0;
    double delta_x = (b-a)/n;
   for (double i = 1; i <= n; i++) {
       //Calculates area of each indiviual trap and add them together.
    double delta_x_plus_x = a + i*(b-a)/n;
    double h1 = fn(delta_x_plus_x-delta_x);
    double h2 = fn(delta_x_plus_x);
    total += (delta_x/2) * (h1+h2);
   }return total;
}


int main(){//declare stuff
    float tol;
    int n;
    float a,b;
    a=0;
    b=1;
    float actual=integral(b)-integral(a);
    
    cin>>tol>>n;
    float estimate=trapeizoid(a,b,n);
    
    while(actual - estimate > tol){
        estimate=trapeizoid(a,b,n);
        n*=2;
    }//Print final stuff
    cout<<fixed<<setprecision(6)<<n/2<<" "<<estimate<<" "<<actual<<" "<<tol;
}