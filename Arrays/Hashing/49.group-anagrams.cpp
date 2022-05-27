/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (62.85%)
 * Likes:    9294
 * Dislikes: 316
 * Total Accepted:    1.4M
 * Total Submissions: 2.1M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */


#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Maps
    // Time Complexity - O(n*m*logm), m is the length of each string
    // Space Complexity - O(n*m)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> out;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            vector<string> ana;
            sort(temp.begin(), temp.end());
            if(m.find(temp) == m.end()){
                ana.push_back(strs[i]);
                m[temp] = ana;
            }else{
                m[temp].push_back(strs[i]);
            }
        }

        for(auto i: m){
            out.push_back(i.second);
        }
        return out;
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // TLE!!
    // Nice approach though
    // Time Complexity - O()
    // Space Complexity - O()
    void makeMap(unordered_map<char, int> &m, string k){
        for(int i = 0; i < k.size(); i++){
            m[k[i]]++;
        }
    }

    bool checkAnagram(string t, unordered_map<char, int> m1, string k){
        if(t == k) return true;
        if(t == "") return false;
        if(t.size() != k.size()) return false;
        for(int i = 0; i < t.size(); i++){
            if(m1.find(t[i]) == m1.end() || m1[t[i]] == 0){
                return false;
            }else{
                m1[t[i]]--;
            }
        }
        return true;
    }

    vector<string> checkStack(stack<string> &vals, stack<string> &empty){
        string temp = vals.top();
        // cout<<temp<<endl;
        vals.pop();
        unordered_map<char, int> freq;
        vector<string> anagrams;
        anagrams.push_back(temp);
        makeMap(freq, temp);
        while (!vals.empty()) {
            string top = vals.top();
            bool anagram = checkAnagram(top, freq, temp);
            // cout<<top<<" "<<anagram<<endl;
            if(anagram){
                anagrams.push_back(top);
            }else{
                empty.push(top);
            }
            vals.pop();
        }
        return anagrams;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        stack<string> s1;
        stack<string> s2;
        vector<vector<string>> out;
        for (int i = 0; i < strs.size(); i++) {
            s1.push(strs[i]);
        }
        while (!s1.empty() || !s2.empty()) {
            vector<string> anagramSet;
            if (s1.empty()) {
                anagramSet = checkStack(s2, s1);
            }else{
                anagramSet = checkStack(s1, s2);
            }
            out.push_back(anagramSet);
        }
        return out;
    }
};
// @lc code=end
