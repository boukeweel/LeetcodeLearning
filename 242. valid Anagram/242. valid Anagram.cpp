// 242. valid Anagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//map always soort on alphabetical order becuase of ascII table and assigned numbers.
//did not know that before this
//
//

#include <iostream>
#include <map>
#include <unordered_map>
bool isAnagram(std::string s, std::string t);
int main()
{
    std::string s{ "abcdefghijklmnopqrstuvwxyz" };
    std::string t{ "abcdfeghijklmnopqrstuvwxyz" };
    if (isAnagram(s, t))
        std::cout << "is anagram\n";
    else
        std::cout << "is not anagram\n";
}

//works but why use 3 for loops able to do in 2
// is accepted by leetcode
/*
bool isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size())
        return false;

    std::map<char, int> sMap;
    std::map<char, int> tMap;


    
    for (char character : s)
    {
        sMap[character]++;
    }
    for (char character : t)
    {
        tMap[character]++;
    }

    for (int i = 0; i < sMap.size(); ++i)
    {
        if (sMap[i] != tMap[i]) return false;
    }

    return true;
}
*/

//only uses 2 forloops little bit better
//when run in leetcode it tells me its slower is slower by almoste double the ms why?
/*
bool isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size())
        return false;

    std::map<char, int> sMap;
    std::map<char, int> tMap;

    for (int i = 0; i < s.size(); ++i)
    {
    	sMap[s[i]]++;
    	tMap[t[i]]++;
    }
    for (int i = 0; i < sMap.size(); ++i)
    {
        if (sMap[i] != tMap[i]) return false;
    }

    return true;
}
*/


//will it be faster with unordered_map? because I saw that it was faster with a unordered_set in problem 217
//it is faster and uses less memory, but will it be the fastest if I use 3 for loops again?
/*
bool isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size())
        return false;

    std::unordered_map<char, int> sMap;
    std::unordered_map<char, int> tMap;

    for (int i = 0; i < s.size(); ++i)
    {
        sMap[s[i]]++;
        tMap[t[i]]++;
    }
    for (int i = 0; i < sMap.size(); ++i)
    {
        if (sMap[i] != tMap[i]) return false;
    }

    return true;
}
*/

//this one is the fastest, and uses the least amount of memory even tho you use 3 for loops
bool isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size())
        return false;

    std::unordered_map<char, int> sMap;
    std::unordered_map<char, int> tMap;

    for (char character : s)
    {
        sMap[character]++;
    }
    for (char character : t)
    {
        tMap[character]++;
    }

    for (int i = 0; i < sMap.size(); ++i)
    {
        if (sMap[i] != tMap[i]) return false;
    }

    return true;
}
