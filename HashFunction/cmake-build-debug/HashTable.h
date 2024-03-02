
#ifndef HASHFUNCTION_HASHTABLE_H
#define HASHFUNCTION_HASHTABLE_H




#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
public:
    HashTable();
    HashTable(int len);
    HashTable(const HashTable& el);
    ~HashTable();

    bool addElement(int key, int value);
    bool deleteElement(int key);
    bool isFull() const;
    void print() const;
    HashTable& operator=(const HashTable& tb);
    int& operator[](int el);
    friend class HashTableTester;

private:
    void clear();
    int hashFunction(int key) const;
    Node* findNode(int key) const;

    std::vector<Node*> m_memory;
    int m_size;
};

#endif //HASHFUNCTION_HASHTABLE_H
