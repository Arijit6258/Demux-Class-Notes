// 240. Search a 2D Matrix II
// Link - https://leetcode.com/problems/search-a-2d-matrix-ii/

/*
Problem Statement - 
    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.
    Example:

    Consider the following matrix:

    [
    [1,   4,  7, 11, 15],
    [2,   5,  8, 12, 19],
    [3,   6,  9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30]
    ]
    Given target = 5, return true.

    Given target = 20, return false.
*/

// my approach
class Solution {
public:
    bool helper(vector<int> &row, int n, int target) {
        int lo = 0, hi = n - 1, mid;
        
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            if (row[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return row[lo] == target;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (!n)
            return false;
        int lo = 0, hi = m - 1, mid;
        
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            if (matrix[mid][0] >= target)
                hi = mid;
            else
                lo = mid + 1;
        }
        
        //bool ans = false;
        for (int i = 0; i <= lo; i++) {
            bool ans = helper(matrix[i], n, target);
            if (ans)
                return ans;
        }
        return false;
    }
};

// time complexity - O(m * log(n))
// space complexity - O(1)



// Class approach

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        
        int n = matrix[0].size();
        if (n == 0)
            return false;
        
        // through i and j we are maintaining the search space
        int i = 0, j = n - 1;
        while(i < m && j >= 0) {
            
            // compare with target
            if (matrix[i][j] == target)
                return true;
            
            else if (matrix[i][j] > target)
                j -= 1;
            
            else
                i += 1;
        }
        
        return false;
    }
    // Time complexity = O(m + n)
    // space complexity = O(1)