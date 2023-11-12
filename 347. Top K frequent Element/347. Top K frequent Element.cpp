// 347. Top K frequent Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

std::vector<int> topKFrequent(std::vector<int>& nums, int k);

int main()
{
    std::vector<int> numbers{ 1,1,2,2,2,3,4,4,4,4 };
    std::vector<int> result{ topKFrequent(numbers,2) };

    for (int value : result)
    {
        std::cout << value << " ";
    }
}

//this solution works
//this solution is only slow, but it does not use a lot of memory
//is the slownes couple to the erase fucntion or something else?
std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
    std::map<int, int> resultMap;
    std::vector<int> result;
    for (int value : nums)
    {
        resultMap[value]++;
    }

    for (int i = 0; i < k; ++i)
    {
        int frequentNum{ 0 };
        int actualNum;
        for (const std::pair<int,int> pair : resultMap)
        {
        	if(frequentNum < pair.second)
        	{
        		frequentNum = pair.second;
                actualNum = pair.first;
        	}
        }
        resultMap.erase(actualNum);
        result.push_back(actualNum);
    }
    return result;
}
