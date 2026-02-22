#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int minUnfairness = INT_MAX;

    for (int i = 0; i <= n - k; i++) {
        int currentDiff = arr[i + k - 1] - arr[i];
        minUnfairness = min(minUnfairness, currentDiff);
    }

    cout << minUnfairness << endl;

    return 0;
}