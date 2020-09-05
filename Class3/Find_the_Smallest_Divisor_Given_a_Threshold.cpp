// 1283. Find the Smallest Divisor Given a Threshold
// Link - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [2,3,5,7,11], threshold = 11
Output: 3
Example 3:

Input: nums = [19], threshold = 5
Output: 4
 

Constraints:

1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6

*/


// Predicate
    bool sum_satisfy(vector<int> &nums, int threshold, int divisor) {
        int sum = 0, i;
        
        for (i = 0; i < nums.size(); i++) {
            int x = nums[i]/divisor;
            if (nums[i]%divisor)
                x++;
            sum += x;
        }
        
        return sum <= threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        // define search space
        // 1 to max_element_of_array
        int n = nums.size(), max_Ele = INT_MIN;
        for (int i = 0; i < n; i++) {
            max_Ele = max(max_Ele, nums[i]);
        }
        
        // FFF*TTT*
        // Predicate : sum_satisfy(x) <= threshold
        // find first T
        int lo = 1, hi = max_Ele, mid;
        
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            if (sum_satisfy(nums, threshold, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }

    // time complexity - O(n * log(max_element))