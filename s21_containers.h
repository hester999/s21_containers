
#ifndef S21_CONTAINERS_S21_CONTAINERS_H


namespace  s21{
    template <typename T>

    struct Node{
        T value;
        Node<T> * next;
        Node<T> * prev;
    };
}



#define S21_CONTAINERS_S21_CONTAINERS_H

#endif //S21_CONTAINERS_S21_CONTAINERS_H
