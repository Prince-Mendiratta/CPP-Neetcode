/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (59.63%)
 * Likes:    3320
 * Dislikes: 908
 * Total Accepted:    1.2M
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Time Complexity - O(nlogn)
    // Space Complexity - O(1)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]==nums[i+1])
                return true;
        
        return false;
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    bool containsDuplicate2(vector<int>& nums) {
        unordered_map<int, int> m1;
        for (int i = 0; i < nums.size(); i++) {
            if(m1.find(nums[i]) != m1.end()){
                return true;
            }
            m1[nums[i]]++;
        }
        return false;
    }
};
// @lc code=end
