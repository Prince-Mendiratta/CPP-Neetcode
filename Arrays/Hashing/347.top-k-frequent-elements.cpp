/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (64.07%)
 * Likes:    9174
 * Dislikes: 369
 * Total Accepted:    965K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 * 
 * 
 * 
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 * 
 */


#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    //////////////////////////////////
    //////      APPROACH 1      //////
    //////////////////////////////////
    // Time Complexity - O(nlogn)
    // Space Complexity - O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        multimap<int, int, greater<int>> sorted;
        vector<int> out;
        for(auto num: nums){
            freq[num]++;
        }
        int highest = 0;
        for(auto entry: freq){
            sorted.insert(pair<int, int>(entry.second, entry.first));
        }
        int i = 0;
        for(auto itr: sorted){
            if(i < k){
                out.push_back(itr.second);
                i++;
            }else{
                break;
            }
        }
        return out;
    }
};
// @lc code=end
