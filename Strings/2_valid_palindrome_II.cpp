// Question Link - https://leetcode.com/problems/valid-palindrome-ii/

// Q: Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

//     Example 1:
//     Input: "aba"
//     Output: True

//     Example 2:
//     Input: "abca"
//     Output: True
//     Explanation: You could delete the character 'c'.

//     Note:
//     The string will only contain lowercase characters a-z. The maximum length of the string is 50000.






// Solution: 

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            // first mismatch in the substring 
            // second mismatch in the main string
            if (s[start] != s[end]) return false;
            
            start++;
            end--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int start = 0, end = s.size()-1;
        
        // find first mismatch
        while((start < end) && (s[start] == s[end])) {
            start++;
            end--;
        }
        
        // if no mismatch - already a palindrome
        if (start >= end) return true;
        
        // try deleting ith and jth character
        if (isPalindrome(s, start+1, end) || isPalindrome(s, start, end-1)) return true;
        
        return false;   
    }
};