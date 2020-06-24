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
		sorting::node::insert(root, i);
	}

	to_array(root, str);
}

void trie::to_array(node *root, std::vector<std::string>& str)
{
	if(root == nullptr)
	{
		return;
	}
	if(root-> value.empty() == false)
	{
		for(int i = 0; i < root-> count; i++)
		{
			str[currentIndex++] = root->value;
		}
	}
	int idx = 0;
	for (node *child : root->children)
	{
		to_array(child, str);
	}
}
