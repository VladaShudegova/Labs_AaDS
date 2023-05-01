#ifndef LAB2_BINARYTREE_H
#define LAB2_BINARYTREE_H

/*
 * Необходимые методы класса BinaryTree:
+ конструкторы (по умолчанию, копирования);
+ деструктор;
+ получение корня дерева;
+ очистка дерева (удаление всех узлов);
+ удаление поддеревьев узла;
+ isEmpty (возвращает true, если дерево пусто);
+ копирование поддерева узла (возвращает новый объект класса);
+ получение высоты дерева;
+ получение количества узлов дерева;
+ получение минимального/максимального ключа дерева;
+ добавление узла в дерево (методом случайного выбора поддерева);
+ удаление узла из дерева по ключу (возвращает true, если узел был удалён);
+ проверка дерева на сбалансированность (возвращает true, если дерево является сбалансированным: высоты правого и левого поддеревьев отличаются не более, чем на единицу, и сами поддеревья также являются сбалансированными);
+ получение суммы всех ключей дерева;
+ получение уровня вершины по ключу (возвращает индекс уровня или -1, если вершина не найдена);
+ получение вектора (std::vector<int>), содержащего все ключи дерева (обход вершин производить любым способом; на оценку "отлично" - обход реализовать с помощью итератора);
+ вывод в консоль дерева в горизонтальном виде (самый правый потомок находится на первой строке, самый левый - на нижней);
-+ вывод в консоль уровня дерева ("пустые" узлы так же вывести, т.о., общее число узлов уровня всегда постоянно: 2^(индекс уровня));
-+ вывод в консоль дерева по уровням (через последовательные вызовы предыдущего метода);
+ вывод в консоль листьев дерева;
+ оператор присваивания.
Данные методы должны работать как для всего дерева, так и для любого из его поддеревьев (например, если в метод получения размера дерева передать не корень, а один из дочерних узлов, будет получено количество узлов для поддерева с корнем в этом узле).
 */

#include <iostream>
#include <vector>


class BinaryTree {

public:
    class Node;

    BinaryTree();
    BinaryTree(const BinaryTree& other);

    BinaryTree(int key);
    BinaryTree(Node* root);
    ~BinaryTree();

    Node* getRoot();

    Node *addNode(Node *root, int key);

    Node * addNode(int key);


    void deleteChildren(Node* node);

    void clearTree();

    bool isEmpty() const;

    BinaryTree copyBinaryTree(Node* node);

    int getHeight() const;

    int getHeight(Node* node) const;

    int size() const;

    int getCount(const Node* node) const;

    int getMaxKey();

    int getMaxKey(Node* node);

    int getMinKey();

    int getMinKey(Node* node);

    bool removeNode(int key);

    bool remove(Node* node, int key, Node* parent);

    Node* search(int key) const;

    Node* search(Node* node, int key) const;

    std::vector<int> getVector() const;

    void getVector(Node* node, std::vector<int>& result) const;

    int getLevel(int key);

    int getLevel(Node* node, int key);

    bool isBalanced(Node* node);

    int getSum() const;

    int getSum(Node* node) const;


    void printHorizontal(Node *root, int marginLeft, int levelSpacing) const;

    void printLevel(int level) const;

    void printByLevels(Node* root) const;

    BinaryTree& operator=(const BinaryTree& other);



private:
    Node* m_root;

};



class BinaryTree::Node
{
public:
    explicit Node(int key = 0) {
        m_key = key;
        m_left = nullptr;
        m_right = nullptr;
    }
    Node(int key, Node* left, Node* right) {
        m_key = key;
        m_left = left;
        m_right = right;
    }
    Node* getLeft() const {
        return m_left;
    }
    void setLeft(Node* left) {
        m_left = left;
    }
    Node* getRight() const {
        return m_right;
    }
    void setRight(Node* right) {
        m_right = right;
    }
    int getKey() const {
        return m_key;
    }
    void setKey(int key) {
        m_key = key;
    }
    int getNumChildren() const {
        return (m_left != nullptr) + (m_right != nullptr);
    }
    Node* copyNode() {
        return copyNode(this);
    }
    Node* copyNode(Node* node) {
        Node* newNode = new Node(node->m_key);
        if (node->m_left != nullptr) {
            newNode->m_left = copyNode(node->m_left);
        }
        if (node->m_right != nullptr) {
            newNode->m_right = copyNode(node->m_right);
        }
        return newNode;
    }
private:
    Node* m_left;
    Node* m_right;
    int m_key;
};


#endif //LAB2_BINARYTREE_H
