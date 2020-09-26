// 42. Trapping Rain Water
// Link - https://leetcode.com/problems/trapping-rain-water/

/**
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

 **/

// First Approach

int trap(vector<int>& height) {
        // at ith index water stored = min (largest height to the left, largetst height to the right)
        int leftMax = 0, rightMax = 0, n = height.size(), totalAmount = 0;
        vector<int> suffixMax (n, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            suffixMax[i] = rightMax;
            rightMax = max(rightMax, height[i]);
        }
        
        for (int i = 0; i < n; i++) {
            int store = min (leftMax, suffixMax[i]);
            if (store > height[i])
                totalAmount += store - height[i];
            
            leftMax = max (leftMax, height[i]);
        }
        
        return totalAmount;
        
        // time complexity - O(n)
        // space complexity - O(n)
        // two passes
    }


// Second Approach

int trap(vector<int>& height) {
        int n = height.size(), surplus = 0, res = 0;
        
        if (n == 0)
            return 0;
        
        int l = 0, r = n - 1;
        int lvalue = height[0], rvalue = height[n - 1];
        
        while (l < r) {
            cout << l << " " << r << " " << lvalue << " " << rvalue << endl;
            if (lvalue < rvalue) {
                surplus = lvalue - height[l + 1];
                
                if (surplus > 0) {
                    res += surplus;
                }
                
                l += 1;
                lvalue = max (lvalue, height[l]);
            }
            
            else {
                surplus = rvalue - height[r - 1];
                
                if (surplus > 0) {
                    res += surplus;
                }
                
                r -= 1;
                rvalue = max (rvalue, height[r]);
            }
        }
        
        return res;
    }