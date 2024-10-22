// Problem_link : https://leetcode.com/problems/valid-palindrome/




// Q. Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    

//     Example 1:

//     Input: s = "A man, a plan, a canal: Panama"
//     Output: true
//     Explanation: "amanaplanacanalpanama" is a palindrome.
//     Example 2:

//     Input: s = "race a car"
//     Output: false
//     Explanation: "raceacar" is not a palindrome.
    

//     Constraints:

//     1 <= s.length <= 2 * 105
//     s consists only of printable ASCII characters.









// Solution:    

class Solution {
public:
    bool isAlphaNumeric(char c) {
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
    }
    
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while(start < end) {
            if (!isAlphaNumeric(s[start])) start++;
            else if (!isAlphaNumeric(s[end])) end--;
            else if (tolower(s[start]) != tolower(s[end])) return false;
            else {
                start++;
                end--;
            }
        }
        
        return true;
    }
};