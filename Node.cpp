#include <iostream>

#include "node.h"
using namespace sorting;


node::node()
{
	count = 0;
	value = "";
}


void node::insert(node *root, const std::string& str)
{
	node *curr_node = root;
	for (char c : str)
	{
		const int idx = hash(c);

		// If the index is empty, create a new node on it
		if (!curr_node->children[idx])
		{
			curr_node -> children[idx] = new node();
		}
		// Iterate to the next node
		curr_node = curr_node->children[idx];
	}
	
	if (curr_node-> value.empty())
	{
		curr_node-> value = str;
	}
	curr_node->count++;
}


int node::hash(char c)
{
	switch (c)
	{
	case '-':
		return 0;
	case '\'':
		return 1;
	default:
		return c - 95;
	}
}
