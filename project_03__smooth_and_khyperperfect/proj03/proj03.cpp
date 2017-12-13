// author : Nathan Easton
// date : 09/25/17
#include <iostream>
#include <iomanip>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

bool is_prime(long x){
    //brings in a long returns a boolean
    //Checks to see if the number is prime 
    //returns true if it is and false if not
    if (x==2||x==3||x==5||x==7){return true;}
    if (x%2==0 || x%3==0||x%5==0||x%7==0){
        return false;
    }
    long maxi=sqrt(x);
    for (int i = 3; i <= maxi; i++) {
        if (x%i==0){
            return false;
        }
    }
    return true;
}

long biggest_prime(long input){
    //brings in a long returns a long
    //returns the biggest prime factor of the input
    long big_prime;
    long input_counter=input/2;
    for (int i = 2; i < input_counter; i++) {
        if(i%2!=0 || i==2 ||i%3!=0 ||i==3 || i==5||i%5!=0){
            //cout<<i;
            if(input==1){return big_prime;}
            while (input%i==0 && is_prime(i)){
                if(input==1){return big_prime;}
                //cout<<i;
                input /=i;
                //cout<<input<<endl;
                big_prime=i;
                // return big_prime;
            }
        }
    }
    return big_prime;
    }

long sum_of_divisors(long input){
    //brings in a long returns a long
    //returns the sum of all the items that divide into the input evenly
    long total=0;
    for (int i = 1; i <= sqrt(input); i++) {
        if (input%i==0){
            total+=i;
            total+=input/i;
        }
    }
    return total;
}
long k_hyperperfect(long n,long k_max){
    //brings in 2 longs returns a long
    long k_hyper=0;
    long sum_of_divs=sum_of_divisors(n);
    for (int i = 0; i <= k_max; i++) {
        if (n==1+i*(sum_of_divs-n-1)){
            k_hyper=i;
        }
    }
    return k_hyper;
}
bool b_smooth(long n,long b){
    //Takes in 2 longs returns a boolean
    if (biggest_prime(n)<=b){
        return true;
    }
    return false;
}
int main(){
    //Declare Varibles
    long n,k_max,b;
    //Get inputs
    cin>> n >>k_max>>b;
    //Print
    cout <<biggest_prime(n)<<" ";
    cout <<sum_of_divisors(n)<<" ";
    cout <<k_hyperperfect(n,k_max)<<" ";
    cout << boolalpha<<b_smooth(n,b);

}
