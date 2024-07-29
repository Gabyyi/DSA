#pragma once
#include <iostream>
#include <fstream>
#include "bst.hpp"
#include <vector>
#include <queue>
#include <string>
struct Character {
	char chr;
	int occ;
	Character(char c,int o):chr{c},occ{o}{}
};


class EncodingTree {
private:
	BinarySearchTree<int>  bst;
	BinarySearchTree<int> encodingTree;
	std::vector<Character> chars;
	char intToChar(int occ)
	{
		for (Character c : chars)
		{
			if (occ == c.occ)
				return c.chr;
		}
		return '#';
	}
	int charToInt(char C)
	{
		for (Character c : chars)
		{
			if (C == c.chr)
				return c.occ;

		}
		return -1;
	}
public:
	void add(Character c)
	{
		bst.insert(c.occ);
		chars.push_back(c);

	}
	Character removeMin()
	{
		int occ = bst.lowestValue();
		bst.removeInfo(bst.lowestValue());
		return Character(intToChar(occ), occ);
	}
	
	void generateEcodingTree()
	{
		encodingTree = *(bst.generateEncodingTree(&bst));
		
	}
	void displayEncodingLevels()
	{
		encodingTree.displayLevels();
	}
	bool encode(char c, std::string& path)
	{

		return encodingTree.findInEncodingTree(charToInt(c), path);
	}
	std::string encode(std::string& message)
	{
		std::string strB = "";
		for (char c : message)
		{
			std::string path = "";
			encode(c, path);
			strB.append(path);
			
		}
		return strB;
	}
	std::string decode(std::string message)
	{
		std::string decodedMessage = "";
		std::string messageAux = message;
		while (!messageAux.empty())
		{
			decodedMessage += intToChar(encodingTree.maxTRaverse(encodingTree.root, messageAux));
			
		}

		return decodedMessage;
	}

	void readCharacters()
	{
		ifstream in("characters.txt");
		char chr;
		int occ;
		while (in>>chr>>occ)
		{
			add(Character(chr, occ));
		}
		in.close();
	}
	void decodeFile()
	{
		std::ifstream in("encoded.in");
		std::string encoded = "";
		char c;
		while (in >> c)
			encoded += c;
		in.close();
		std::ofstream out("message.out");

		out << decode(encoded);
		out.close();
	}
	void encodeFile()
	{
		std::ifstream in("message.in");
		std::string message = "";
		char c;
		while (in >> c)
		{
			message += c;
		}
		in.close();
		std::ofstream out("encoded.out");
		out << encode(message);
		out.close();
	}

	

};