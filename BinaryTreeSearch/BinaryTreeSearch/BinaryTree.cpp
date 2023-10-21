#include "BinaryTree.h"

#include <queue>
#include <stdio.h>
#include <math.h>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;

BinaryTree::BinaryTree() {
    m_root = nullptr;
}

BinaryTree::BinaryTree(const BinaryTree& other) {
    if (other.m_root == nullptr) {
        m_root = nullptr;
        return;
    }
    m_root = other.m_root->copyNode();
}

BinaryTree::BinaryTree(int key) {
    m_root = new Node(key);
}

BinaryTree::BinaryTree(Node* root) {
    m_root = root;
}

BinaryTree::~BinaryTree() {
    clearTree();
}

BinaryTree::Node* BinaryTree::getRoot() {
    return m_root;
}

BinaryTree::Node* BinaryTree::addNode(Node* root, int key) {
    if (!root) {
        root = new Node(key);
    }
    else if (rand() % 2) {
        root->setLeft(addNode(root->getLeft(), key));
    }
    else {
        root->setRight(addNode(root->getRight(), key));
    }

    return root;
}


BinaryTree::Node* BinaryTree::addNode(int key) {
    if (m_root) {
        return addNode(m_root, key);
    }
    else {
        return m_root = new Node(key);
    }
}


void BinaryTree::deleteChildren(Node* node) {
    if (node->getLeft() != nullptr) {
        deleteChildren(node->getLeft());
    }
    if (node->getRight() != nullptr) {
        deleteChildren(node->getRight());
    }

    delete node;
}

void BinaryTree::clearTree() {
    if (m_root != nullptr)
    {

        delete m_root;
        m_root = nullptr;
    }
}

bool BinaryTree::isEmpty() const {
    return (m_root == nullptr);
}

BinaryTree BinaryTree::copyBinaryTree(Node* node) {
    return BinaryTree(node->copyNode());
}

int BinaryTree::getHeight() const {
    return getHeight(m_root);
}

int BinaryTree::getHeight(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return max(getHeight(node->getLeft()), getHeight(node->getRight())) + 1;
}

int BinaryTree::size() const {
    return getCount(m_root);
}

int BinaryTree::getCount(const Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return getCount(node->getLeft()) + getCount(node->getRight()) + 1;
}

int BinaryTree::getMaxKey() const {
    return getMaxKey(m_root);
}

int BinaryTree::getMaxKey(Node* node) const {
    if (node == nullptr) {
        return INT_MAX;
    }
    return max(node->getKey(), max(getMaxKey(node->getLeft()), getMaxKey(node->getRight())));
}

int BinaryTree::getMinKey() const {
    return getMinKey(m_root);
}

int BinaryTree::getMinKey(Node* node) const {
    if (node == nullptr) {
        return INT_MIN;
    }
    return min(node->getKey(), max(getMinKey(node->getLeft()), getMinKey(node->getRight())));
}

bool BinaryTree::removeNode(const int key) {
    return removeNode(m_root, key, nullptr);
}




bool BinaryTree::removeNode(Node* node, const int key, Node* parent) {
    if (node == nullptr) {
        return false;
    }
    if (node->getKey() == key) {
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            if (parent == nullptr) {
                m_root = nullptr;
            }
            else if (parent->getLeft() == node) {
                parent->setLeft(nullptr);
            }
            else {
                parent->setRight(nullptr);
            }
            delete node;
            return true;
        }
        if (node->getLeft() == nullptr) {
            if (parent == nullptr) {
                m_root = node->getRight();
            }
            else if (parent->getLeft() == node) {
                parent->setLeft(node->getRight());
            }
            else {
                parent->setRight(node->getRight());
            }
            delete node;
            return true;
        }
        if (node->getRight() == nullptr) {
            if (parent == nullptr) {
                m_root = node->getLeft();
            }
            else if (parent->getLeft() == node) {
                parent->setLeft(node->getLeft());
            }
            else {
                parent->setRight(node->getLeft());
            }
            delete node;
            return true;
        }
        Node* temp = node->getLeft();
        Node* tempParent = node;
        while (temp->getRight() != nullptr) {
            tempParent = temp;
            temp = temp->getRight();
        }
        node->setKey(temp->getKey());
        return removeNode(temp, temp->getKey(), tempParent);
    }
    return removeNode(node->getLeft(), key, node) || removeNode(node->getRight(), key, node);
}

BinaryTree::Node* BinaryTree::search(const int key) const {
    return search(m_root, key);
}

BinaryTree::Node* BinaryTree::search(BinaryTree::Node* node, const int key) const {
    if (node == nullptr || node->getKey() == key) {
        return node;
    }
    else if (key < node->getKey()) {
        return search(node->getLeft(), key);
    }
    else {
        return search(node->getRight(), key);
    }
}

