// author : Nathan Easton
// date : 10/16/17
// Project : 10
// Secion : 14
/*
Makes a bag to hold packages in with dynamically resized arrays of packages.
*/

#include<iostream>
using std::ostream;
#include<string>
#include<initializer_list>
using std::string;
using std::cout; using std::endl;
 using std::copy; using std::swap;
#include <stdexcept>
#include<fstream>
using std::runtime_error;
using std::ifstream;


#include "proj10_package.h"
#include "proj10_knapsack.h"
//Constructor for knapsack
Knapsack::Knapsack(size_t wlimit){
    data_=new Package[capacity_];
    weight_limit_=wlimit;
}
//Constructor for knapsack
Knapsack::Knapsack(size_t wlimit, size_t cap){
    data_=new Package[cap];
    weight_limit_=wlimit;
    capacity_=cap;
}
//Constructor for knapsack using another knapsack to make a copy
Knapsack::Knapsack(const Knapsack& k){
    
    data_=new Package[k.capacity_];
    weight_limit_=k.weight_limit_;
    capacity_=k.capacity_;
    size_=k.size_;
    copy(k.data_,k.data_+k.size_,data_);
    
}
// void Knapsack::swap(Knapsack &k){
//     using std::swap;
        
//     swap(this->weight_limit_,k.weight_limit_);
//     swap(this->capacity_,k.capacity_);
//     swap(this->size_,k.size_);
//     swap(this->data_,k.data_);
//     delete [] k.data_;
    
    
// }

//Deconstructs the Knapsack object by deleting its data_;
Knapsack::~Knapsack(){
    delete [] data_;
}

// Knapsack& Knapsack::operator=(const Knapsack k){
//         swap(k);
//         // this->capacity_=k.capacity_;
//         // this->weight_limit_=k.weight_limit_;
//         // this->size_=k.size_;
//         // this->data_=k.data_;
//         // delete [] k.data_;
//         return *this;
//     };
//Returns the knapsacks capacity
long Knapsack::capacity() const{
    return capacity_;
}
//Returns the knapsacks size
long Knapsack::size() const{
    return size_;
}
//Returns the knapsacks weight_limit
long Knapsack::weight_limit() const{
    return weight_limit_;
}
//Returns if the knapsack is full or not
bool Knapsack::empty() const{
    if (size_==0)
        return true;
    else
        return false;
}
//Returns the total priority of all the packages in it.
long Knapsack::priority() const{
    if(size_==0)
        return 0;
    auto p=0;
    for (int i = 0; i < size_; i++) {
        // cout<<data_[i]<<endl;
        p+=data_[i].priority_;
    }
    return p;
}
//Returns the total weight of all the packages in side of it.
long Knapsack::weight() const{
    if(size_==0)
        return 0;
    auto w=0;
    for (int i = 0; i < size_; i++) {
        // cout<<data_[i]<<endl;
        w+=data_[i].weight_;
    }
    return w;
}
//Adds objects to the knapsack if the objects are below capacity if they are above then it adds more room until weight limit is hit.
bool Knapsack::add(const Package &p){
    if (p.weight_+weight()>weight_limit_)
        return false;
    else{
        if (size_+1==capacity_){
            Package *new_ary = new Package[capacity_ * 2]{};
            copy(data_, data_+capacity_, new_ary);
            capacity_ *= 2;
            // stl swap, not Stack swap
            std::swap (new_ary, data_);
            delete [] new_ary;
            data_[size_]=p;
            size_++;
        }
        else{
        data_[size_]=p;
        size_++;
            
        }
        
        return true;
        
    }
}
//Just a print operator.
ostream& operator<<(ostream& os, Knapsack &k){
    if (k.size_==0){
        return os;
    }
    for (int i = 0; i < k.size_; i++) {
        os<<k.data_[i];
        if (i<k.size_-1){
            os<<", ";
        }
    }
    return os;
}
//Reads in packaages from a datafile then loops through and sorts them and adds them to the knapsack based on prority to weight ratio.
void solve_KS(string s,Knapsack &k){
    ifstream file;
    ifstream file1;
    
    file.open(s);
    if (!file.good()){
        throw runtime_error(s);
    }
    int a=0;
    string content;
    
    while(file>>content){
        a++;
    }
    file1.open(s);
    // cout<<"test";
    auto data=new Package[a/2];
    int q=0;
    while(file1 >> content) {
        // cout<<"test";
        auto w=0;auto p=0;
        
        w=std::stol(content);
        // cout<<w<<" ";
        file1 >> content;
        p=std::stol(content);
        // cout<<p<<endl;
        
        data[q]=Package(w,p);
        q++;
    }
    bool flip=true;
    for (int i = 0; i < q; i++) {
        /* code */
        // cout<<data[i]<<endl;
    }
    int x=0;
    // cout<<q<<endl;
    // cout<<data[0]<<" "<<data[1]<<" "<<data[2]<<" "<<data[3]<<" "<<data[4]<<" "<<data[5]<<" "<<data[6]<<endl;
    while(x!=100){//Sorts the data by protity to weight ratio 
        for (int i = 0; i <q-1 ; i++) {
            // cout<<i;
            if (package_compare(data[i],data[i+1])){
                // cout<<data[i]<<" "<<data[i+1];
                //Fliips them if they are in the wrong order
                auto temporary_element = data[i];
                data[i] = data[i+1];
                data[i+1] = temporary_element;
            }
    }x++;
    }
    //Did something with the duplicates which wasnt specified in the pdf
    for (int i = 0; i <q-1 ; i++) {
        if (data[i].weight_==data[i+1].weight_ && data[i].priority_==data[i+1].priority_){
            data[i].weight_=0;
            data[i].priority_=data[i].priority_-1;
            // cout<<"DUP"<<data[i]<<"DUP"<<endl;
        }
    }//Finally add all of them to the data
    for (int i = 0; i < q; i++) {
        // cout<<data[i]<<endl;
        // if(data[i].weight_!=-1 && data[i].priority_!=-1)
        k.add(data[i]);
    }
    
}

// main(){
//     long l;
//     // cout<<"test";
//     Knapsack ks(51,3);
//     cout<<ks;
//     solve_KS("packages.txt", ks);
//     cout<<ks<<endl;
//     cout<<ks.weight()<<" "<<ks.priority();
//     }