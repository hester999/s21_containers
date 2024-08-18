#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include "s21_containers.h"

namespace s21 {

    template <typename T>
    struct QueueNode : public Node<T> {
        using Node<T>::next;
        QueueNode(T value);
    };

    template <typename T>
    class Queue {
    public:
        Queue();
        ~Queue();
        void push(T value);
        // Другие методы могут быть здесь объявлены
    private:
        Node<T>* tail;
        Node<T>* head;
    };

}  // namespace s21

#include "s21_queue.tpp"  // Включение файла с реализацией шаблонных методов

#endif  // S21_QUEUE_H
