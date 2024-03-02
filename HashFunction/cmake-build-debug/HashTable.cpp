#include "HashTable.h"

HashTable::HashTable() : m_size(3) {
    m_memory.resize(m_size, nullptr);
}

HashTable::HashTable(int len) : m_size(len) {
    if (m_size <= 2) {
        throw "HashTable can't use len less than 3";
    }
    m_memory.resize(m_size, nullptr);
}

HashTable::HashTable(const HashTable& other) {
    m_size = other.m_size;
    m_memory.resize(m_size, nullptr);
    for (int i = 0; i < m_size; ++i) {
        Node* curr = other.m_memory[i];
        while (curr) {
            addElement(curr->key, curr->value);
            curr = curr->next;
        }
    }
}

HashTable::~HashTable() {
    clear();
}

bool HashTable::addElement(int key, int value) {
    int index = hashFunction(key);
    if (!m_memory[index]) {
        m_memory[index] = new Node(key, value);
    } else {
        Node* curr = m_memory[index];
        while (curr->next) {
            if (curr->key == key) {
                return false; // Already exists
            }
            curr = curr->next;
        }
        if (curr->key == key) {
            return false; // Already exists
        }
        curr->next = new Node(key, value);
    }
    return true;
}

bool HashTable::deleteElement(int key) {
    int index = hashFunction(key);
    Node* curr = m_memory[index];
    Node* prev = nullptr;
    while (curr) {
        if (curr->key == key) {
            if (!prev) {
                m_memory[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false; // Not found
}

bool HashTable::isFull() const {
    for (int i = 0; i < m_size; ++i) {
        if (!m_memory[i]) {
            return false;
        }
    }
    return true;
}

void HashTable::print() const {
    for (int i = 0; i < m_size; ++i) {
        Node* curr = m_memory[i];
        while (curr) {
            std::cout << "Index " << i << ": (" << curr->key << ", " << curr->value << ")" << std::endl;
            curr = curr->next;
        }
    }
}

HashTable& HashTable::operator=(const HashTable& tb) {
    if (this != &tb) {
        clear();
        m_size = tb.m_size;
        m_memory.resize(m_size, nullptr);
        for (int i = 0; i < m_size; ++i) {
            Node* curr = tb.m_memory[i];
            while (curr) {
                addElement(curr->key, curr->value);
                curr = curr->next;
            }
        }
    }
    return *this;
}

int& HashTable::operator[](int el) {
    Node* node = findNode(el);
    if (!node) {
        throw "Key not found";
    }
    return node->value;
}

void HashTable::clear() {
    for (int i = 0; i < m_size; ++i) {
        Node* curr = m_memory[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        m_memory[i] = nullptr;
    }
}

int HashTable::hashFunction(int key) const {
    return key % m_size;
}

Node* HashTable::findNode(int key) const {
    int index = hashFunction(key);
    Node* curr = m_memory[index];
    while (curr) {
        if (curr->key == key) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}
