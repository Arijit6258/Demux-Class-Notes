/***
 * 852. Peak Index in a Mountain Array
 * Link - https://leetcode.com/problems/peak-index-in-a-mountain-array/
 
Let's call an array A a mountain if the following properties hold:

1. A.length >= 3

2. There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.
***/

int peakIndexInMountainArray(vector<int>& A) {
        // FFF*TTT*
        // Predicate : A[i] > A[i + 1]
        // Find first T
        
        int mid, n = A.size(), lo, hi;
        
        lo = 0, hi = n - 1;
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            if (A[mid] > A[mid + 1])
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }