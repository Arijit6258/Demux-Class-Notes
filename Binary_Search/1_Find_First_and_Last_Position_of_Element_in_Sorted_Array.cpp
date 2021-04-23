// Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Q. 

//     Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

//     If target is not found in the array, return [-1, -1].

//     Follow up: Could you write an algorithm with O(log n) runtime complexity?

    

//     Example 1:

//     Input: nums = [5,7,7,8,8,10], target = 8
//     Output: [3,4]
//     Example 2:

//     Input: nums = [5,7,7,8,8,10], target = 6
//     Output: [-1,-1]
//     Example 3:

//     Input: nums = [], target = 0
//     Output: [-1,-1]
    

//     Constraints:

//     0 <= nums.length <= 105
//     -109 <= nums[i] <= 109
//     nums is a non-decreasing array.
//     -109 <= target <= 109


// ------------------------------------------------------------------------------------------------


// Solution : 

// Approach 1 - 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        if (n == 0) return {-1, -1};
        
        // Binary search 1 : find the last index which has element less than target
        // P(X) : X >= target
        // FFF*TTT* - find the first T
        
        int lo1 = 0, hi1 = n-1;
        while(lo1 < hi1) {
            int mid = lo1+(hi1-lo1)/2;
            if (nums[mid] >= target) hi1 = mid;
            else lo1 = mid+1;
        }
        
        // not found target
        if (nums[lo1] != target) return {-1, -1};
        
        // Binary search 2 : find the first index which has element greater than target
        // P(X) : X > target
        // FFF*TTT* - find first T
        
        int lo2 = 0, hi2 = n-1;
        while(lo2 < hi2) {
            int mid = lo2+(hi2-lo2)/2;
            if (nums[mid] > target) hi2 = mid;
            else lo2 = mid+1;
        }
        
        vector<int> res;
        res.push_back(lo1);
        if (nums[lo2] == target) res.push_back(lo2);
        else res.push_back(lo2-1);
        
        return res;
    }
};


// ------------------------------------------------------------------------------------------------


// Approach 2 - 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        if (n == 0) return {-1, -1};
        
        // Binary search 1 : find the last index which has element less than target
        // P(X) : X < target
        // TTT*FFF* - find the last T
        
        int lo1 = 0, hi1 = n-1;
        while(lo1 < hi1) {
            int mid = lo1+(hi1-lo1+1)/2;
            if (nums[mid] < target) lo1 = mid;
            else hi1 = mid-1;
        }
        
        // Binary search 2 : find the first index which has element greater than target
        // P(X) : X > target
        // FFF*TTT* - find first T
        
        int lo2 = 0, hi2 = n-1;
        while(lo2 < hi2) {
            int mid = lo2+(hi2-lo2)/2;
            if (nums[mid] > target) hi2 = mid;
            else lo2 = mid+1;
        }

        vector<int> res;
        if (nums[lo1] == target) res.push_back(lo1);
        else if (lo1+1 < n && nums[lo1+1] == target) res.push_back(lo1+1);
        else return {-1, -1};
        
        if (nums[lo2] == target) res.push_back(lo2);
        else if (lo2-1 >= 0 && nums[lo2-1] == target) res.push_back(lo2-1);
        else return {-1, -1};
        
        return res;
    }
};