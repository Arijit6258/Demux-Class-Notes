// 137. Single Number II
// Link - https://leetcode.com/problems/single-number-ii/
/**
 * problem statement:
 *      
 * Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

    Note:

    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Example 1:

    Input: [2,2,3,2]
    Output: 3
    Example 2:

    Input: [0,1,0,1,0,1,99]
    Output: 99
 **/

    int singleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        
        // checking for 32 bits
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                // extract ith bit
                int mask = (1 << i);
                if (nums[j] & mask)
                    count += 1;
            }
            
            // checking number of set bits
            // if count == 3k + 1 then the answer has a set bit at ith position
            if (count%3)
                res = res | (1 << i);
        }
        
        return res;
    }
