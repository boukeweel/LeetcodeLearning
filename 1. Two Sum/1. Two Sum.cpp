// 1. Two Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

std::vector<int> TwoSum(std::vector<int>& nums, int target);

int main()
{
    std::vector<int> numbers{ 1,4,3,2 };
    int target{ 6 };

    std::vector<int> result{ TwoSum(numbers,target) };
    for (int number : result)
    {
        std::cout << number << " ";
    }
    
}

//I know do it with minus but is there a diffrence I use + instead?
//this solution is good on the memory side of thing but a bit slower on the speed
/*
std::vector<int> TwoSum(std::vector<int>& nums, int target)
{
    int tempTarget{ target };
    std::vector<int> indexNumbers{};
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
            tempTarget -= nums[i];
            tempTarget -= nums[j];
            if(tempTarget == 0)
            {
                indexNumbers.push_back(i);
                indexNumbers.push_back(j);
                return indexNumbers;
            }
            tempTarget = target;
		}
	}
    return std::vector<int>{};
}
*/


//this way its slower and uses a bit more memory
/*
std::vector<int> TwoSum(std::vector<int>& nums, int target)
{
    int tempTarget{ 0 };
    std::vector<int> indexNumbers{};
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            tempTarget += nums[i];
            tempTarget += nums[j];
            if (tempTarget == target)
            {
                indexNumbers.push_back(i);
                indexNumbers.push_back(j);
                return indexNumbers;
            }
            tempTarget = 0;
        }
    }
    return std::vector<int>{};
}
*/

//here I dont make a seprated indexNumber Vector and just return it only, will it make it faster?
//it makes it faster
/*
std::vector<int> TwoSum(std::vector<int>& nums, int target)
{
    int tempTarget{ target };
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            tempTarget -= nums[i];
            tempTarget -= nums[j];
            if (tempTarget == 0)
            {
                return {i,j};
            }
            tempTarget = target;
        }
    }
    return std::vector<int>{};
}
*/

//can you get it in 1 for loop instead of 2?
//I need some help to find this solution
//this solution is really fast, but it is using more memory than the rest
/*
std::vector<int> TwoSum(std::vector<int>& nums, int target)
{
    std::map<int, int> numbersMap;
	for (int i = 0; i < nums.size(); ++i)
	{
        int result = target - nums[i];
        if(numbersMap.find(result) != numbersMap.end())
        {
            return{ numbersMap[result], i };
        }
        numbersMap[nums[i]] = i;
	}
    return std::vector<int>{};
}
*/

//is it better with a unorderd map?
//is even faster but, still uses more memory than the first 3 try's
std::vector<int> TwoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> numbersMap;
    for (int i = 0; i < nums.size(); ++i)
    {
        int result = target - nums[i];
        if (numbersMap.find(result) != numbersMap.end())
        {
            return{ numbersMap[result], i };
        }
        numbersMap[nums[i]] = i;
    }
    return std::vector<int>{};
}