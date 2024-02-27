#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>

#include "HuffmanTree.h"

using std::cout;
using std::endl;
using std::string;
using std::set;

int main()
{
    set<char> test;
    string text1 = "You look so greate! Which night you don't sleep?";
    int frequencies[256] = {};


	for (int i = 0; i < text1.length(); i++)
	{
		frequencies[text1[i]]++;
        test.insert(text1[i]);
	}


//    for (int i = 0; i < text1.length(); i++)
//    {
//        cout << text1[i] << ":" << frequencies[text1[i]] << endl;
//    }
   
    
    std::ifstream inputFile("/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/input1.txt"); //("input.txt");
    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    //Первый этап кодирования: собираем дерево из символов
    HuffmanTree huffmanTree;
    huffmanTree.build(text);

    //Второй этап кодирования: кодирование по дереву Хаффмана
    std::string encodedText;

    double compressionRatio = huffmanTree.encode(text, encodedText);
    cout << "Data compression: " << compressionRatio << endl;

    if (encodedText.length())
    {
        cout << encodedText << endl;
    }
    else
    {
        cout << "Empty!" << endl;
    }

    std::ofstream encodedFile("/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/encoded.txt"); //("encoded.txt");
    encodedFile << encodedText;
    encodedFile.close();

    //Декодирование кода Хаффмана
    std::ifstream encodedInputFile("/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/encoded.txt"); //("encoded.txt");
    std::string encodedInputText((std::istreambuf_iterator<char>(encodedInputFile)), std::istreambuf_iterator<char>());

    std::string decodedText;
    huffmanTree.decode(encodedInputText, decodedText);
    std::ofstream decodedFile("/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/decoded.txt"); //("decoded.txt");
    decodedFile << decodedText;
    decodedFile.close();

    if (text == decodedText)
    {
        cout << "Data decoding completed successfully" << endl;
    }
    else
    {
        cout << "Data decoding failed" << endl;
    }

    return 0;
}