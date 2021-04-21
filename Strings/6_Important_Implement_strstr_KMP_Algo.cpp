// Link - https://leetcode.com/problems/implement-strstr/

//----------------------------------------------------------------


//      Q.
//     Implement strStr().

//     Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

//     Clarification:

//     What should we return when needle is an empty string? This is a great question to ask during an interview.

//     For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

    

//     Example 1:

//     Input: haystack = "hello", needle = "ll"
//     Output: 2
//     Example 2:

//     Input: haystack = "aaaaa", needle = "bba"
//     Output: -1
//     Example 3:

//     Input: haystack = "", needle = ""
//     Output: 0
    

//     Constraints:

//     0 <= haystack.length, needle.length <= 5 * 104
//     haystack and needle consist of only lower-case English characters.


// ------------------------------------------


// Solution - 


class Solution {
public:
    int strStr(string haystack, string needle) {
        // calculate lps array
        int n = needle.size();
        vector<int> lps(n, 0);
        
        for (int i = 1; i < n; i++) {
            // compute lps[i]
            int j = lps[i-1];
            
            // continue until find a match
            while(j > 0 && needle[i] != needle[j]) {
                j = lps[j-1];
            }
            
            // if bubble not found
            if (needle[i] != needle[j]) lps[i] = 0;
            
            // bubble found - extend the bubble
            else lps[i] = j+1;
        }
        
        // Kmp algorithm
        // lps[i] --> longest proper prefix which is also proper suffix of pattern[0:i]
        int i = 0, j = 0;
        
        while(i < haystack.size() && j < n) {
            if (haystack[i] != needle[j]) {
                // mismatch
                if (j == 0) i++;
                else j = lps[j-1];
                continue;
            } 
            
            i++; j++;
        }
        
        // pattern found
        if (j == n) return i-n;
        
        // pattern not found
        return -1;
    }
};