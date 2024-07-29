#include <iostream>
#include "EncodingTree.hpp"

int main()
{
	EncodingTree tree;
	tree.readCharacters();
	tree.generateEcodingTree();
	tree.displayEncodingLevels();
	tree.decodeFile();
	tree.encodeFile();
	
	return 0;
}