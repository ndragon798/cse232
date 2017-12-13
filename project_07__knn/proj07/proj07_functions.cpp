// author : Nathan Easton
// date : 10/30/17
// Project : 7
/*
Uses a distance functions to make a map for a machine learning algorithm
*/
#include "proj07_functions.h"
#include<iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h> 
#include <algorithm>
using std::sort;
using std::ifstream;
using std::iostream;
using std::to_string;
using std::fixed;
using std::setprecision;
using std::stringstream;
using std::cout; using std::endl; using std::boolalpha;

//takes in a string and char returns a vector of strings
vector<string> split(const string &s, char delim){
    vector<string> split_vector;
    string x=s;
    std::size_t found = x.find(delim);
    //loops while it finds the delimiter
    while(found!=std::string::npos){
        // cout<<x.substr(0,found);
        
        split_vector.push_back(x.substr(0,found));
        //takes a sub str and adds it to the vector
        x=x.substr(found+1);
        //sets x up to the next area after the previous substr
        found=x.find(delim);
    }
    split_vector.push_back(x);
    return split_vector;
}
//takes in a map of vector double and string an unsigned in , and a ifstream
void read_data(map<vector<double>, string> &m, unsigned int feature_count, ifstream &inf){
    string temp;
    int x;
    //whiel you can pull a line from the if stream do it
    while (std::getline(inf,temp)){
        vector<double> tempv;
        double temp_d;
        // cout<<temp<<endl;
        vector<string> test =split(temp,',');
        for (int i = 0; i < test.size()-1; i++) {
            // cout<<test[i]<<endl;
            temp_d=std::stod(test[i]);
            tempv.push_back(temp_d);
            // tempv.push_back(((double)test[i]));
        }
        
        m[tempv]=test[test.size()-1];//add them to map m
    }
}
//returns a string when given a pair of double and string
string pair_to_string(const pair<vector<double>, string> &p){
    stringstream stream;
    //adds item to the stream
    for (int i = 0; i < p.first.size(); i++) {
        stream << fixed << setprecision(3) <<p.first[i]<<" ";
    }
    // f_string+=p.second;
    stream<<p.second;
    string s = stream.str();
    return s;
}
//takes in map and ostream fills the ostream with stuff
void print_map(const map<vector<double>, string> &m, ostream &out){
    for (auto x: m) {
        out<<pair_to_string(x)<<"\n";
    }
}
//returns a double when given 2 bectors and an unsigned int
double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count){
    // double dist;
    double tmp;
    for (int i = 0; i < feature_count; i++) {
        tmp+=((v1[i]-v2[i])*(v1[i]-v2[i]));
    }return sqrt(tmp);//retunrs distance between the two vectors
}
//returns a map when given a map a vector and an int
map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, const vector<double> &test, int k){
    map<vector<double>,string> t_map;
    vector<double> tmp_v;
    double tmp_d;
    for (auto x:m){
        if (x.first != test){
            tmp_d=distance(x.first,test,x.first.size());//finds the distance for each item
            // cout<<tmp_d<<" ";
            tmp_v.push_back(tmp_d);
            // t_map[x.first]=x.second;
        }
        //  tmp_d=distance(x.first,test,x.first.size();
        //  cout<<tmp_d;
    }
    sort(tmp_v.begin(),tmp_v.end());
    // for (int i = 0; i < tmp_v.size(); i++) {
    //     cout<<tmp_v[i];
    // }
    int index=0;
    while(index<k){
        for (auto x:m){
            if (x.first != test){
                tmp_d=distance(x.first,test,x.first.size());
            }if(tmp_d==tmp_v[index] and index<k){
                t_map[x.first]=x.second;
                // cout<<index;
                // tmp_v.erase(tmp_v.begin()+index);
                index++;
            }
        }
    }
   return t_map;
}

double test_one(const map<vector<double>, string> &m, pair<vector<double>, string> test, int k){//calculates the distances for all the items in the map when given the vector
    // cout<<test.second<<endl;
    double df=0;
    auto t_map=k_neighbors(m,test.first,k);
    for (auto x:t_map){
        if (x.second==test.second){
            df++;
        }
    }
    df=df/3;
    return df;
}

// int main(){
// ifstream fin("little.txt");
// map<vector<double>, string> m;
// read_data(m,4,fin);
// auto start = m.begin();
// double result = test_one(m, *start, 3);
// cout<<result;
// // auto result = k_neighbors(m, start->first, 3);
// // for(auto x:result){
// //     cout<<x.second<<" ";
// //     for (int i = 0; i < x.first.size(); i++) {
// //         cout<<x.first[i]<<" ";
// //     }
// //     cout<<endl;
// // }
// }