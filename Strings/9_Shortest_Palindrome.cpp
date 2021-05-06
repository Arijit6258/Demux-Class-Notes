// Link - https://leetcode.com/problems/shortest-palindrome/


// ------------------------------------------------------------------------------------------------


// Q. 

//     You are given a string s. You can convert s to a palindrome by adding characters in front of it.

//     Return the shortest palindrome you can find by performing this transformation.

    

//     Example 1:

//     Input: s = "aacecaaa"
//     Output: "aaacecaaa"
//     Example 2:

//     Input: s = "abcd"
//     Output: "dcbabcd"
    

//     Constraints:

//     0 <= s.length <= 5 * 104
//     s consists of lowercase English letters only.


// ----------------------------------------------------------------------------------------------------------


// Solution - 


class Solution {
public:
    string shortestPalindrome(string s) {
        string srev = s;
        reverse(srev.begin(), srev.end());
        string con_str = s+'#'+srev;
        int n = s.size();
        
        // calculate LPS of last character
        vector<int> lps (2*n+1, 0);
        
        for (int i = 1; i < con_str.size(); i++) {
            int j = lps[i-1];
            while((j > 0) && (con_str[j] != con_str[i])) {
                j = lps[j-1];
            }
            
            if (con_str[j] == con_str[i]) lps[i] = j+1;
            else lps[i] = 0;
        }
        
        // cout << lps[2*n] << endl;
        
        string append = s.substr(lps[2*n]);
        reverse(append.begin(), append.end());
        return append+s;
    }
};