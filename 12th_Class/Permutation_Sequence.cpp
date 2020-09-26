// 60. Permutation Sequence
// Link - https://leetcode.com/problems/permutation-sequence/
/**
 * The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314" 
 **/


    // Function for calculating factorials
    vector<int> factorial (int n) {
        vector<int> fact;
        fact.push_back(1);
        
        int i;
        for (i = 1; i <= n; i++)
            fact.push_back(fact[i - 1]*i);
        
        return fact;
    }
    
    int getAvailableDigit (int pos, vector<int>& digitSet) {
        int i;
        
        for (i = 1; i < digitSet.size(); i++) {
            if (!digitSet[i])
                pos -= 1;
            
            if (pos == 0)
                return i;
        }
        
        return -1;
    }
    
    string getPermutation(int n, int k) {
        // first digit of kth permutation is ((k - 1)/(n - 1)!) + 1
        //  for next digit ->
        // nNew = n - 1
        // newK = (k - 1)%(n - 1)!
        int tempN = n, tempK = k;
        vector<int> digitSet(n + 1, 0);  // digitset[i] = 1 means i is used as a digit already
        int currDigit = 1;
        vector<int> fact = factorial(n);
        string res = "";
        
        while(tempK > 0) {
            currDigit = 1 + ((tempK - 1)/fact[tempN - 1]);
            int nextDigit = getAvailableDigit(currDigit, digitSet);
            
            res += (nextDigit + '0');
            
            // changing to new values
            tempK = tempK%fact[tempN - 1];
            tempN -= 1;
            digitSet[nextDigit] = 1;
        }
        
        for (int i = digitSet.size() - 1; i > 0; i--) {
            if (!digitSet[i]) {
                res += (i + '0');
                digitSet[i] = 1;
            }
        }
        
       return res; 
    }


    