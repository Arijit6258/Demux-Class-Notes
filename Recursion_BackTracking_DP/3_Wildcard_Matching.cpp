// Link - https://leetcode.com/problems/wildcard-matching/

// ------------------------------------------------------------------------------------------------

// Q.

    // Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    // '?' Matches any single character.
    // '*' Matches any sequence of characters (including the empty sequence).
    // The matching should cover the entire input string (not partial).

    

    // Example 1:

    // Input: s = "aa", p = "a"
    // Output: false
    // Explanation: "a" does not match the entire string "aa".
    // Example 2:

    // Input: s = "aa", p = "*"
    // Output: true
    // Explanation: '*' matches any sequence.
    // Example 3:

    // Input: s = "cb", p = "?a"
    // Output: false
    // Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
    // Example 4:

    // Input: s = "adceb", p = "*a*b"
    // Output: true
    // Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
    // Example 5:

    // Input: s = "acdcb", p = "a*c?b"
    // Output: false
    

    // Constraints:

    // 0 <= s.length, p.length <= 2000
    // s contains only lowercase English letters.
    // p contains only lowercase English letters, '?' or '*'.


// ------------------------------------------------------------------------------------------------

// Solution : 


// Memoization

class Solution {
public:
    bool isMatchHelper(const string& s, const string& p, int s_index, int p_index, vector<vector<int>>& cache) {
        // base case
        if (s == p) return true;
        
        if (s_index == s.size()) {
            while (p_index < p.size()) {
                if (p[p_index] != '*') return false;
                p_index++;
            }
            
            return true;
        }
        
        if (p_index == p.size() && s_index < s.size()) return false;
        
        // check if already calculated
        if (cache[s_index][p_index] != -1) return cache[s_index][p_index];
        
        // recursive case
        if (p[p_index] == '?') {
            cache[s_index][p_index] = isMatchHelper (s, p, s_index+1, p_index+1, cache);
        } else if (p[p_index] != '*') {
            if (p[p_index] == s[s_index]) {
                cache[s_index][p_index] = isMatchHelper (s, p, s_index+1, p_index+1, cache);
            } else {
                cache[s_index][p_index] = false;
            }
        } else {
            int temp = s_index;
            while(temp <= s.size()) {
                if (isMatchHelper(s, p, temp, p_index+1, cache)) {
                    cache[s_index][p_index] = true;
                    cache[temp][p_index] = true;
                    break;
                }
                
                temp++;
            }
            
            if (temp > s.size()) cache[s_index][p_index] = false;
        }
        
        
        return cache[s_index][p_index];
    }
    
    bool isMatch(string s, string p) {
        // clean up p for consecutive *
        string cleaned_p = "";
        for (char c : p) {
            if (cleaned_p.size() != 0 && cleaned_p[cleaned_p.size()-1] == '*' && c == '*') continue;
            cleaned_p += c;
        }
        
        int s_index = 0, p_index = 0;
        vector<vector<int>> cache (s.size()+1, vector<int>(cleaned_p.size()+1, -1));
        return isMatchHelper(s, cleaned_p, s_index, p_index, cache);
    }
};

/***

Time complexity: O(min(S,P)) for the best case, and O(2^min(S,P/2)) for the worst case, 
where S and P are lengths of the input string and the pattern correspondingly. 
The best case is quite obvious, let's estimate the worst case. 
The most time consuming is the situation where recursion forms the tree on the star character in the pattern. 
In this situation 2 branches are executed : helper(s, p[1:]) and helper(s[1:], p). 
The maximum number of stars in the pattern after data cleanup is P/2P/2 and hence the time complexity is 
O(2^min(S,P/2)).

***/


