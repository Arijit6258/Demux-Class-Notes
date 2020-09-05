// 74. Search a 2D Matrix 
// Link - https://leetcode.com/problems/search-a-2d-matrix/
/** 
    Problem Statement : 

    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    Example 1:

    Input:
    matrix = [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
    ]
    target = 3
    Output: true
    Example 2:

    Input:
    matrix = [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
    ]
    target = 13
    Output: false
**/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // FFF*TTT*
        // predicate : P(X) = matrix[x][0] >= target
        // last false
        
        int n = matrix.size(), lo = 0, hi, mid;
        hi = n - 1;
        
        if (n == 0 || matrix[0].size() == 0)
            return false;
        
        while(lo < hi) {
            mid = lo + (hi - lo + 1)/2;
            if (matrix[mid][0] > target)
                hi = mid - 1;
            else
                lo = mid;
        }
        
        if (matrix[lo][0] > target)
            return false;
        
        vector<int> row = matrix[lo];
        lo = 0, hi = row.size() - 1;
        
        if (row.size() == 0)
            return false;
        
        while(lo < hi) {
            mid = lo + (hi - lo + 1)/2;
            if (row[mid] > target)
                hi = mid - 1;
            else
                lo = mid;
        }
        
        return row[lo] == target;
    }
    
    // Time compexity = O(log(n * m))
    // Space complexity = O(1)