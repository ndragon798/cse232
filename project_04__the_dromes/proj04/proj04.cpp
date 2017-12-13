// author : Nathan Easton
// date : 10/02/17
#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;
const string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";
bool correctbase(string n,int base){
    //brings in a string and an int
    //returns a bool
    //loops through and makes sure the string n is the correct base
    for (int i = 0; i < n.length(); i++) {
        // cout<<n.at(i)-'0'<<" "<<base-1<<endl;
        if (base<=10 and n.at(i)-'0'>9){
            return false;
        }
    }return true;
    
}
bool metadrome(string n,int base){
    //brings in a string and an int
    //returns a bool
    //loops through and checks that string n is the metadrop
    if (!correctbase(n,base))return false;
    int start=n.at(0)-'0';
    for (int i = 1; i < n.length(); i++) {
        if ((n.at(i)-'0')==(start+1)){
             start++;
        }else{return false;}
    }return true;
}
bool plaindrome(string n,int base){
    //brings in a string and an int
    //returns a bool
    //loops through and checks that string n is the metadrop
    if (!correctbase(n,base))return false;
    int start=n.at(0)-'0';
    for (int i = 1; i < n.length(); i++) {
        if ((n.at(i)-'0')==(start+1)||(n.at(i)-'0')==(start)){
            if((n.at(i)-'0')==(start+1)){
             start++;
            }
        }else{return false;}
    }return true;
}
bool katadrome(string n,int base){
    //brings in a string and an int
    //returns a bool
    //loops through and checks that string n is the metadrop
    if (!correctbase(n,base))return false;
    int start=n.at(0)-'0';
    for (int i = 1; i < n.length(); i++) {
        if ((n.at(i)-'0')==(start-1)){
             start--;
        }else{return false;}
    }return true;
}
bool nialpdrome(string n,int base){
        //brings in a string and an int
    //returns a bool
    //loops through and checks that string n is the metadrop
    if (!correctbase(n,base))return false;
    int start=n.at(0)-'0';
    for (int i = 1; i < n.length(); i++) {
        if ((n.at(i)-'0')==(start-1)||(n.at(i)-'0')==(start)){
            if((n.at(i)-'0')==(start-1)){
             start--;
            }
        }else{return false;}
    }return true;
}
string classify(string n,int base){
    //brings in a string and an int
    //returns a bool
    //loops through and checks each case  and returns
    if (metadrome(n,base)){
        return "metadrome";
    }else if (plaindrome(n,base)){
        return "plaindrome";
    }else if (katadrome(n,base)){
        return "katadrome";
    }else if (nialpdrome(n,base)){
        return "nialpdrome";
    }else{return "nondrome";}
}
int main (){
  string num;
  long base;
  cout << boolalpha;
  cin >> num >> base;
  cout << metadrome (num, base) << " "
       << plaindrome (num, base) << " "
       << katadrome (num, base) << " "
       << nialpdrome (num, base) << " "
       << classify(num, base) << endl;
}