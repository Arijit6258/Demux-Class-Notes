// 131. Palindrome Partitioning
// Link - https://leetcode.com/problems/palindrome-partitioning/
/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
] 
 **/

bool isPalindrome(string& s, int start, int end) {
        while(start <= end) {
            if (s[start] != s[end])
                return false;
            
            start += 1;
            end -= 1;
        }
        return true;
    }
    
    void helper(string& s, int startIndex, vector<string> curr, vector<vector<string>>& res) {
        // base case
        if (startIndex == s.size()) {
            res.push_back(curr);
            return;
        }
            
       
        // recursive case
        int i, n = s.length();
        string prefix = "";
        for (i = startIndex; i < n; i++) {
            prefix += s[i];
            
            if (isPalindrome(prefix, 0, prefix.size() - 1)) {
                curr.push_back(prefix);
                helper(s, i + 1, curr, res);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        if (s.length() == 0)
            return {};
        
        vector<vector<string>> res;
        helper(s, 0, {}, res);
        return res;
    }

// runtime - 68ms, space 45.7 MB



// Optimized Solution - 


    bool isPalindrome(string& s, int start, int end) {
        while(start <= end) {
            if (s[start] != s[end])
                return false;
            
            start += 1;
            end -= 1;
        }
        return true;
    }
    
    void helper(string& s, int startIndex, vector<string>& curr, vector<vector<string>>& res) {
        // base case
        if (startIndex == s.size()) {
            res.push_back(curr);
            return;
        }
            
       
        // recursive case
        int i, n = s.length();
        string prefix = "";
        for (i = startIndex; i < n; i++) {
            prefix += s[i];
            
            if (isPalindrome(prefix, 0, prefix.size() - 1)) {
                curr.push_back(prefix);
                helper(s, i + 1, curr, res);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        if (s.length() == 0)
            return {};
        
        vector<vector<string>> res;
        vector<string> curr;
        helper(s, 0, curr, res);
        return res;
    }


// runtime - 16ms , space - 9.6 MB
// passing as reference is avoiding copying.
// so runtime and space increased.