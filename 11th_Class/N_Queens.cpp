// 51. N-Queens
// Link - https://leetcode.com/problems/n-queens/
/**
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
 **/
       void markUnmark (vector<vector<int>>& visited, int row, int col, int n, int val) {
        // no need to mark row as we are passing a new row everytime
        int i, j;
        
        // column mark
        for (i = row; i < n; i++)
            visited[i][col] += val;
        
        // primary diagonal
        i = row, j = col;
        while(i < n && j < n) {
            visited[i][j] += val;
        
            i += 1;
            j += 1;
        }
        
        // secondary diagonal
        i = row, j = col;
        while(i < n && j >= 0) {
            visited[i][j] += val;
            
            i += 1;
            j -= 1;
        }
        
    }
    
    void solveNQueensHelper(vector<vector<int>>& visited, int n, int rowNum, vector<string>& curr_board, vector<vector<string>>& res) {    
        // Base cases
        // Positive case
        if (rowNum == n) {
            res.push_back(curr_board);
            return;
        }
        
        // Recursive case
        // for the current row (rowNum) try out all the possibilites
        int col;
        for (col = 0; col < n; col++) {
            // rowNum, col <-- valid
            if (visited[rowNum][col])
                continue;
            
            // Mark the corresponding col, primary diagonal and secondary diagonal
            markUnmark (visited, rowNum, col, n, 1);
            // push the current contribution
            curr_board[rowNum][col] = 'Q';
            // Call recursively
            solveNQueensHelper(visited, n, rowNum + 1, curr_board, res);
            // pop the current contribution
            curr_board[rowNum][col] = '.';
            // unmark the corresponding col, primary diagonal and secondary diagonal
            markUnmark (visited, rowNum, col, n, -1);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> visited(n, vector<int> (n, 0));
        vector<string> curr_board(n, string(n, '.'));
        solveNQueensHelper(visited, n, 0, curr_board, res);
        return res;
    }







// Optimized solutions

void solveNQueensHelper(vector<bool>& r, vector<bool>& c, vector<bool>& pd, vector<bool>& sd, int n, int rowNum, vector<string>& curr_board, vector<vector<string>>& res) {    
        // Base cases
        // Positive case
        if (rowNum == n) {
            res.push_back(curr_board);
            return;
        }
        
        // Recursive case
        // for the current row (rowNum) try out all the possibilites
        int col;
        for (col = 0; col < n; col++) {
            // rowNum, col <-- valid
            if (r[rowNum] || c[col] || pd[rowNum - col + n - 1] || sd[rowNum + col])
                continue;
            
            // Mark the corresponding col, primary diagonal and secondary diagonal
            r[rowNum] = true;
            c[col] = true;
            pd[rowNum - col + n - 1] = true;
            sd[rowNum + col] = true;
            // push the current contribution
            curr_board[rowNum][col] = 'Q';
            // Call recursively
            solveNQueensHelper(r, c, pd, sd, n, rowNum + 1, curr_board, res);
            // pop the current contribution
            curr_board[rowNum][col] = '.';
            // unmark the corresponding col, primary diagonal and secondary diagonal
            r[rowNum] = false;
            c[col] = false;
            pd[rowNum - col + n - 1] = false;
            sd[rowNum + col] = false;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<bool> r (n, false);
        vector<bool> c (n, false);
        vector<bool> pd (2*n - 1, false);
        vector<bool> sd (2*n - 1, false);
        vector<string> curr_board(n, string(n, '.'));
        solveNQueensHelper(r, c, pd, sd, n, 0, curr_board, res);
        return res;
    }







 