// Link - https://leetcode.com/problems/encode-and-decode-strings/


// Q. Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

//     Machine 1 (sender) has the function:

//     string encode(vector<string> strs) {
        // ... your code
//     return encoded_string;
//     }
//     Machine 2 (receiver) has the function:
//     vector<string> decode(string s) {
        //... your code
//     return strs;
//     }
//     So Machine 1 does:

//     string encoded_string = encode(strs);
//     and Machine 2 does:

//     vector<string> strs2 = decode(encoded_string);
//     strs2 in Machine 2 should be the same as strs in Machine 1.

//     Implement the encode and decode methods.

    

//     Example 1:

//     Input: dummy_input = ["Hello","World"]
//     Output: ["Hello","World"]

//     Explanation:
//     Machine 1:
//     Codec encoder = new Codec();
//     String msg = encoder.encode(strs);
//     Machine 1 ---msg---> Machine 2

//     Machine 2:
//     Codec decoder = new Codec();
//     String[] strs = decoder.decode(msg);
//     Example 2:

//     Input: dummy_input = [""]
//     Output: [""]
    

//     Constraints:

//     1 <= strs.length <= 200
//     0 <= strs[i].length <= 200
//     strs[i] contains any possible characters out of 256 valid ASCII characters.
    

//     Follow up:

//     Could you write a generalized algorithm to work on any possible characters?
//     Could you solve the problem without using any serialize methods (such as eval)?








// Solution: 

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // Separate the individual words by lengths
        string encoded_string = "";
        for (string s : strs) {
            encoded_string += (to_string(s.length())+'#'); // # - delimiter
            encoded_string += s;
        }
        
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> dec;
        
        int i = 0;
        while(i < s.size()) {
            // get occurance of first #
            int pos = s.find('#', i);
            int count = stoi(s.substr(i, pos-i));
            dec.push_back(s.substr(pos+1, count));
            i = pos+count+1;
        }
        
        return dec;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));