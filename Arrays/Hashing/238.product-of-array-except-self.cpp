/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (63.23%)
 * Likes:    12287
 * Dislikes: 745
 * Total Accepted:    1.2M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 * 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 * 
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The
 * output array does not count as extra space for space complexity analysis.)
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
    // Bruteforce
    // Time Complexity - O(n^2)
    // Space Complexity - O(1)
    // TLE!!
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>out(nums.size());
        for (int i = 0 ; i < nums.size(); i++) {
            int prod = 1;
            for (int j = 0; j < nums.size(); j++) {
                if(j == i){
                    continue;
                }
                prod = prod * nums[j];
            }
            out[i] = prod;
        }
        return out;
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Not a valid solution but a way
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    vector<int> productExceptSelf2(vector<int>& nums) {
        vector<int>out(nums.size());
        int prod = 1;
        int zeroes = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            if(nums[i] == 0){
                zeroes++;
                continue;
            }
            prod = prod * nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if(zeroes > 1 || zeroes == 1 && nums[i] != 0){
                out[i] = 0;
            }else if(zeroes){
                out[i] = prod;
            }else{
                out[i] = prod / nums[i];
            }
        }
        return out;
    }

    //////////////////////////////////
    //////      APPROACH 3      //////
    //////////////////////////////////
    // Separate Left and right product
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    vector<int> productExceptSelf3(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        if(n<1)
            return output;
        
        int product = 1;
        for(int i=0;i<n;++i)
        {
            product *= nums[i];
            output.push_back(product);            
        }
        
        product = 1;
        for(int i=n-1;i>0;--i)
        {
            output[i] = output[i-1]*product;
            product *= nums[i];
        }
        output[0] = product;
        
        return output;
    }
};
// @lc code=end
