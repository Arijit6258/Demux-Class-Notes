// Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/


// ---------------------------------------------------------------------------------------------


// Q. 

    // Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

    // A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    // Example 1:

    // Input: digits = "23"
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    // Example 2:

    // Input: digits = ""
    // Output: []
    // Example 3:

    // Input: digits = "2"
    // Output: ["a","b","c"]
    

    // Constraints:

    // 0 <= digits.length <= 4
    // digits[i] is a digit in the range ['2', '9'].


// ------------------------------------------------------------------------------------------------


// Solution : 

class Solution {
public:
    void letterCombinationsRecursive(string digits, int index, string running_combination, vector<string>& all_possible_letter_combinations, vector<vector<char>>& map) {
        // base case
        if (index == digits.size()) {
            all_possible_letter_combinations.push_back(running_combination);
            return;
        }
        
        // recursive case
        int digit = digits[index]-'2';
        for (char& c : map[digit]) {
            letterCombinationsRecursive(digits, index+1, running_combination+c, all_possible_letter_combinations, map);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        // empty String
        if (digits == "") return {};
        
        // map of digits to characters
        vector<vector<char>> map (8);
        map[0] = {'a', 'b', 'c'};
        map[1] = {'d', 'e', 'f'};
        map[2] = {'g', 'h', 'i'};
        map[3] = {'j', 'k', 'l'};
        map[4] = {'m', 'n', 'o'};
        map[5] = {'p', 'q', 'r', 's'};
        map[6] = {'t', 'u', 'v'};
        map[7] = {'w', 'x', 'y', 'z'};
        
        vector<string> all_possible_letter_combinations;
        string running_combination = "";
        letterCombinationsRecursive(digits, 0, running_combination, all_possible_letter_combinations, map);
        return all_possible_letter_combinations;
    }
};