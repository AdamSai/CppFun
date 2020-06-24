// SortingFun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include "trie.h"
#include "3dParty/re2Project/re2/re2.h"
#include "3dParty/re2Project/re2/stringpiece.h"

using namespace sorting;
int main()
{
	trie* my_trie = new trie();

	std::string text_file_path =
		R"(D:\Github\Algorithms\SortingShakespeare\SortingShakespeare\shakespeare-complete-works.txt)";

	// Read file

	std::ifstream inFile;
	std::cout << "Opening file\n";
	inFile.open(text_file_path);
	if(!inFile)
	{
		std::cerr << "unable to open file at path: " << text_file_path;
		exit(1);
	}
	std::cout << "Reading file\n";
	std::stringstream strStream;
	strStream << inFile.rdbuf();
	auto str = strStream.str();
	// Convert to lower case

	std::cout << "Converting string to lower case\n";
	std::for_each(str.begin(), str.end(), [](char& c)
	{
		c = ::tolower(c);
	});
	std::cout << "Finished\n";
	inFile.close();


	// Regex
	std::vector<std::string> matches;
	re2::StringPiece input(str);
	std::string var;

	auto begin = std::chrono::high_resolution_clock::now();
	std::cout << "Finding matches" << std::endl;
	RE2 regexp("([a-zA-Z]+'?-?[a-zA-Z]*)");
	while(RE2::FindAndConsume(&input, regexp, &var))
	{
		matches.push_back(var);
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	
	std::cout << "Matches found: " << matches.size() << " in " << ms << " ms " << std::endl;

	



	// Test
	std::cout << "============Sorting:============\n";
	//std::cout << "============before:============\n";
	//for(int i = 0; i < 20; i++)
	//{
	//	std::cout << matches[i] << std::endl;
	//}
	begin = std::chrono::high_resolution_clock::now();

	trie::sort(matches);
	end = std::chrono::high_resolution_clock::now();
	dur = end - begin;
	ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	//std::cout << "============after:============\n";

	//for (int i = 0; i < 20; i++)
	//{
	//	std::cout << matches[i] << std::endl;
	//}


	 dur = end - begin;
	 ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

	std::cout << "Finished sorting in: " << ms << "ms" << std::endl;
}
