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
    class queue {
    public:
        queue();
        ~queue();
        void push(T value);
        void pop();
        T front();
        // Другие методы могут быть здесь объявлены
    private:
        Node<T>* tail;
        Node<T>* head;
    };

}  // namespace s21

#include "s21_queue.tpp"  // Включение файла с реализацией шаблонных методов

#endif  // S21_QUEUE_H
