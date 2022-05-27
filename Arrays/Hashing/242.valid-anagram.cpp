/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (60.58%)
 * Likes:    4862
 * Dislikes: 214
 * Total Accepted:    1.3M
 * Total Submissions: 2.1M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 * 
 */


#include <iostream>
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
    // Time Complexity - O(n+m)
    // Space Complexity - O(n)
    void makeMap(unordered_map<char, int> &m, string k){
        for(int i = 0; i < k.size(); i++){
            m[k[i]]++;
        }
    }

    bool checkAnagram(string &t, unordered_map<char, int> &m1){
        for(int i = 0; i < t.size(); i++){
            if(m1.find(t[i]) == m1.end() || m1[t[i]] == 0){
                return false;
            }else{
                m1[t[i]]--;
            }
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        if (s.size() > t.size()) {
            makeMap(m1, t);
            return checkAnagram(s, m1);
        }else{
            makeMap(m1, s);
            return checkAnagram(t, m1);
        }
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Sort the strings
    // Time Complexity - O(log(n+m))
    // Space Complexity - O(1)
    bool isAnagram1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
};
// @lc code=end
