#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;

template <typename T>
struct Node{
public:
    Node *next_;
    T data_;
    
Node() : data_( T() ), next_(nullptr) {};
Node(T d) : data_(d), next_(nullptr) {};
};

template <typename T>
class SingleLink{
private:
    Node<T> *head_ = nullptr;
    Node<T> *tail_ = nullptr;
  
public:
    SingleLink()= default;         
    SingleLink(T dat);    
    void append_back(T);
    friend ostream& operator<<(ostream &out, SingleLink<T>& s){
        Node<T> *n;
        for (n = s.head_; n != nullptr; n = n->next_) {
            out << n->data_;
            if (n!=s.tail_)
                out<<", ";
        }
        return out;
    };
    bool SingleLink<T>::del(T val) {
        Node<T> *n;
        //only one value
        if (head_ == tail_) {
            if (val = head_->val) {
                
            }
        }
        //a list full of shit
         for (n = head_; n != tail_; n = n->next_) {
             if ((n->next)->data_ == val)
                break;
         }
         
    }
    //Node<T>& operator[](size_t index);
    
    // Rule of three stuff, if you get time. Look at 21.2
    // ~SingleLink();
    // SingleLink(const SingleLink &);
    // SingleLink& operator=(SingleLink);
  
};

// YOUR STUFF HERE
template<typename T>
SingleLink<T>::SingleLink(T dat) {
    Node<T> *ptr = new Node<T>(dat);
    head_ = ptr;
    tail_ = ptr;
}

//template<typename T>
// void SingleLink<T>::append_back(Node<T> &n){
//     if (tail_ != nullptr){
//     	tail_->next_ = &n;
//     	tail_ = &n;
//     }
//     else {
//     	head_=&n;
//     	tail_=&n;
//     }
// }

template<typename T>
void SingleLink<T>::append_back(T dat){
    Node<T>* n = new Node<T>(dat);
    if (head_ == nullptr && tail_ == nullptr) {
        head_ = n;
        tail_ = n;
    }
    else {
        tail_->next_ = n;
        tail_ = n;
        tail_->next_ = nullptr;
    }
    

}


#endif
  
