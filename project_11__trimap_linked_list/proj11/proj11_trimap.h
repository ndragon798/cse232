// author : Nathan Easton
// date : 12/06/17
// Project : 11
// Secion : 14
/*
its TriMap but with pointers :/
*/
#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::swap;
#include<string>
using std::string;

// forward declaration so we can make Element a friend of TriMap
template<typename K, typename V>
class TriMap;

// private Element, friend of TriMap class
template <typename K, typename V>
class Element{

private:
  K key_;
  size_t index_ = 0;
  Element *next_ = nullptr;  

public:
  V value_;
  
  Element() = default;
  Element(K key, V val, size_t i) : key_(key),index_(i), next_(nullptr), value_(val) {};

  // *defined* in the class, makes templating easier.
  friend ostream& operator<<(ostream& out, Element& e){
    out << e.key_ << ":" << e.value_ << ":" << e.index_;
    return out;
  }
  friend class TriMap<K,V>;
};


template<typename K, typename V>
class TriMap{

private:
  Element<K,V> *head_ = nullptr;
  Element<K,V> *tail_ = nullptr;
  size_t size_ = 1;
  
  // a private function, used by operator<<
  void print_list(ostream& out);
  
public:
  TriMap() = default;
  TriMap(K, V);
  TriMap(const TriMap&);
  TriMap& operator=(TriMap);
  ~TriMap();
  long size();
  bool insert(K,V);
  bool remove(K);
  Element<K,V>* find_key(K);
  Element<K,V>* find_value(V);
  Element<K,V>* find_index(size_t);  
  
  // *defined* in the class, makes templating easier.
  // uses private method print_list
  // you can remove print_list and just do it here if you
  // prefer. I won't test print_list
  friend ostream& operator<<(ostream& out, TriMap<K,V>& sl){
    sl.print_list(out);
    return out;
  };
};
//Takes in key and value and makes a TriMap with them.
template<typename K, typename V>
TriMap<K,V>::TriMap(K key, V value){
    Element<K,V>* ptr = new Element<K,V>(key,value,0);
    head_ = ptr;
    tail_ = ptr;
};

/* 
bit of work. we need to remember a pointer that walks
down the list to copy, as tail_ walks down the new list. 
Make a new node (copy the current node of the list we are copying), 
update the tail_->next_ to point to the new node, update tail_ to new node
 */
 
 //This was pretty much straight from the example.
 //just goes through and assigns the stuff from sl to new stuff then adds it to the TriMap
template<typename K, typename V>
TriMap<K,V>::TriMap(const TriMap& sl){
if (sl.head_ == nullptr){
	head_ = nullptr;
	tail_ = nullptr;
    }
    else{
	head_ = new Element<K,V>(sl.head_->key_,sl.head_->value_,sl.head_->index_);
	tail_ = head_;
	Element<K,V>* sl_ptr = sl.head_->next_;
	Element<K,V>* new_node;
	while (sl_ptr != nullptr){
	    new_node = new Element<K,V>(sl_ptr->key_,sl_ptr->value_,sl_ptr->index_);
	    tail_->next_ = new_node;
	    sl_ptr = sl_ptr->next_;
	    tail_ = new_node;
	}
    }
    
}
//straight from the example just swaps pointers
template<typename K, typename V>
TriMap<K,V>& TriMap<K,V>::operator=(TriMap tm){
    swap(head_, tm.head_);
    swap(tail_, tm.tail_);
    return *this;
}
	

// walk down the list using head_ , keeping a trailer pointer called to_del
// delete what to_del points to
// move head_ and to_del to the next node.
template<typename K, typename V>
TriMap<K,V>::~TriMap(){

}
//loops through and gens a size based on the amount of objects
template<typename K, typename V>
long TriMap<K,V>::size(){
      auto size=1;
    for(Element<K,V>* ptr = head_; ptr !=tail_; ptr = ptr->next_){
        size++;
    }
    return size;
}
//loops through and checks all cases and inserts it really a lot of work .
template<typename K, typename V>
bool TriMap<K,V>::insert(K key, V value){
  // very important, what are all the cases here!!!!
  // elements are inserted in *key order*
   auto k=key;
   size_t size=0;
  for(Element<K,V> *ptr = head_; ptr != nullptr; ptr = ptr->next_){
      if (ptr->key_==key){
        return false;
      }
    // cout<<ptr->key_;
    // cout<<size;
    size+=1;
  }
  
  if(head_==nullptr){
      Element<K,V>* ptra = new Element<K,V>(key,value,size);
    ptra->next_=head_;
    head_ = ptra;
    
  for(Element<K,V>* ptr = head_; ptr != nullptr; ptr = ptr->next_){
      tail_=ptr;
  }
  }
  else if(size==1){
        auto n = new Element<K,V>(key, value, size);
        if (head_->key_>key){
            head_=n;
            n->next_=tail_;
            // head_->next_=n;
            
        }else{
            head_->next_=n;
            tail_=n;
        }
  }else{
    auto n = new Element<K,V>(key, value, size);
    auto behind=head_;
    for(Element<K,V>* ptr = head_; ptr != nullptr; ptr = ptr->next_){
        if(key>ptr->key_){
            behind=ptr;
        }
        
    }
    if(behind!=head_ || key>head_->key_){
    auto temp=behind->next_;
    behind->next_=n;
    n->next_=temp;
         if (behind==tail_){
            tail_=n;
        }
    }else{
        if (behind==tail_){
            tail_=n;
        }
        n->next_=head_;
        head_=n;
        
    }
      
  }
  
  return true;
  
}
    //loops through finds the key then ignores it and counts down all the other objects with higher indexies
template<typename K, typename V>
bool TriMap<K,V>::remove(K key){
  // again, what are all the cases!!!
  // also, if you delete a node, the indicies of all
  // nodes with a higher index have that index reduced by one
  long index=-1;
  for(Element<K,V>* ptr = head_; ptr !=tail_; ptr = ptr->next_){
      auto nextptr=ptr->next_;
    //   if (nextptr->key_==key_){}
      if (key==nextptr->key_){
          
          index=nextptr->index_;
          ptr->next_=nextptr->next_;
          
        //   if(ptr==tail_){
        //       tail_==nullptr;
        //   }
        
      }
  }
//   cout<<index<<endl;
  for(Element<K,V>* ptr = head_; ptr !=nullptr; ptr = ptr->next_){
    //   cout<<ptr->index_<<endl;
      if(ptr->index_>index){
        //   cout<<"test"<<endl<<ptr->key_;
          ptr->index_--;
      }
      
  }
  if (index!=-1){
          return true;
      }
  return false;
}
 
//loops through to find the key same thing as the two below it.
template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_key(K key){
  // no binary search, just linear search
  
    Element<K,V> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_)
        if (ptr->key_==key)
            return ptr;
}    

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_value(V val){
  // linear search
      Element<K,V> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_)
        if (ptr->value_==val)
            return ptr;
  
}  

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_index(size_t i){
  // linear search
  Element<K,V> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_)
        if (ptr->index_==i)
            return ptr;
  
}  
//loops through and prints it.
template<typename K, typename V>
void TriMap<K,V>::print_list(ostream &out){
  // this is a class member function, has access
  // to private data. Called by operator<<
    ostringstream oss;
    Element<K,V> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_)
        if(ptr!=tail_)
    	    oss << *ptr << ", ";
        else
            oss<<*ptr;
    string s = oss.str();
    out << s.substr(0,s.size());
};


#endif
  
