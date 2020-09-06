// 260. Single Number III
// Link - https://leetcode.com/problems/single-number-iii/
/**
 * Problem Statement -
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

1 <= nums.length <= 30000
 Each integer in nums will appear twice, only two integers will appear once.

**/


vector<int> singleNumber(vector<int>& nums) {
        // extracting a^b
        int a_xor_b = 0, i;
        for (i = 0; i < nums.size(); i++) 
            a_xor_b ^= nums[i];
        
        // mask
        int mask = (a_xor_b & (~(a_xor_b - 1)));
        int a = 0, b = 0;
        for (i = 0; i < nums.size(); i++) {
            if (mask & nums[i])
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        return {a, b};
    }