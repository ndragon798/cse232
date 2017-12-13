// author : Nathan Easton
// date : 10/16/17
// Project : 6
/*
Plays a 1d version of the game of life
*/
#include<string>
using std::string;
using std::to_string;
#include<vector>
using std::vector;
#include<algorithm>
using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
// any other includes you need
#include<iostream>
#include <fstream>
using std::ifstream;
using std::cout; using std::endl; using std::boolalpha;

#include "proj06_functions.h"

// your functions after this
// Divide the number by 2.
// Get the integer quotient for the next iteration.
// Get the remainder for the hex digit.
// Repeat the steps until the quotient is equal to 0.
string to_binary(int num){//Takes in an int returns a string
    if (num<=1 || num>255) {
        return "00000000";//Error checking
    }
    string f_string;
    while(num>0){//Converts to vinary
        int remain=num%2;
        f_string.push_back((char)(remain+'0'));
        num=num/2;
    }
    while (f_string.length()!=8){
        f_string.push_back('0');
    }
    reverse(f_string.begin(),f_string.end());//Reverses it because bin is backwards 

    return f_string;
}

int next_val(const vector<int> &v ,const string &rule_binary_string){//Takes in vector and string returns an int
    vector<vector<int>> rules= {{1,1,1},{1,1,0},{1,0,1},{1,0,0},{0,1,1},{0,1,0},{0,0,1},{0,0,0}};
    for (int i = 0; i < rules.size(); i++) {
        if (v==rules[i]){//returns the next value loops through all the possible bins
            // cout<<i<<endl;
            return (int)rule_binary_string[i]-48;
            
        }
    }
    
}
// a freebie!
// takes in a vector of 0,1
// outputs a string of '_' or '*'
string pretty_print(vector<int> & v){//Yall did this one
  ostringstream oss;
  transform(v.begin(), v.end(), ostream_iterator<char>(oss),
	    [] (int i) {
	      return (i==0) ? '_' : '*';
	    }
	    );
    return oss.str();
}
vector<int> one_iteration(const vector<int> &v,const string &rule_binary_string){//takes in vector and string returns a vector 
    vector<int> r_vector;
    for (int i = 0; i < v.size(); i++) {
        if (i==0){
            // cout<<0<<v[0]<<v[1]<<endl;
            r_vector.push_back(next_val({0,v[0],v[1]},rule_binary_string));
        }else if(i==v.size()-1){
            // cout<<v[v.size()-2]<<v[v.size()-1]<<0<<endl;
            r_vector.push_back(next_val({v[v.size()-2],v[v.size()-1],0},rule_binary_string));
        }else{
            // cout<<v[i-1]<<v[i]<<v[i+1]<<endl;
            r_vector.push_back(next_val({v[i-1],v[i],v[i+1]},rule_binary_string));
    }
    
    }
    // r_vector.push_back(0);
    // r_vector.push_back(0);
    return r_vector;
}    

string vector_to_string(const vector<int> &v){//takes in becor reutns string
    string f_string="";
    for (int i = 0; i < v.size(); i++) {
        /* code */
        char s=(char)v[i];
        s+='0';
        // cout<<s;
        f_string.push_back(s);
        f_string+=",";
    }
    f_string.pop_back();
    return f_string;
}
void read_vector(vector<int> &v,string fstring){//reads vector in from file
    ifstream inFile;
    int x;
    string f_string;
    inFile.open(fstring);
    while (inFile>>x){
        v.push_back(x);
    }
}
// int main(){
//     // vector<int> test=one_iteration({0,0,1,1,1,0,0}, "11011100");
//     // // cout<<next_val({0,1,0},"00011110")<<endl;
//     // for (int i = 0; i < test.size(); i++) {
//     //     cout<<test[i];
//     // }
//     // vector<int> v{0,0,0,1,0,0,0};
//     // cout<<vector_to_string(v);
//     vector<int> test;
//     read_vector(test,"inf.txt");
//     cout<<vector_to_string(test);
// }
