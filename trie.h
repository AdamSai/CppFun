#pragma once
#include <vector>
#include <string>

namespace sorting
{
	class node;

	class trie
	{
	public:
		trie();
		static void sort(std::vector<std::string>& str);
	private:
		static void to_array(node* root, std::vector<std::string>& str);
		static unsigned int currentIndex;
	};
}
