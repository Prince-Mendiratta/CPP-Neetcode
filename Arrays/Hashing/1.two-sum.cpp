/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (48.02%)
 * Total Accepted:    5.6M
 * Total Submissions: 11.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 * 
 * 
 * 
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Bruteforce Approach
    // Time Complexity - O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    out.push_back(i);
                    out.push_back(j);
                    return out;
                }
            }
        }
        return out;
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // HashMap
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> out;
        unordered_map<int, int> m1;
        for(int i = 0; i < nums.size(); i++){
            int val = target - nums[i];
            if(m1.find(val) == m1.end()){
                m1[nums[i]] = i;
            }
            else{
                out.push_back(i);
                out.push_back(m1[val]);
                return out;
            }
        } // Worst - O(n)
        return out;
    }
};
