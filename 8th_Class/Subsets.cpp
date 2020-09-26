// 78. Subsets
// Link - https://leetcode.com/problems/subsets/
/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

vector<vector<int>> subsets(vector<int> &nums, int index) {
        if (nums.size() == index)
            return {{}};
        
        int element = nums[index];
        vector<vector<int>> smallAns = subsets(nums, index + 1);
        int n = smallAns.size();
        for (int i = 0; i < n; i++) {
            vector<int> v = smallAns[i];
            v.push_back(element);
            smallAns.push_back(v);
        }
        return smallAns;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets(nums, 0);
    }