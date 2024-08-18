#include <iostream>
#include "queue"
#include "s21_containers.h"
#include "s21_queue.h"

int main(){

    s21::queue<int> a;
    a.push(123);
    a.push(12);
    a.push(1);

    for (int i= 0; i<3; i++ ){
        std::cout<< a.front()<<std::endl;
        a.pop();
    }

    return 0;
}