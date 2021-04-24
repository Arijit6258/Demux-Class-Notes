// Link - https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/


// ------------------------------------------------------------------------------------------------

// Q.

//     Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

//     In case of a tie, return the minimum such integer.

//     Notice that the answer is not neccesarilly a number from arr.

    

//     Example 1:

//     Input: arr = [4,9,3], target = 10
//     Output: 3
//     Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
//     Example 2:

//     Input: arr = [2,3,5], target = 10
//     Output: 5
//     Example 3:

//     Input: arr = [60864,25176,27249,21296,20204], target = 56803
//     Output: 11361
    

//     Constraints:

//     1 <= arr.length <= 10^4
//     1 <= arr[i], target <= 10^5


// -------------------------------------------------------------------------------



// Solution : 


class Solution {
public:
    int getSum (int val, vector<int>& arr) {
        int sum = 0;
        for (int n : arr) {
            if (n > val) sum += val;
            else sum += n;
        }
        
        return sum;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int lo = 0, hi = INT_MIN;
        for (int n : arr) {
            hi = max(hi, n);
        }
        
        // predicate - sum <= target
        // TTT*FFF*
        // find last T and first F
        
        // last T -
        while(lo < hi) {
            int mid = lo+(hi-lo+1)/2;
        
            if (getSum(mid, arr) <= target) lo = mid;
            else hi = mid-1;
        }
        
        
        int s1 = getSum(lo, arr), s2 = getSum(lo+1, arr);
        return abs(s1-target) <= abs(s2-target) ? lo : lo+1;
    }
};