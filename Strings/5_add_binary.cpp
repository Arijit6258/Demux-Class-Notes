// Link - https://leetcode.com/problems/add-binary/

// Q.  

//     Given two binary strings a and b, return their sum as a binary string.

    

//     Example 1:

//     Input: a = "11", b = "1"
//     Output: "100"
//     Example 2:

//     Input: a = "1010", b = "1011"
//     Output: "10101"
    

//     Constraints:

//     1 <= a.length, b.length <= 104
//     a and b consist only of '0' or '1' characters.
//     Each string does not contain leading zeros except for the zero itself.



//     Solution: 




class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string res = "";
        
        while(i >= 0 || j >= 0) {
            int sum = 0, n1 = 0, n2 = 0;
            if (i >= 0) n1 = a[i]-'0';
            if (j >= 0) n2 = b[j]-'0';
            
            sum = (n1+n2+carry)%2;
            carry = (n1+n2+carry)/2;
            
            res += char(sum+'0');
            i--; j--;
        }
        
        if (carry) res += (carry+'0');
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};