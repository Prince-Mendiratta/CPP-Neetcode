/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (40.38%)
 * Likes:    3702
 * Dislikes: 5229
 * Total Accepted:    1.3M
 * Total Submissions: 3.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Time Complexity - O(n)
    bool isValid(char *c){
        *c = *c >= 65 && *c <= 90 ? *c + 32 : *c;
        if(*c >= 48 && *c <= 57 || *c >= 97 && *c <= 122){
            return true;
        }
        if(*c == 32){
            return false;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j){
            cout<<s[i]<<s[j]<<endl;
            if(!isValid(&s[i])){
                i++;
            }else if(!isValid(&s[j])){
                j--;
            }else{
                if(s[i] == s[j]){
                    i++;
                    j--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
