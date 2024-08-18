#include "s21_queue.h"

namespace s21 {

    // Реализация конструктора QueueNode
    template <typename T>
    QueueNode<T>::QueueNode(T value) : Node<T>(value) {}

    // Реализация конструктора Queue
    template <typename T>
    Queue<T>::Queue() : head(nullptr), tail(nullptr) {}

    // Реализация деструктора Queue
    template <typename T>
    Queue<T>::~Queue() {
        // Здесь может быть код для очистки ресурсов (например, удаление всех элементов)
    }

    // Реализация метода push
    template <typename T>
    void Queue<T>::push(T value) {
        QueueNode<T>* node = new QueueNode<T>(value);

    }

    // Реализация других методов...

}  // namespace s21
