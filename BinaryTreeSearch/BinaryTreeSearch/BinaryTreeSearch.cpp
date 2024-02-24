#include "BinaryTreeSearch.h"
using std::vector;


BinaryTreeSearch::BinaryTreeSearch(Node* root) {
	m_root = root;
}

BinaryTreeSearch BinaryTreeSearch::copyBinaryTreeSearch(Node* node) {
	return BinaryTreeSearch(node->copyNode());
}

BinaryTree::Node* BinaryTreeSearch::addNode(Node* root, int key){

	if (!root) {
		root = new Node(key);
		return root;
	}
	
	if (root->getKey() > key) {
		root->setLeft(addNode(root->getLeft(), key));
	}
	else  {
		root->setRight(addNode(root->getRight(), key));
	}

	return root;


}


BinaryTree::Node* BinaryTreeSearch::addNode(int key) {
	if (m_root) {
		return addNode(m_root, key);
	}
	else {
		return m_root = new Node(key);
	}
}




BinaryTree::Node* BinaryTreeSearch::getMaxNode() const {
	return getMaxNode(m_root);
}
BinaryTree::Node* BinaryTreeSearch::getMaxNode(BinaryTree::Node* node) const {
	if (node->getRight() == nullptr) {
		return node;
	}
	return getMaxNode(node->getRight());
}

int BinaryTreeSearch::getMaxKey() const {
	return getMaxKey(m_root);
}
int BinaryTreeSearch::getMaxKey(BinaryTree::Node* node) const {
	return getMaxNode()->getKey();
}

BinaryTree::Node* BinaryTreeSearch::getMinNode() const {
	return getMinNode(m_root);
}
BinaryTree::Node* BinaryTreeSearch::getMinNode(Node* node) const {
	if (node->getLeft() == nullptr) {
		std::cout << "I work!" << std::endl;
		return node;
	}
	return getMinNode(node->getLeft());
}


int BinaryTreeSearch::getMinKey() const {
	return getMinKey(m_root);
}
int BinaryTreeSearch::getMinKey(BinaryTree::Node* node) const {
	
	return getMinNode()->getKey();

}

BinaryTree::Node* BinaryTreeSearch::search(const int key) const {
	return search(m_root, key);
}
BinaryTree::Node* BinaryTreeSearch::search(BinaryTree::Node* node, const int key) const {
	if (node == nullptr || node->getKey() == key) {
		return node;
	}
	else if (key<node->getKey()) {
		return search(node->getLeft(), key);
	}
	else{
		return search(node->getRight(), key);
	}
}




BinaryTree::Node* BinaryTreeSearch::removeNode(BinaryTree::Node* node, int key, bool &isDeleted) {
	if (node == nullptr) {
		return nullptr;
	}
	if (key < node->getKey()) {
		node->setLeft(removeNode(node->getLeft(), key, isDeleted));
	}
	else if (key > node->getKey()) {
		node->setRight(removeNode(node->getRight(), key, isDeleted));
	}
	else if (node->getLeft()!=nullptr && node->getRight()!=nullptr) {
		node->setKey(getMinKey(node->getRight()));
		node->setRight(removeNode(node->getRight(), node->getKey(), isDeleted));
	}

	else {
		isDeleted = true;
		if (node->getLeft() != nullptr) {
			node = node->getLeft();
		}
		
		else if (node->getRight() != nullptr) {
			node = node->getRight();
		}
		else {
			node = nullptr;
		}
			
			
	}
	return node;
}

bool BinaryTreeSearch::deleteNode(Node*& node, const int key)  {
	bool isDeleted = false;
	removeNode(m_root, key, isDeleted);
	return isDeleted;
}

bool BinaryTreeSearch::deleteNode(const int key) {
	return deleteNode(m_root, key);
}



BinaryTreeSearch& BinaryTreeSearch::operator=(const BinaryTreeSearch& other) {
	if (this != &other) {

		clearTree();
		
		if (other.m_root != nullptr) {
			m_root = other.m_root->copyNode();
		}
	}
	return *this;
}

int BinaryTreeSearch::getlevelNode(const int key) {
	BinaryTree::Node* levelNode = search(key);
	if (!levelNode) {
		return -1; 
	}
	return getHeight() - getHeight(levelNode);
}

BinaryTree::Node* createOptimalTree(std::vector<int> d, std::vector<int> &p, std::vector<int> &q){
    d.insert(d.begin() , 0);
    p.insert(p.begin() , 0);
    int treeSize = d.size();


    vector<vector<int>> weight(treeSize, vector<int>(treeSize, 0)); // матрица весов - W
    vector<vector<int>> price(treeSize, vector<int>(treeSize, 0)); // матрица стоимости - С
    vector<vector<int>> keyNumbers(treeSize, vector<int>(treeSize, 0)); // матрица номеров ключей в корнях поддеревьев - R

    for (int i = 0 ; i<treeSize ; i++)  // заполнение диагоналей матриц W и С
    {
        weight[i][i] = q[i];
        price[i][i] = q[i];
    }

    // заполнили вторую диагональ у всех матриц
    for(int i = 0; i<treeSize-1; i++)
    {
        int j = i+1;
        weight[i][j] = weight[i][j-1] + p[j] + q[j];
        price[i][j] = weight[i][j] + price[i][i] + price[j][j];
        keyNumbers[i][j] = j;
    }

    if ( (treeSize - 1) >=2 ) // генерируем матрицу R, для построения дерева
    {
        for(int k = 2 ; k < treeSize; k++)
        {
            for(int i = 0 ; i < treeSize - 2 ; i++)
            {
                int j = i + k;
                if(j > treeSize - 1)
                {
                    break;
                }
                weight[i][j] = weight[i][j-1] + p[j] + q[j];
                int index = i + 1;
                int minCost = price[i][index-1]+price[index][j];
                int temp = index;
                for (index = i+1; index<=j ; index++)
                {
                    if ( (price[i][index-1] + price[index][j]) < minCost)
                    {
                        minCost = price[i][index-1] + price[index][j];
                        temp = index;
                    }
                }

                price[i][j] = weight[i][j] + minCost;
                keyNumbers[i][j] = temp;
            }
        }
    }




}
