#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int minDifference(int arr[], int n)  { 
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        
        // dp[j] will be true if a subset with sum j is possible
        vector<bool> dp(totalSum + 1, false);
        dp[0] = true;
        
        // Fill the DP table
        for (int i = 0; i < n; i++) {
            for (int j = totalSum; j >= arr[i]; j--) {
                dp[j] = dp[j] | dp[j - arr[i]];
            }
        }
        
        // Find the largest j such that j <= totalSum/2 and dp[j] is true
        int minDiff = totalSum;
        for (int j = totalSum / 2; j >= 0; j--) {
            if (dp[j]) {
                minDiff = totalSum - 2 * j;
                break;
            }
        }
        
        return minDiff;
    } 
};

int main() {
    int n;
    // Read number of elements
    if (cin >> n) {
        int arr[n];
        // Read array elements
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.minDifference(arr, n) << endl;
    }
    return 0;
}