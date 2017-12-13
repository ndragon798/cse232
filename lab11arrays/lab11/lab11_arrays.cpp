#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<fstream>
using std::ifstream;
#include<string>
using std::string;
#include <sstream>
using std::ostringstream;
#include <stdexcept>
using std::runtime_error;
#include "lab11_arrays.h"

bool is_even(long l){
    return(l%2==0);
}

void print_array(long ary[], size_t sz, ostream& out){
    int i;
    for (i = 0; i < sz-1; i++) {
        out<<ary[i]<<", ";
    }
    out<<ary[i];
}

size_t fill_from_file(long* (& ary), string f_name){
    ifstream file;
    
    file.open(f_name);
    if (!file.good()){
        throw runtime_error(f_name);
    }
    long size;
    int i;
    file >>size;
    ary=new long[size];
    int a=0;
    while (file >> i){
        ary[a]=i;
        a++;
    }
    return size;
    
}

size_t concatenate(long* (& ary1), size_t sz1, long ary2[], size_t sz2){
    long* ary=new long[sz1+sz2];
    for (int i = 0; i < sz1; i++) {//copy
        ary[i]=ary1[i];
    }
    for (int i = 0; i < sz2; i++) {//copy
        /* code */
        ary[i+sz1]=ary2[i];
    }
    // print_array(ary,sz1+sz2,cout);
    long *temp = ary1;
    ary1=ary;
    delete temp;
    return sz1+sz2;
}

pair<long*, size_t> copy_evens(long ary[], size_t sz){
    auto nsize=0;
    for (int i = 0; i < sz; i++) {
        if (ary[i]%2==0){
            nsize++;
        }
    }
    auto ind=0;
    long* ary1=new long[nsize];
    for (int i = 0; i < sz; i++) {
        if (ary[i]%2==0){
            ary1[ind]=ary[i];
            ind++;
        }
    }
    std::pair<long*,size_t> dsaf(ary1,nsize);
    return dsaf;
}

// int main(){
//     ostringstream oss;
//     // cout<< is_even(10);
//     // cout<<is_even(11);
//     long ary1[5]{1,2,3,4,5};
//     // print_array(ary1,5,cout);
//     long* ary2 = new long;
//     auto a=fill_from_file(ary2,"tables.txt");
//     long *ary3 = ary2;
//     ary3[0]=7;
//     // print_array(ary2,a,cout);
//     // delete [] ary2;
//     auto b=concatenate(ary3,5,ary2,5);
//     print_array(ary3,10,cout);
    
// }