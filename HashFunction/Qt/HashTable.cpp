#include "HashTable.h"
#include <iostream>
#include <iomanip>

HashTable::HashTable()
{
    m_nodeCount = 0;
    setCapacity(10);
    setHashFunction(new SecondHash());
}


HashTable::HashTable(int size)
{
    m_nodeCount = 0;
    setCapacity(size);
    setHashFunction(new SecondHash());
}

HashTable::HashTable(const HashTable& copy)
{
    m_nodeCount = 0;
    setCapacity(copy.m_capacity);
    setHashFunction(copy.m_hashFunction->clone());
    copyTable(copy);
}

HashTable::~HashTable()
{
    clear();
    delete m_hashFunction;
}

void HashTable::clear()
{
    for (Node* node : m_nodes)
    {
        while (node)
        {
            Node* previousNode = node;
       
            node = node->getNextNode();
            delete previousNode;
            
        }
    }
    for (int i = 0; i < m_capacity; i++)
    {
        m_nodes[i] = nullptr;
    }
    m_nodeCount = 0;
}

int HashTable::add(int key, int value)
{
    unsigned int hash = m_hashFunction->hash(key, m_capacity);
    Node* addNode = new Node(key, value);

    if (m_nodes[hash] == nullptr)
    {
        m_nodes[hash] = addNode;
    }
    else
    {
        Node* temp = m_nodes[hash];
        while (temp->getNextNode())
        {
            temp = temp->getNextNode();
        }
        temp->setNextNode(addNode);
    }
    m_nodeCount++;
    return hash;
}

bool HashTable::remove(int key)
{
    unsigned int hash = m_hashFunction->hash(key, m_capacity);
    Node* temp = m_nodes[hash];
    Node* parent = nullptr;

    while (temp != nullptr)
    {
        if (temp->getKey() == key)
        {
            if (parent)
            {
                parent->setNextNode(temp->getNextNode());
                delete temp;
            }
            else
            {
                Node* nextNode = temp->getNextNode();
                delete temp;
                m_nodes[hash] = nextNode;
            }
            m_nodeCount--;
            return true;
        }
        parent = temp;
        temp = temp->getNextNode();
    }
    return false;
}

bool HashTable::contains(int key)
{
    unsigned int hash = m_hashFunction->hash(key, m_capacity);
    Node* temp = m_nodes[hash];

    while (temp)
    {
        if (temp->getKey() == key)
        {
            return true;
        }

        temp = temp->getNextNode();
    }

    return false;
}

void HashTable::printTable() const
{
    std::cout << "Hash" << std::setw(18) << "(Key, Value)" << std::setw(26) << "(_table[i], _next)" << std::endl;
    for (int i = 0; i < m_capacity; i++) {
        std::cout << "Hash " << i << ":" << std::setw(4);
        Node* current = m_nodes[i];
        if (current != nullptr) {
            std::cout << std::setw(4) << "(" << current->getKey() << ", " << current->getValue() << ")";
            std::cout << std::setw(9) << "(" << current << ", " << current->getNextNode() << ") ";
            while (current->getNextNode())
            {
                current = current->getNextNode();
                std::cout << std::setw(4) << "(" << current->getKey() << ", " << current->getValue() << ")";
                std::cout << std::setw(9) << "(" << current << ", " << current->getNextNode() << ") ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void HashTable::copyTable(const HashTable& copy)
{
    clear();
    m_nodeCount = copy.m_nodeCount;
    setCapacity(copy.m_capacity);
    setHashFunction(copy.m_hashFunction->clone());

    for (Node* node : copy.nodes())
    {
        add(node->getKey(), node->getValue());
    }
}

HashTable& HashTable::operator=(const HashTable& copy)
{
    if (this != &copy)
    {
        delete m_hashFunction;
        copyTable(copy);
    }
    return *this;
}

int& HashTable::operator[](int key)
{
    if (contains(key))
    {
        throw "No key in table";
    }

    unsigned int hash = m_hashFunction->hash(key, m_capacity);
    Node* temp = m_nodes[hash];

    while (temp)
    {
        if (temp->getKey() == key)
        {
            return temp->GetAdressValue();
        }

        temp = temp->getNextNode();
    }

}

void HashTable::changeHashFunction(HashFunction* newHashFunction) {
    getisFirstHash() == true ? setfirstHash(false) : setfirstHash(true);


    // Создаем временный вектор узлов для хранения всех элементов
    std::vector<Node*> allNodes;
    for (Node* node : m_nodes) {
        Node* currentNode = node;
        while (currentNode) {
            allNodes.push_back(new Node(currentNode->getKey(), currentNode->getValue()));
            currentNode = currentNode->getNextNode();
        }
    }

    // Очищаем текущий список узлов
    clear();

    // Устанавливаем новую хеш-функцию
    setHashFunction(newHashFunction);

    // Переход по всем элементам, добавление их с использованием новой хеш-функции
    for (Node* node : allNodes) {
        add(node->getKey(), node->getValue());
    }

    printTable();
}
