#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Returns the number of distinct subsequences of s that equal t.
unsigned long long numDistinct(const string& s, const string& t) {
    int m = static_cast<int>(s.length());
    int n = static_cast<int>(t.length());

    vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

    // Empty target string can be formed from any prefix of s in one way.
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "rabbbit", t1 = "rabbit";
    cout << "Example 1:" << '\n';
    cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"" << '\n';
    cout << "Output: " << numDistinct(s1, t1) << '\n' << '\n';

    string s2 = "babgbag", t2 = "bag";
    cout << "Example 2:" << '\n';
    cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"" << '\n';
    cout << "Output: " << numDistinct(s2, t2) << '\n';

    return 0;
}
