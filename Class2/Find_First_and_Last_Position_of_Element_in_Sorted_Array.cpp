/*** 
 * 
 * Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Problem Statement

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9
***/

// Explicit Search Question

vector<int> searchRange(vector<int>& nums, int target) {
        // First Position
        // FFF*TTT*
        // P(X) : X >= target, first T
        
        int n = nums.size(), lo, hi, mid;
        vector<int> res;
        if (n == 0)
            return {-1, -1};
        
        lo = 0, hi = n - 1;
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            
            if (nums[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
        }
        
        if (nums[lo] != target) 
            return {-1, -1};
        
        // First Occurance
        res.push_back(lo);
        
        // Last Position
        // FFF*TTT*
        // P(X) : X > target
        
        lo = 0, hi = n - 1;
        while(lo < hi) {
            mid = lo + (hi - lo + 1)/2;
            if (nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid;
        }
        
        res.push_back(lo);
        
        return res;
    }