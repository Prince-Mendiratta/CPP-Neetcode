/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (53.24%)
 * Likes:    17154
 * Dislikes: 956
 * Total Accepted:    1.5M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the i^th line are (i, 0) and (i,
 * height[i]).
 * 
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 * 
 * Return the maximum amount of water a container can store.
 * 
 * Notice that you may not slant the container.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [1,1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 * 
 * 
 */


#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
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
    // TLE!!!
    int maxArea(vector<int>& height) {
        int maxVol = 0;
        for (int i = 0; i < height.size()-1; i++) {
            for (int j = i+1; j < height.size(); j++) {
                int xaxis = abs(j - i);
                int vol = min(height[j],height[i]) * xaxis;
                if(vol > maxVol){
                    maxVol = vol;
                }
            }
            
        }
        return maxVol;
    }

    //////////////////////////////////
    //////      APPROACH 2      //////
    //////////////////////////////////
    // Two pointer
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    int maxArea2(vector<int>& height) {
        int maxVol = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            int xaxis = abs(j - i);
            int vol = min(height[j],height[i]) * xaxis;
            if(vol > maxVol){
                maxVol = vol;
            }
            if(height[i] > height[j]){
                j--;
            }else if(height[i] < height[j]){
                i++;
            }else{
                i++;
            }
        }
        return maxVol;
    }
};
// @lc code=end
