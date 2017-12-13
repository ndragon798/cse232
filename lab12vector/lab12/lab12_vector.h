#ifndef LAB12_VECTOR
#define LAB12_VECTOR
#include<iostream>
#include<initializer_list>
#include<stdexcept>
using std::initializer_list; using std::copy; using std::swap; using std::range_error;
namespace student {
     template<typename T>
     class vector;
     template<typename T>
     class vector{
        private: 
            T *data_=nullptr;
            size_t capacity_=10;
            size_t size_=0;
        public:
            // vector = default();
            vector() = default;
            vector(size_t);
            vector(initializer_list<T>);
            size_t capacity();
            size_t size();
            void push_back(T item);
            T& operator[](size_t val);
            vector(vector& v);
            vector& operator=(vector& v);
            ~vector();
            T& front();
            T& back();
            
     };
    template <typename T>
    vector<T>::vector(initializer_list<T> list){
    size_t indx = 0;
    capacity_ = list.size();
    size_ =list.size();
    data_ = new T[size_];
    for (auto x : list){
        data_[indx++] = x;
    }
};
    template <typename T>
    vector<T>::vector(size_t capacity){
        capacity_ = capacity;
        size_ = 0;
        data_ = new T[capacity_];
    };
    template <typename T>
    size_t vector<T>::size(){
        return size_;
    };
    template <typename T>
    size_t vector<T>::capacity(){
        return capacity_;
    };
    template <typename T>
    T& vector<T>::operator[](size_t val){
        if (val>=size_)
            throw range_error("out of range");
        else
            return data_[val];
    };
    template<typename T>
    vector<T>::~vector(){
        delete [] data_;
    };
    template<typename T>
    T& vector<T>::front(){
        if (size_>0)
            return data_[0];
        else
            throw range_error("out of range");
    };
    template<typename T>
    T& vector<T>::back(){
        if (size_>0)
            return data_[size_-1];
        else
            throw range_error("out of range");
    };
    template<typename T>
    void vector<T>::push_back(T item){
        if (size_==capacity_){
            T *tmp;
            tmp= new T[capacity_*2]{};
            copy(data_,data_+size_,tmp);
            swap(tmp,data_);
            delete [] tmp;
            data_[size_]=item;
        }else{
            data_[size_]=item;
            size_++;
        }
        
    };
    template<typename T>
    vector<T>& vector<T>::operator=(vector& v){

        swap(this->size_, v.size_);
        swap(this->capacity_, v.capacity_);
        swap(this->data_, v.data_);
        return *this;
    };
    
    
}
#endif