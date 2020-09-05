// 1300. Sum of Mutated Array Closest to Target
// Link - https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

// Problem statement - 
/**
        Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

        In case of a tie, return the minimum such integer.

        Notice that the answer is not neccesarilly a number from arr.

        

        Example 1:

        Input: arr = [4,9,3], target = 10
        Output: 3
        Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
        Example 2:

        Input: arr = [2,3,5], target = 10
        Output: 5
        Example 3:

        Input: arr = [60864,25176,27249,21296,20204], target = 56803
        Output: 11361
        

        Constraints:

        1 <= arr.length <= 10^4
        1 <= arr[i], target <= 10^5 

 **/

class Solution {
public:
    int get_sum (int value, vector<int> &arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > value)
                sum += value;
            else
                sum += arr[i];
        }
        return sum;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        // find the value for s(v) <= target with v as large as possible
        // search space is 0 to max_element of array
        int n = arr.size(), lo, hi, mid;
        
        lo = 0, hi = 0;
        // TTT*FFF*
        // P(X) : S(v) <= target
        // last T
        for (int i = 0; i < arr.size(); i++)
            hi = max(hi, arr[i]);
        
        while(lo < hi) {
            mid = lo + (hi - lo + 1)/2;
            if (get_sum (mid, arr) <= target)
                lo = mid;
            else
                hi = mid - 1;
        }
        
        // Sanity check
        // no need to sanity check because we are considering 0 as a potential answer.
        // So there will be one true at any point.
        
        int S1 = get_sum(lo, arr), S2 = get_sum(lo + 1, arr);
        int diff1 = abs(target - S1), diff2 = abs(target - S2);
        
        if (diff1 <= diff2)
            return lo;
        else
            return lo + 1;
    }
};