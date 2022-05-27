/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (48.25%)
 * Likes:    9450
 * Dislikes: 421
 * Total Accepted:    676.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
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
    //////      APPROACH 0      //////
    //////////////////////////////////
    // BruteForce
    // Time Complexity - O(nlogn)
    int longestConsecutive0(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        // for(auto x: nums){
        //     cout<<x<<" ";
        // }
        cout<<endl;
        int longest = 0, current = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i-1] == nums[i]){
                continue;
            }else if(nums[i-1] == nums[i] - 1){
                current++;
            }else{
                // cout<<"longest is "<<longest<<" and current is "<<current<<endl;
                if (current > longest) {
                    longest = current;
                    current = 1;
                }else{
                    current = 1;
                }
            }
        }
        return max(longest, current);
    }

    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // HashMap
    // Time Complexity - O(n)
    // Space Complexity - O(n)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        int max_count = 0, count = 0;

        for (auto n : nums) {
            num_set.insert(n);
        }

        for (auto n : num_set) {
            if (!num_set.count(n - 1)) {
                count = 0;
                while (num_set.count(n)) {
                    count++;
                    n = n + 1;
                }
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};
// @lc code=end
