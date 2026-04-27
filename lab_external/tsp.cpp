class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        // code here
        int n = cost.size();
vector<vector<int>> dp(1 << n, vector<int>(n, -1));
function<int(int, int)> solve = [&](int mask, int pos) {
    if (mask == (1 << n) - 1) return cost[pos][0];
    if (dp[mask][pos] != -1) return dp[mask][pos];
    int min_cost = 1e9;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            min_cost = min(min_cost, cost[pos][city] + solve(mask | (1 << city), city));
        }
    }
    return dp[mask][pos] = min_cost;
};
return solve(1, 0);
    }
};