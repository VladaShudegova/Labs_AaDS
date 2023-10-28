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
    string text = "Morning good! You are cool";
    int frequencies[256] = {};

	for (int i = 0; i < text.length(); i++)
	{
		frequencies[text[i]]++;
        test.insert(text[i]);
	}
    for (int i = 0; i < text.length(); i++)
    {
        cout << text[i] << ":" << frequencies[text[i]] << endl;
    }
   
    
    //std::ifstream inputFile("input.txt");
    //std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    //HuffmanTree labHuffmanTree;
    //labHuffmanTree.build(text);
    //std::string encodedText;

    //double compressionRatio = labHuffmanTree.encode(text, encodedText);
    //cout << "Data compression: " << compressionRatio << endl;

    //if (encodedText.length())
    //{
    //    cout << encodedText << endl;
    //}
    //else
    //{
    //    cout << "Empty!" << endl;
    //}

    //std::ofstream encodedFile("encoded.txt");
    //encodedFile << encodedText;
    //encodedFile.close();

    //std::ifstream encodedInputFile("encoded.txt");
    //std::string encodedInputText((std::istreambuf_iterator<char>(encodedInputFile)), std::istreambuf_iterator<char>());

    //std::string decodedText;
    //labHuffmanTree.decode(encodedInputText, decodedText);
    //std::ofstream decodedFile("decoded.txt");
    //decodedFile << decodedText;
    //decodedFile.close();

    //if (text == decodedText)
    //{
    //    cout << "Data decoding completed successfully" << endl;
    //}
    //else
    //{
    //    cout << "Data decoding failed" << endl;
    //}

    //return 0;
}