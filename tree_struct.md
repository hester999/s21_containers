```
struct s21_TreeNode {
    int value;
    s21_TreeNode* left;
    s21_TreeNode* right;

    s21_TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};
```
структура, которая хранит поля 
- int value - значение
- s21_TreeNode* left - указатель на структуру, которая в последствии будет использоваться как node и хранить числа, которые меньше root 
- s21_TreeNode* right - указатель на структуру, которая в последствии будет использоваться как node и хранить числа, которые больше root
- s21_TreeNode(int val) - конструктор структуры(????) который инициализирует поля 


# Class s21_BinaryTree

```
class s21_BinaryTree {
private:
    s21_TreeNode *node;

    s21_TreeNode *insert(s21_TreeNode *node, int value) {
        if (node == nullptr) {
            node = new s21_TreeNode(value);
        } else if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

public:
    s21_BinaryTree() {
        node = nullptr;
    }

    void insert(int value) {
        node = insert(node, value);
    }

    void InOrder(s21_TreeNode *node) {
        if (node != nullptr) {
            InOrder(node->left);
            std::cout << node->value << " ";
            InOrder(node->right);
        }
    }

    void InOrder() {
        InOrder(node);
        std::cout << std::endl;
    }
};
```

### Private fields 

- s21_TreeNode *node; -  является указателем на структуру и по сути будет хронить адреса наших узлов  
- s21_TreeNode *insert(s21_TreeNode *node, int value); - метод вставки, на первом шаге проверяет наличие корня, если его нет,
  то создаем новый корень.
  Если же у нас уже есть корень, то проверяем, наш элемент больше или нет, если больше то идем по правой стороне, есл нет, то по левой 
- Возвращает адрес нашей ноды 

### Public fields 

``` 
s21_BinaryTree() {
        node = nullptr;
    }
```
- Конструктор без параметров, просто зануляет наш указатль на структруру

``` 
 void insert(int value) {
        node = insert(node, value);
    }
```
- По сути просто метод, который дергает метод из приватной части

``` 
  void InOrder(s21_TreeNode *node) {
        if (node != nullptr) {
            InOrder(node->left);
            std::cout << node->value << " ";
            InOrder(node->right);
        }
    }
```