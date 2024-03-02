#pragma once

#include <string>
#include <set>

class HuffmanTree
{
public:
	class Node;

	HuffmanTree();

	~HuffmanTree();
	void removal();

    double encode(const std::string& text, std::string& encodedText);

    void encodeFile(const std::string& inputFile, const std::string& outputFile);

private:
	Node* m_root;


private:
    void build(const std::string& text);

    bool decode(const std::string& encodedText, std::string& decodedText) const;
    void removalAuxiliary(Node* node);
};

class HuffmanTree::Node
{
public:
	Node();
	Node(Node* left, Node* right);

	Node*& getLeft();
	Node*& getRight();
	int& getFrequency();
	void setFrequency(int& number);
	std::set<char> getSymbols();

	void setSymbols(const char symbol);

private:
	Node* m_left;
	Node* m_right;
	int m_frequency;
	std::set<char> m_symbols;
};