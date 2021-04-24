// Link - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// ------------------------------------------------------------------------------------------------


// Q. 

//     Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

//     Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

//     It is guaranteed that there will be an answer.

    

//     Example 1:

//     Input: nums = [1,2,5,9], threshold = 6
//     Output: 5
//     Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
//     If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
//     Example 2:

//     Input: nums = [44,22,33,11,1], threshold = 5
//     Output: 44
//     Example 3:

//     Input: nums = [21212,10101,12121], threshold = 1000000
//     Output: 1
//     Example 4:

//     Input: nums = [2,3,5,7,11], threshold = 11
//     Output: 3
    

//     Constraints:

//     1 <= nums.length <= 5 * 104
//     1 <= nums[i] <= 106
//     nums.length <= threshold <= 106




// --------------------------------------------------------------------------------------------------------------------


// Solution : 


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lower_bound = 1, upper_bound = INT_MIN, i, n = nums.size();
        
        for (i = 0; i < n; i++) {
            upper_bound = max(upper_bound, nums[i]);
        }
        
        // search for the divisor 
        // use binary search
        // P(X) : sum(nums[i]/X) <= threshold
        // FFF*TTT*
        // find first T
        
        while(lower_bound < upper_bound) {
            int divisor = lower_bound+(upper_bound-lower_bound)/2;
            int sum = 0;
            
            for (i = 0; i < n; i++) {
                sum += ceil((1.0*nums[i])/divisor);
            }
            
            if (sum <= threshold) upper_bound = divisor;
            else lower_bound = divisor+1;   
        }
        
        return lower_bound;
    }
};