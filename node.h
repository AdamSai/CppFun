#pragma once
#include <array>
#include <string>
#include <vector>

namespace sorting
{

	class node
	{

	public:
		node();
		node* children[28]{};
		unsigned short int count;
		std::string value;
		static void insert(node *root, const std::string& str);
	private:
		static int hash(char c);
	};
}
