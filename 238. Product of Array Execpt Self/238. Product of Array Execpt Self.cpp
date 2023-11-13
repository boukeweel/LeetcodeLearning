// 238. Product of Array Execpt Self.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums);

int main()
{
    std::vector<int> Numbers{ 1,2,3,4 };
    std::vector<int> result{ productExceptSelf(Numbers) };

    for (int value : result)
    {
        std::cout << value << " ";
    }
}

//it works but it is not fast enough needs to be o(n), because it loops 2 times true the list
//std::vector<int> productExceptSelf(std::vector<int>& nums)
//{
//    std::vector<int> results(nums.size(),1);
//
//    for (int i = 0; i < nums.size(); ++i)
//    {
//	    for (int j = 0; j < nums.size(); ++j)
//	    {
//            if(i == j)
//            {
//                continue;
//            }
//            results[i] = results[i] * nums[j];
//	    }
//    }
//
//    return results;
//}

//got this solution online because was taking to long to find the solution 
//works by mutliplying everything before the number, and than multiplying everything after the number, and at the end multiplying them both with each other.
std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    std::vector<int> results(nums.size(), 1);


    int prefix{ 1 };
    for (int i = 0; i < nums.size(); ++i)
    {
        results[i] = prefix;
        prefix = prefix * nums[i];
    }

    int postfix{ 1 };
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        results[i] = results[i] * postfix;
        postfix = postfix * nums[i];
    }

    return results;
}