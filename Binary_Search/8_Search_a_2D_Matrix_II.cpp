// Link - https://leetcode.com/problems/search-a-2d-matrix-ii/

// ------------------------------------------------------------------------------------------------

// Q.

//     Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

//     Integers in each row are sorted in ascending from left to right.
//     Integers in each column are sorted in ascending from top to bottom.
    

//     Example 1:


//     Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
//     Output: true
//     Example 2:


//     Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
//     Output: false
    

//     Constraints:

//     m == matrix.length
//     n == matrix[i].length
//     1 <= n, m <= 300
//     -109 <= matix[i][j] <= 109
//     All the integers in each row are sorted in ascending order.
//     All the integers in each column are sorted in ascending order.
//     -109 <= target <= 109


// --------------------------------------------------------------------------------------------------------


// Solution : 


// Binary search Approach


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



// Eleminating row and column approach


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rs = 0, ce = matrix[0].size()-1;
        
        while(rs < matrix.size() && ce >= 0) {
            if (target > matrix[rs][ce]) rs++;
            else if (target < matrix[rs][ce]) ce--;
            else return true;
        }
        
        return false;
        
        // T.C - O(m+n)
    }
};