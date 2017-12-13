#include<vector>
using std::vector;
#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include<iostream>
using std::cout; using std::cin; using std::endl;
#include "lab08_functions.h"

long collatz_next(long n) {
    if (n == 1)
        return 1;
    if (n <= 0) {
        throw std::range_error("test");
    }

    if (n % 2 == 0)
        return (long)n / 2;

    return (long)((3 * n) + 1);
}

string Collatz_to_string(const Collatz &p) {
    string f_string = "";
    f_string += std::to_string(p.first) + ": ";
    for (int i = 0; i < p.second.size(); i++) {
        /* code */
        f_string += std::to_string(p.second[i]) + ",";
    }
    f_string.pop_back();
    return f_string;
    // f_string+=p.first();
}
string sequence_in_map_to_string(map<long, vector<long> > &m, long number) {
    std::map<long, vector<long>>::iterator it;
    it = m.find(number);
    if (it != m.end()) {
        return Collatz_to_string(*it);
    }
    //for(std::map<long, vector<long>::iterator it=m.begin(); )
}
vector<long> collatz_sequence(map<long, vector<long> > &m, long number) {
    vector<long> out;
    long store=number;
    while (number > 1) {
        std::map<long, vector<long>>::iterator it;
        it = m.find(number);
        //if found in map
        if (it != m.end()) {
            // out.append((*it).second);
            // out.insert(out.end(),(*it).second.begin(),(*it).second.end());
            for (int i = 0; i < (*it).second.size(); i++) {
                out.push_back((*it).second[i]);
            }
            return out;
        }
        else {
            out.push_back(collatz_next(number));
            // m[number]=out;
            number = collatz_next(number);
        }
    }
    m[store]=out;
    return out;
}
void collatz_range(map<long, vector<long> > &m, long low, long high) {
    for (long i = low; i <= high; i++) {
        vector<long> v=collatz_sequence(m,i);
        // for (int i = 0; i < v.size(); i++) {
        //     cout<<v[i]<<" ";
        // }
        
    }
}
int main(){
    std::map<long,vector<long>> m;
    //m[1] = {4,62,3,7};
    //m[2] = {1,2,3,4};
    //m[3] = {12,17,78,69};
    // vector<long> v =collatz_sequence(m,20);
    // for (int i = 0; i < v.size(); i++) {
    //     /* code */
    //     cout<<v[i]<<endl;
    // }
    collatz_range(m,2,50);
    cout << m.find(50)->first;
    for (int i=0; i < (m.find(50)->second).size(); i++) {
        cout << ((m.find(50)->second)[i])<< endl;
    }
    //Collatz c=Collatz(2,{1,2,3,4});
    //cout<< Collatz_to_string(c);
    // cout<< sequence_in_map_to_string(m,3) << endl;
}