vector<int> BinaryTree::getVector() const {
    vector<int> result;
    getVector(m_root, result);
    return result;
}

void BinaryTree::getVector(BinaryTree::Node* node, vector<int>& result) const {
    if (node != nullptr) {
        result.push_back(node->getKey());
        getVector(node->getLeft(), result);
        getVector(node->getRight(), result);
    }
}

int BinaryTree::getLevel(const int key) const {
    return BinaryTree::getLevel(m_root, key);
}

int BinaryTree::getLevel(Node* node, const int key) const {
    if (node == nullptr) {
        return -1;
    }
    if (node->getKey() == key) {
        return 0;
    }
    int leftLevel = BinaryTree::getLevel(node->getLeft(), key);
    if (leftLevel != -1) {
        return leftLevel + 1;
    }
    int rightLevel = BinaryTree::getLevel(node->getRight(), key);
    if (rightLevel != -1) {
        return rightLevel + 1;
    }
    return -1;
}

bool BinaryTree::isBalanced(Node* node) const {
    if (node == nullptr) {
        return true;
    }
    int leftHeight = getHeight(node->getLeft());
    int rightHeight = getHeight(node->getRight());
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(node->getLeft()) && isBalanced(node->getRight())) {
        return true;
    }
    return false;
}

int BinaryTree::getSum() const {
    return getSum(m_root);
}

int BinaryTree::getSum(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    else {
        return node->getKey() + getSum(node->getLeft()) + getSum(node->getRight());
    }
}

void BinaryTree::printHorizontal(Node* root, const int marginLeft, const int levelSpacing) const
{
    if (root == nullptr) {
        return;
    }
    printHorizontal(root->getRight(), marginLeft + levelSpacing, levelSpacing);
    std::cout << std::string(marginLeft, ' ') << root->getKey() << std::endl;
    printHorizontal(root->getLeft(), marginLeft + levelSpacing, levelSpacing);
}

void BinaryTree::print() const {
    printHorizontal(this->m_root, 3, 6);
}

void BinaryTree::printLevel(int level) const {
    if (isEmpty()) {
        return;
    }

    int targetLevel = level;
    int currentLevel = 0;
    int nodesInTargetLevel = pow(2, targetLevel);
    int levelSpacing = pow(2, targetLevel + 1) - 1;
    int marginLeft = levelSpacing / 2;

    std::queue<Node*> nodesQueue;
    nodesQueue.push(m_root);

    while (!nodesQueue.empty()) {
        int nodesInCurrentLevel = nodesQueue.size();
        if (currentLevel == targetLevel) {
            for (int i = 0; i < nodesInCurrentLevel; i++) {
                Node* currentNode = nodesQueue.front();
                nodesQueue.pop();
                if (currentNode != nullptr) {
                    std::cout << std::string(marginLeft, ' ') << currentNode->getKey() << std::string(marginLeft, ' ');
                }
                else {
                    std::cout << std::string(levelSpacing, ' ');
                }
            }
            std::cout << std::endl;
            return;
        }
        for (int i = 0; i < nodesInCurrentLevel; i++) {
            Node* currentNode = nodesQueue.front();
            nodesQueue.pop();
            if (currentNode != nullptr) {
                nodesQueue.push(currentNode->getLeft());
                nodesQueue.push(currentNode->getRight());
            }
            else {
                nodesQueue.push(nullptr);
                nodesQueue.push(nullptr);
            }
        }
        currentLevel++;
        nodesInTargetLevel /= 2;
        levelSpacing = pow(2, currentLevel + 1) - 1;
        marginLeft = levelSpacing / 2;
    }
}


void BinaryTree::printByLevels(Node* root) const {
    if (root == nullptr) {
        return;
    }

    int level = 1;
    std::queue<BinaryTree::Node*> nodesQueue;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) {
        int levelSize = nodesQueue.size();
        std::cout << "Level " << level << ": ";

        for (int i = 0; i < levelSize; i++) {
            Node* currentNode = nodesQueue.front();
            nodesQueue.pop();

            if (currentNode != nullptr) {
                cout << currentNode->getKey() << " ";
                nodesQueue.push(currentNode->getLeft());
                nodesQueue.push(currentNode->getRight());
            }
            else {
                std::cout << "null ";
                nodesQueue.push(nullptr);
                nodesQueue.push(nullptr);
            }
        }

        cout << std::endl;
        level++;
    }
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    if (this != &other) {

        clearTree();
        // Копируем корень и остальные узлы
        if (other.m_root != nullptr) {
            m_root = other.m_root->copyNode();
        }
    }
    return *this;
}







