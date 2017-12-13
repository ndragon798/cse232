#include "proj09_trimap.h"
#include<iostream>
using std::cout; using std::endl;
#include <algorithm>
using std::binary_search;
using std::upper_bound;
#include <iomanip>
#include <sstream>
#include <string>
using std::ostringstream;

ostream& operator<<(ostream& os, const Element& e){
    os<<e.key_<<":"<<e.value_<<":"<<e.index_;
    return os;
}
ostream& operator<<(ostream& os, const TriMap& t){
    if (t.vec_.size()==0)
        return os;
    for (int i = 0; i < t.vec_.size(); i++) {
        os<<t.vec_[i];
        if (i!=t.vec_.size()-1)
            os<<", ";
    }
    return os;
}


TriMap::TriMap(const Element &e){
    vec_.push_back(e);
    sz_+=1;
}
TriMap::TriMap(initializer_list<Element> x){
    vec_=x;
    for (auto a:x){
        // cout<<a;
        sz_+=1;
    }
}

size_t TriMap::size(){
    return sz_;
}

bool TriMap::insert(string key,string value){
    Element e(key,value,sz_);
    // auto sv;
    auto loca=sz_;
    auto t=vec_.end();
    for (int i = 0; i < vec_.size(); i++) {
        if (vec_[i].key_==key) 
            return false;
        if (key<vec_[i].key_ && loca>i){
            loca=i;
            t=vec_.begin()+i;
            // cout<<i;
        }
        
    }
    vec_.insert(t,e);
    sz_++;
    // loca=loca+vec_.begin();
    // vec_.insert(loca,e);
    return true;
}

bool TriMap::remove(string key){
    size_t loca;
    for (int i = 0; i < vec_.size(); i++) {
        if (key==vec_[i].key_){
            loca=vec_[i].index_;
            vec_.erase(vec_.begin()+i);
            sz_--;
            for (int i = 0; i < vec_.size(); i++) {
                if(vec_[i].index_>loca){
                    vec_[i].index_--;
                }
            }
            return true;
        }
    }
    
    return false;
}

Element* TriMap::find_value(const string &value){
    auto find_pos = find_if(vec_.begin(), vec_.end(),
		[&value](Element e){
		  return e.value_ == value;
    		}
		);
	if (find_pos == vec_.end() )
    return nullptr;
  else
    return &(*find_pos);
}

Element* TriMap::find_index(size_t index){
    auto find_pos = find_if(vec_.begin(), vec_.end(),
		[&index](Element e){
		  return e.index_ == index;
    		}
		);
	if (find_pos == vec_.end() )
    return nullptr;
  else
    return &(*find_pos);
}

Element* TriMap::find_key(const string &key){
    Element e1(key,"0",0);
    // Element e2();
    auto ms_pos = upper_bound(vec_.begin(), vec_.end(), e1, [](const Element &e1, const Element &e2){
            // cout<<e1.key_<<e2.key_<<endl;
            return e1.key_<e2.key_;
            // return key<e.key_;
    });
    if ((*(ms_pos-1)).key_!=key)
        return nullptr;
    // cout <<*&(*ms_pos);
    return &(*(ms_pos-1));
}

// int main(){
//     TriMap m;
//     m.insert("w","x");
//     m.insert("c", "d");
//     m.insert("a","b");
//     m.insert("y","z");
//     Element* result = m.find_key("m");
    
//     cout<<*result;
// }
