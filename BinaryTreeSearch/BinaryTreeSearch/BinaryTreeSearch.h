#pragma once
//
//Необходимые методы класса :
//+конструкторы(по умолчанию, копирования);
//+деструктор;
//+копирование поддерева узла(возвращает новый объект класса);
//+получение минимального / максимального ключа дерева(имеет другой алгоритм);
//+добавление узла в дерево(имеет другой алгоритм);
//+удаление узла из дерева по ключу(возвращает true, если узел был удалён) (имеет другой алгоритм);
//+поиск узла дерева по ключу;
//-получение уровня вершины по ключу(возвращает индекс уровня или - 1, если вершина не найдена) (имеет другой алгоритм);
//+оператор присваивания.

#include "BinaryTree.h"



class BinaryTreeSearch: 
	public BinaryTree
{
public:
	using BinaryTree::Node;
	BinaryTreeSearch() : BinaryTree() {};
	BinaryTreeSearch(const BinaryTreeSearch& other) :BinaryTree(other) {};
	BinaryTreeSearch(Node* root);

	~BinaryTreeSearch() override = default;

	BinaryTreeSearch copyBinaryTreeSearch(Node* node);
	
	Node* addNode(int key) override;
	Node* addNode(Node* root, int key) override;

	int getMaxKey() const override;
	virtual int getMaxKey(Node* node) const override;

	int getMinKey() const override;
	virtual int getMinKey(Node* node) const override;

	Node* getMinNode() const;
	Node* getMinNode(Node* node) const;

	Node* getMaxNode() const;
	Node* getMaxNode(Node* node) const;


	Node* search(const int key) const override;
	Node* search(Node* node, const int key) const override;

	bool deleteNode(Node*& node, const int key);
	bool deleteNode(const int key);

	Node* removeNode(Node* node, int key, bool& isDeleted);

	int getlevelNode(const int key);

	BinaryTreeSearch& operator=(const BinaryTreeSearch& other);
	
};


