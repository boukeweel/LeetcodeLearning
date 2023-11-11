// 49. Group Anagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace  std;
vector<vector<string>> GroupAnagrams(vector<string>& strs);
string GetKey(string word);

int main()
{
    vector<string> strings{ "cat","bat","eat","ate","tea","tab" };

    vector<vector<string>> result{ GroupAnagrams(strings) };
}


//I needed help with this solution its not mine own, had a hard time with this one
vector<vector<string>> GroupAnagrams(vector<string>& strs)
{
    map<string, vector<string>> anagramMap;
    for (int i = 0; i < strs.size(); ++i)
    {
        string key = GetKey(strs[i]);
        anagramMap[key].push_back(strs[i]);
    }

    vector<vector<string>> result;
    for (auto it = anagramMap.begin(); it != anagramMap.end(); it++) {
        result.push_back(it->second);
    }
    return result;
}
string GetKey(string word)
{
    vector<int> count(26);
    for (int i = 0; i < word.size(); ++i)
    {
        count[word[i] - 'a']++;
    }

    string key{ "" };
    for (int i = 0; i < count.size(); ++i)
    {
        //if you dont do a char after the number it wil get a wrong answer
        key.append(to_string(count[i]) + '|');
    }

    return key;
}
