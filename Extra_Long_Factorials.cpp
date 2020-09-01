// Link of the question - https://www.hackerrank.com/challenges/extra-long-factorials/problem

// solution - 

#include <iostream>
#include <vector>

using namespace std;
// helper function for multiplying
void multiply(vector<int> &currProd, int num) {
    // currProd sotres the number in reverse
    int carry = 0, i, currDigit;

    for (i = 0; i < currProd.size(); i++) {
        currDigit = (currProd[i]*num + carry)%10;
        carry = (currProd[i]*num + carry)/10;
        
        // copy the last significant digit.
        currProd[i] = currDigit;
    }

    // copy the remaining carry in reverse order
    for (i = carry; i > 0; i = i/10)
        currProd.push_back(i%10);
}
// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    // keep an array as running product
    vector<int> currProd;
    currProd.push_back(1);
    int i;

    for (i = 1; i <= n; i++)
        multiply(currProd, i);

    // Print the number in reverse
    for (i = currProd.size() - 1; i >= 0; i--)
        cout << currProd[i];
    
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}

// Time Complexity : O(N * D)
// Space Complexity : O(D)