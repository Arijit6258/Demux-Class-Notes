// Link - https://leetcode.com/problems/search-a-2d-matrix/

// Q. 

    // Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    // Integers in each row are sorted from left to right.
    // The first integer of each row is greater than the last integer of the previous row.
    

    // Example 1:


    // Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    // Output: true
    // Example 2:


    // Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    // Output: false
    

    // Constraints:

    // m == matrix.length
    // n == matrix[i].length
    // 1 <= m, n <= 100
    // -104 <= matrix[i][j], target <= 104



// ------------------------------------------------------------------------------------------------


// Solution : 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        // find the row 
        // P(X) : matrix[X][0] <= target
        // TTT*FFF*
        // find last T
        
        int lo = 0, hi = n-1;
        while(lo < hi) {
            int mid = lo+(hi-lo+1)/2;
            if (matrix[mid][0] <= target) lo = mid;
            else hi = mid-1;
        }
        
        int row = lo;
        
        // find the column
        // P(Y) : matrix[row][Y] <= target
        // TTT*FFF*
        // find last T
        
        lo = 0, hi = m-1;
        while(lo < hi) {
            int mid = lo+(hi-lo+1)/2;
            if (matrix[row][mid] <= target) lo = mid;
            else hi = mid-1;
        }
        
        return matrix[row][lo] == target;
    }
};