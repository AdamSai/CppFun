#include "trie.h"

#include <iostream>


#include "node.h"
using namespace sorting;


unsigned int trie::currentIndex;

trie::trie()
{
	currentIndex = 0;
}

void trie::sort(std::vector<std::string>& str)
{
	node* root = new node();
	for (auto& i : str)
	{
		node::insert(root, i);
	}

	to_array(root, str);
}

void trie::to_array(node* root, std::vector<std::string>& str)
{
	if(root == nullptr)
	{
		return;
	}
	// If the node is not empty add the value to the array
	if(!root-> value.empty())
	{
		for(int i = 0; i < root-> count; i++)
		{
			str[currentIndex++] = root->value;
		}
	}
	for (node *child : root->children)
	{
		to_array(child, str);
	}
}
