// 40. Combination Sum II
// Link - https://leetcode.com/problems/combination-sum-ii/

/**
 Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
] 
 **/

void helper(vector<int>& candidates, int index, vector<int>& curr, int target, vector<vector<int>>& res) {
        // base case
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        
        if (index == candidates.size())
            return;
        
        // recursive case
        // exclude
        int nextIndex = index + 1;
        while(nextIndex < candidates.size() && candidates[index] == candidates[nextIndex])
            nextIndex += 1;
       
        helper(candidates, nextIndex, curr, target, res);
        
        // include
        if (target >= candidates[index]) {
            curr.push_back(candidates[index]);
            helper(candidates, index + 1, curr, target - candidates[index], res);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort (candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        helper(candidates, 0, curr, target, res);
        return res;
    }