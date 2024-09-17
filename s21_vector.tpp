#include "s21_vector.h"

namespace s21 {

//Vector Member functions
template <typename T>
vector<T>::vector() {
  this->data_ = nullptr;
  this->size_ = 0;
  this->capacity_ = 0;
}

template <typename T>
vector<T>::vector(size_type n) {
  if (n > max_size()) {
    throw std::length_error("Requested size exceeds maximum supported size");
  } else {
    this->data_ = nullptr;
    this->size_ = n;
    this->capacity_ = n;
    this->data_ = new value_type[capacity_];
    for (size_type i = 0; i < n; ++i) {
      this->data_[i] = value_type();
    }
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items) {
    this->data_ = nullptr;
    this->size_ = 0;
    this->capacity_ = 0;
    size_type n = items.size();
    if (n > 0) {
        this->size_ = n;
        this->capacity_ = n;
        this->data_ = new value_type[capacity_];
        size_type i = 0;
        for (const_iterator it = items.begin(); it != items.end(); ++it, ++i) {
            this->data_[i] = *it;
        }
    }
}

template <typename T>
vector<T>::vector(const vector &v) {
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  this->data_ = new value_type[capacity_];
  for (size_type i = 0; i != v.size_; ++i) {
    this->data_[i] = v.data_[i];
  }
}

template <typename T>
vector<T>::vector(vector &&v) {
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  this->data_ = v.data_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
}

template <typename T>
vector<T>::~vector() {
  if (this->data_ != nullptr) {
    delete[] this->data_;
  }
  this->size_ = 0;
  this->capacity_ = 0;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&a) {
  if (this != &a) {
    this->size_ = a.size_;
    this->capacity_ = a.capacity_;
    this->data_ = a.data_;
    a.size_ = 0;
    a.capacity_ = 0;
    a.data_ = nullptr;
  }
  return *this;
}

//Vector Element access
template<typename T>
typename vector<T>::reference vector<T>::at(size_type pos){ 
    if( pos >= this->size_){
        throw std::out_of_range("Index out of range");
    }
    return this->data_[pos];
}

template<typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos){
    return this->data_[pos];
}

template<typename T>
typename vector<T>::const_reference vector<T>::front(){
    if(this->size_ == 0){
         throw std::out_of_range("front: vector empty");
    }
    return this->data_[0];
}

template<typename T>
typename vector<T>::const_reference vector<T>::back(){
    if(this->size_ == 0){
         throw std::out_of_range("back: vector empty");
    }
    return this->data_[this->size_- 1];
}

template<typename T>
T* vector<T>::data(){
    return this->data_;
}

//Vector Iterators
template<typename T>
typename vector<T>::iterator vector<T>::begin(){
    return this->data_;
}

template<typename T>
typename vector<T>::iterator vector<T>::end(){
    return (this->data_+this->size_);
}

//Vector Capacity
template<typename T>
bool vector<T>::empty(){
    return this->size_ == 0;
}

template<typename T>
typename vector<T>::size_type vector<T>::size(){
    return this->size_;
}

template<typename T>
typename vector<T>::size_type vector<T>::capacity(){
    return this->capacity_;
}

template<typename T>
void vector<T>::reserve(size_type size){
if (size > max_size()) {
    throw std::length_error("Requested size exceeds maximum supported size");
  } 
if(this->capacity_<size){
    value_type* temp = new value_type[size];
    for(size_type i = 0; i<this->size_;++i){
        temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
    this -> capacity_ = size;
}
}

template<typename T>
void vector<T>::shrink_to_fit(){
    if(this->capacity_>this->size_){
    value_type* temp = new value_type[this->size_];
    for(size_type i = 0; i<this->size_;++i){
        temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
    this -> capacity_ = this->size_;
}
}


//Допольнительные функции
template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}
}  // namespace s21