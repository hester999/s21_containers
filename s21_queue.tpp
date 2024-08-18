#include "s21_queue.h"
#include "iostream"
namespace s21 {

    template <typename T>
    Node<T>::Node(T value) : value(value), next(nullptr), prev(nullptr) {}

    template <typename T>
    QueueNode<T>::QueueNode(T value) :Node<T>(value) {}

    // Реализация конструктора Queue
    template <typename T>
    queue<T>::queue() : head(nullptr), tail(nullptr) {}

    // Реализация деструктора Queue
    template <typename T>
    queue<T>::~queue() {
        // Здесь может быть код для очистки ресурсов (например, удаление всех элементов)
    }

    // Реализация метода push
    template <typename T>
    void queue<T>::push(T value) {
        QueueNode<T>* node = new QueueNode<T>(value);

        if(tail){
            tail ->next = node;
        }else{
            head = node;
        }
        tail = node;
    }

    template <typename T>
    void queue<T>::pop(){
        if (!head){
            throw std::runtime_error("Empty queue");
        }
        Node<T> *tmp  =  head;
        head = head->next ;
        delete tmp;
    }

    template <typename T>
    T queue<T>::front() {
        return head->value;
    }

}  // namespace s21
