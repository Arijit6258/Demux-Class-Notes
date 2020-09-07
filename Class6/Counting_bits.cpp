// 338. Counting Bits
// Link - https://leetcode.com/problems/counting-bits/
/**
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

 **/

vector<int> countBits(int num) {
        vector<int> count_set(num + 1, 0);
        for (int i = 1; i <= num; i++)
            count_set[i] = count_set[i&(i - 1)] + 1;
        return count_set;
    }

    // Alternating solution

    vector<int> countBits(int num) {
        vector<int> count_set(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            if (i%2)
                count_set[i] = count_set[i - 1] + 1;
            else
                count_set[i] = count_set[i/2];
                
        }
        return count_set;
    }

.
