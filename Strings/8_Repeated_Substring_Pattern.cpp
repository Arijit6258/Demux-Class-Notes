// Link - https://leetcode.com/problems/repeated-substring-pattern/

// ------------------------------------------------------------------------------------------------

// Q.  

//     Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

    

//     Example 1:

//     Input: s = "abab"
//     Output: true
//     Explanation: It is the substring "ab" twice.
//     Example 2:

//     Input: s = "aba"
//     Output: false
//     Example 3:

//     Input: s = "abcabcabcabc"
//     Output: true
//     Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
    

//     Constraints:

//     1 <= s.length <= 104
//     s consists of lowercase English letters.



// ------------------------------------------------------------------------------------------------



// Solution : 


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s.substr(1)+s.substr(0, s.length()-1);
        
        int idx = t.find(s);
        
        if (idx == string::npos) 
            return false;
        
        return true;
    }
};