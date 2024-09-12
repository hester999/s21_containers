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
    return usual_array[pos];}

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
}
