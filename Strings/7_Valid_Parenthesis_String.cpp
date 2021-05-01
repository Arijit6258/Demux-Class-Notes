// Link - https://leetcode.com/problems/valid-parenthesis-string/

// ------------------------------------------------------------------------------------------------

// Q. 

//     Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

//     The following rules define a valid string:

//     Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//     Any right parenthesis ')' must have a corresponding left parenthesis '('.
//     Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//     '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
    

//     Example 1:

//     Input: s = "()"
//     Output: true
//     Example 2:

//     Input: s = "(*)"
//     Output: true
//     Example 3:

//     Input: s = "(*))"
//     Output: true
    

//     Constraints:

//     1 <= s.length <= 100
//     s[i] is '(', ')' or '*'.


// ------------------------------------------------------------------------------------------------


// Solution : 


class Solution {
public:
    bool checkValidString(string s) {
        int l_count = 0, unoccupied = 0, occupied = 0;
        // l_count -> Number of outstanding left parenthesis
        // unoccupied -> Count of all stars which have not yet been assigned anything
        // occupied -> Count of all stars which have been greedily assigned a closing parenthesis
        
        for (char c : s) {
            // open bracket
            if (c == '(') l_count++;
            else if (c == '*') {
                // opening bracket is more than closing bracket+number of stars replaced with closing 
                // replace the current star with closing bracket to balance with opening bracket
                if (l_count-occupied > 0) occupied++;
                // opening bracket is equal to closing bracket+number of stars replaced with closing 
                // keep this star as unoccupied for now
                else unoccupied++;
            }
            else {
                // opening bracket is more than closing bracket+number of stars replaced with closing
                // one opening bracket will be closed by this closing bracket. So, decrease l_count
                if (l_count-occupied > 0) l_count--;
                // opening bracket is equal to closing bracket+number of stars replaced with closing
                // if a star was replaced with closing bracket previously then change that bracket to star
                // keep that star as unoccupied
                // one opening which was previously closed by the star is now closed by this closing
                else if (occupied > 0) {
                    occupied--;
                    l_count--;
                    unoccupied++;
                }
                // if there is any unoccupied then change it to opening
                else if (unoccupied > 0) {
                    unoccupied--;
                }
                // otherwise there is no way to balance this closing bracket with any previous opening 
                // bracket or star
                else return false;
            }
        }
        
        return l_count-occupied == 0;
    }
};