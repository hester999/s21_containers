#ifndef S21_LIST_H
#define S21_LIST_H

namespace s21 {
template <typename T>
class list {
 public:
  using value_type = T;  // переопределение типа
  using reference = T&;  // переопределение типа ссылки
  using const_reference = const T&;  // переопределение типа const ссылки
  using iterator = ListIterator<T>;  // переопределение класса для итератора
  using const_iterator =
      ListConstIterator<T>;  // переопределение класса для const итератора
  using size_type = std::size_t;  // переопределение типа для размера контейнера

 private:
  // узел двусвязного списка
  struct ListNode {
    value_type data_;  // значение узла
    ListNode* next_;   // указатель на следующий узел
    ListNode* prev_;   // указатель на предыдущий узел

    // конструктор для создания узла со значением value
    ListNode(const_reference value)
        : data_(value), next_(nullptr), prev(nullptr) {}
  };

 public:
  // методы для взаимодействия с классом
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  ~list();
  operator=(list && l);

  // методы для доступа к элементам класса
  const_reference front();
  const_reference back();

  // методы для итерирования по элементам класса (доступ к итераторам)
  iterator begin();
  iterator end();

  // методы для доступа к информации о наполнении контейнера
  bool empty();
  size_type size();
  size_type max_size();

  // методы для изменения контейнера
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();

 private:
  ListNode* head;  // голова списка
  ListNode* tail;  // хвост списка

  // итератор списка
  struct ListIterator {
    /* data */
  };

  // константный итератор списка
  struct ListConstIterator {
    /* data */
  };
};

}  // namespace s21

#include "s21_list.tpp"  // Включение файла с реализацией шаблонных методов

#endif  // S21_LIST_H