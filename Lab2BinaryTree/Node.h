#ifndef LABS_TREE_NODE_H
#define LABS_TREE_NODE_H

/*
 * Необходимые методы класса Node:
 + конструкторы (по умолчанию и с параметрами);
 + получение ключа узла (целое число);
 + получение количества прямых потомков узла;
 */


class Node
{
private:
    int m_key = 0;
    int m_childrenCount = 0;
    Node *m_leftChild = nullptr;
    Node *m_rightChild = nullptr;

public:
    Node() = default;
    Node(int key = 0, Node *leftChild = nullptr, Node *rightChild = nullptr);
    ~Node() = default; //Удалением потомков занимается НЕ узел
    int key() const;
    int childrenCount() const;
    void setKey(const int key);
    void setLeftChild(Node* leftChild);
    void setRightChild(Node* rightChild);
    Node* leftChild();
    Node* rightChild();




};


#endif //LABS_TREE_NODE_H
