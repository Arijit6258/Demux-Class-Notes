// 1011. Capacity To Ship Packages Within D Days
// Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
/** 
 * Problem Statement :
 
 * A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: 
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed. 
Example 2:

Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
Explanation: 
A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], D = 4
Output: 3
Explanation: 
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= D <= weights.length <= 50000
1 <= weights[i] <= 500

**/

// Solution : 

int Days_Required(int capacity, vector<int> &weights) {
        int days = 0, i = 0;
        
        // calculating number of days required
        while(i < weights.size()) {
            int j = i, w = 0;
            while(j < weights.size() && w + weights[j] <= capacity) {
                w += weights[j];
                j += 1;
            }
            i = j;
            days += 1;
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        // Optimization Problem - Capacity has to be optimized
        // FFF*TTT*
        // P(X) : no_of_days_required(X) <= D
        // Find first Ture
        // Search Space : Max Element of array to sum of array elements
        
        int n = weights.size(), lo, hi, mid;
        
        // obtaining the search space
        hi = 0, lo = INT_MIN;
        for(int i = 0; i < n; i++) {
            hi += weights[i];
            lo = max(lo, weights[i]);
        }
        
        // binary_search
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            if (Days_Required(mid, weights) <= D)
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }