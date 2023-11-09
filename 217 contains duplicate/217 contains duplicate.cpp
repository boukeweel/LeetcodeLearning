// 217 contains duplicate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums);

int main()
{
	std::vector<int> testVector{ 1,2,3,4 };

	if (containsDuplicate(testVector))
		std::cout << "contains dublicated\n";
	else
		std::cout << "does not contains dublicated\n";
}

/***
 *	works but is to slow
 *	this one is O(n*log(n)); bad :(
 */

/*
bool containsDuplicate(std::vector<int>& nums)
	{
	std::vector<int> tempVec{};

	for (int element : nums)
	{
		auto numIt = std::find(tempVec.begin(), tempVec.end(), element);
		if (numIt != tempVec.end())
			return true;

		tempVec.push_back(element);
	}
	return false;
	}
 */

/**
 * better works faster
 * this one is O(n); good :)
 *
 * learned that unorderd_set are really good if you need to find thing is a list
 */
bool containsDuplicate(std::vector<int>& nums)
{
	std::unordered_set<int> tempSet{};

	for (int element : nums)
	{
		if (tempSet.find(element) != tempSet.end())
			return true;

		tempSet.insert(element);
	}
	return false;
}
