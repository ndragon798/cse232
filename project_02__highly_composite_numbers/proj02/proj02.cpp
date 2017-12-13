// author : Nathan Easton
// date : 09/18/17
// your actual code
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
//Create varibles
long usr_in, num_divs, in_mod,mod_divs;
int main(){
    //Take in user input
cin >> usr_in;
num_divs=0;
mod_divs=0;
//Make sure input is greater than or equal to 1
if (usr_in >=1) {
    //For loop to usr_in
    for (int i = 1; i <= usr_in; i++) {
        //if it can be divided by i then add 1 to num_divs
        if (usr_in%i==0){
            num_divs++;
        }
    }
    /*
    Check to see if the numbers before are highly composite. 
    Its like the previous for loop except with another loop outside of it to    
    loop through all numbers prior
    */
    for (int i = 1; i < usr_in; i++) {
        for (in_mod = 1; in_mod<= i; in_mod++) {
            if (i%in_mod==0){
                mod_divs++;
            }
            
        }
        //check to see if mod_divs is greater than or equal to num_divs if it is then exit
        if (mod_divs>=num_divs){
            cout << "False " << usr_in << " " << in_mod-1 << " " << mod_divs;
            exit(0);
        }
        in_mod=0;
        mod_divs=0;
    }
    if (num_divs > mod_divs){
        cout << "True " << usr_in << " "<< num_divs;
    }
    }else{
        cout << "Error";
    }
}

/*
This code is a lot more shorter than what I write.
The writer use a lot of for loop in the project instead of using the while loop.
Every name in the project is clear and reasonable, easy to understand.
However, if I am the writer,
I would still want to write std:: every time when I use the code.
Just to make my code easier to read.
*/

/*
well commented
you used descriptive names
*/