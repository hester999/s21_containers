#include "s21_array.h"
namespace s21{

//Array Member functions
template <typename T, size_t amount> 
array<T,amount>::array(){
    for(size_type i = 0; i < amount ; i++){
        usual_array[i] = 0;
    }
}

template <typename T, size_t amount> 
array<T,amount>::array(std::initializer_list<value_type> const &items){
size_type i = 0;
  for(const_iterator it = items.begin(); it != items.end() && i < amount; ++it, ++i){
    usual_array[i] = *it;
  }
}

template <typename T, size_t amount> 
array<T,amount>::array(const array &a){
    for(size_type i = 0; i < amount; i++)
    usual_array[i] = a.usual_array[i];
}

template<typename T, size_t amount>
array<T,amount>::array(array &&a){
for(size_type i = 0; i<amount; ++i){
usual_array[i] = std::move(a.usual_array[i]);
}
}

template <typename T, size_t amount>
array<T,amount>::~array(){
}

template <typename T, size_t amount>
array<T,amount>& array<T,amount>::operator=(array &&a){
if(this != &a){
    for(size_type i = 0; i < amount ; ++i){
        usual_array[i] = std::move(a.usual_array[i]);
    }
}
    return *this;
}


//Element access
template <typename T, size_t amount> 
typename array<T,amount>::reference array<T, amount>::operator[](size_type pos) { 
    return usual_array[pos];
}

template<typename T, size_t amount>
typename array<T,amount>::reference array<T,amount>::at(size_type pos){ 
    if( pos >= amount){
        throw std::out_of_range("Index out of range");
    }
    return usual_array[pos];
}

template<typename T, size_t amount>
typename array<T,amount>::const_reference array<T,amount>::front(){
    return usual_array[0];
}

template<typename T,size_t amount>
typename array<T,amount>::const_reference array<T,amount>::back(){
    return usual_array[amount-1];
}

template<typename T, size_t amount>
typename array<T,amount>::iterator array<T,amount>::data(){
    return usual_array;
}

//Array Iterators
template<typename T, size_t amount>
typename array<T,amount>::iterator array<T,amount>::begin(){
    return usual_array;
}

template<typename T, size_t amount>
typename array<T,amount>::iterator array<T,amount>::end(){
    return usual_array + amount;
}

//Array Capacity
template<typename T, size_t amount>
bool array<T,amount>::empty(){
  return amount == 0 || usual_array == nullptr;
}

template<typename T, size_t amount>
typename array<T,amount>::size_type array<T,amount>::size(){
    return amount;
}

template<typename T, size_t amount>
typename array<T,amount>::size_type array<T,amount>::max_size(){
    return amount;
}

//Array Modifiers
template<typename T, size_t amount>
void array<T,amount>::swap(array& other){
for(size_type i = 0; i < amount;++i){
std::swap(usual_array[i],other[i]);
}
}

template<typename T, size_t amount>
void array<T,amount>::fill(const_reference value){
    for (size_type i = 0; i <amount; ++i){
        usual_array[i] = value;
    }
}

}
