#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<pair<int, int>> q; // {node, cost}
    q.push({src, 0});

    int stops = 0;

    while (!q.empty() && stops <= k) {
        int size = q.size();
        vector<int> temp = dist;

        while (size--) {
            auto [node, cost] = q.front();
            q.pop();

            for (auto &flight : flights) {
                if (flight[0] == node) {
                    int next = flight[1];
                    int price = flight[2];

                    if (cost + price < temp[next]) {
                        temp[next] = cost + price;
                        q.push({next, temp[next]});
                    }
                }
            }
        }

        dist = temp;
        stops++;
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100}, {1,2,100}, {2,0,100},
        {1,3,600}, {2,3,200}
    };

    int src = 0, dst = 3, k = 1;