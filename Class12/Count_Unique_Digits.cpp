// 357. Count Numbers with Unique Digits
// Link - https://leetcode.com/problems/count-numbers-with-unique-digits/

/**
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:

Input: 2
Output: 91 
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
             excluding 11,22,33,44,55,66,77,88,99
 

Constraints:

0 <= n <= 8

 **/

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        
        int i, CountNum = 0, runProd = 1, nextDigit = 9;
        for (i = 1; i <= n; i++) {
            // number of i digit number with unique digits
            if (i == 1)
                CountNum += 10;
            
            else {
                int j, runProd = 9, factor = 9;
                
                // for jth digit in i digits number
                for (j = 2; j <= i; j++) {
                    runProd *= factor;
                    factor -= 1;
                }
                CountNum += runProd;
            }
        }
        return CountNum;
    }

    