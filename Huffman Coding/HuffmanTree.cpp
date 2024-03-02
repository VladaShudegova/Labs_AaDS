#include <iostream>
#include <string>
#include <list>
#include <set>
#include <fstream>

#include "HuffmanTree.h"

using std::cout;

HuffmanTree::HuffmanTree()
{
	m_root = nullptr;
}

HuffmanTree::~HuffmanTree()
{
	removal();
}

void HuffmanTree::removal()
{
	removalAuxiliary(m_root);

	m_root = nullptr;
}

void HuffmanTree::removalAuxiliary(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	removalAuxiliary(node->getLeft());
	removalAuxiliary(node->getRight());

	delete node;
}

void HuffmanTree::build(const std::string& text)
{
	removal();  //удаляем старые узлы

	int frequencies[256] = {};

	for (int i = 0; i < text.length(); i++)
	{
		frequencies[text[i]]++;
	}

	std::list<Node*> nodes; //список элементов, содержащих символы исх текста и их частоты

	for (int i = 0; i < 256; i++)
	{
		if (frequencies[i] == 0)    //символы, которые не встретились в тексте
		{
			continue;
		}

		Node* newNode = new Node;

		newNode->setFrequency(frequencies[i]);
		newNode->setSymbols(i);

		nodes.push_back(newNode);
	}

	while (nodes.size() > 1)
	{
        //отсортировываем список после добавления объединенного узла
		nodes.sort([](Node* left, Node* right)
			{
				return (left->getFrequency()) < (right->getFrequency());
			});

		Node* first;
		Node* second;

		first = *(nodes.begin());
		nodes.pop_front();

		second = *(nodes.begin());
		nodes.pop_front();

		Node* root = new Node(first, second);

		nodes.push_back(root);
	}

	m_root = *(nodes.begin());  //корень всего дерева
}
void HuffmanTree::encodeFile(const std::string& inputFile, const std::string& outputFile) {
    // Создаем объект класса HuffmanTree
    HuffmanTree huffmanTree;

    // Открываем исходный файл для чтения
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open input file!" << std::endl;
        return; // Завершаем метод в случае ошибки
    }

    // Считываем содержимое файла в строку
    std::string text((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

    // Строим дерево Хаффмана из текста файла с помощью объекта HuffmanTree
    huffmanTree.build(text);

    // Кодируем текст
    std::string encodedText;
    double compressionRatio = huffmanTree.encode(text, encodedText);

    // Закрываем файл
    inFile.close();

    // Сохраняем закодированный текст в выходной файл
    if (compressionRatio != -1) {
        // Открываем файл для записи закодированного текста
        std::ofstream outFile(outputFile);
        if (outFile.is_open()) {
            outFile << encodedText;
            outFile.close();
            std::cout << "Encoded text saved to: " << outputFile << std::endl;
        } else {
            std::cerr << "Error: Unable to open output file for writing!" << std::endl;
        }
    } else {
        std::cerr << "Error: Encoding failed!" << std::endl;
    }
}



double HuffmanTree::encode(const std::string& text, std::string& encodedText)
{
	if (m_root == nullptr)
	{
		build(text);
	}

	encodedText = "";

	for (int i = 0; i < text.length(); i++)
	{
		char huffmanChar = text[i];
		std::set<char> symbols = m_root->getSymbols();

		if (symbols.find(huffmanChar) == symbols.end())
		{
            cout<< huffmanChar <<": ";
			return -1;   //дерево построено не верно
		}

		if (symbols.size() == 1)
		{
			encodedText.push_back('0');

			continue;
		}

		Node* node = m_root;

		while ((node->getSymbols().size()) > 1)
		{
			Node* left = node->getLeft();

			if (left == nullptr)
			{
				continue;
			}

			std::set<char> leftSymbols = left->getSymbols();

			if (leftSymbols.find(huffmanChar) != leftSymbols.end())
			{
				encodedText.push_back('0');

				node = left;
			}
			else
			{
				encodedText.push_back('1');

				node = node->getRight();
			}
		}
	}

	return double(encodedText.size()) / double(text.size() * 8); //находим коэффециент сжатия
}

bool HuffmanTree::decode(const std::string& encodedText, std::string& decodedText) const
{
	decodedText = "";

	Node* node = m_root;

	if (node == nullptr)        //ошибка в декодировании корня дерева
	{
		return false;
	}

	for (char huffmanChar : encodedText)
	{
		if (m_root->getSymbols().size() == 1)
		{
			if (huffmanChar != '0')
			{
				return false;
			}

			decodedText += *(node->getSymbols().begin());

			continue;
		}
		if (huffmanChar == '0')
		{
			node = node->getLeft();
		}
		else if (huffmanChar == '1')
		{
			node = node->getRight();
		}
		else
		{
			return false;
		}

		if (node == nullptr)
		{
			return false;
		}
		else if (node->getSymbols().size() == 1)
		{
			decodedText += *(node->getSymbols().begin());

			node = m_root;
		}
	}

	return m_root;
}