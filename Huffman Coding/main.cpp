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

    std::string Text = "/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/input1.txt";
    std::string EncodedText = "/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/encoded.txt";
    std::string DecodedText = "/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/decoded.txt";


    HuffmanTree huffmanTree;
    huffmanTree.encodeFile(Text, EncodedText);



//    //Декодирование кода Хаффмана
//    std::ifstream encodedInputFile("/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/encoded.txt"); //("encoded.txt");
//    std::string encodedInputText((std::istreambuf_iterator<char>(encodedInputFile)), std::istreambuf_iterator<char>());
//
//    std::string decodedText;
//    huffmanTree.decode(encodedInputText, decodedText);
//    std::ofstream decodedFile("/Users/vladashudegova/dev/Labs_TSU/Labs_AaDS/Huffman Coding/decoded.txt"); //("decoded.txt");
//    decodedFile << decodedText;
//    decodedFile.close();
//
//    if (text == decodedText)
//    {
//        cout << "Data decoding completed successfully" << endl;
//    }
//    else
//    {
//        cout << "Data decoding failed" << endl;
//    }
//
    return 0;
}