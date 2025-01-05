# include<bits/stdc++.h>
using namespace std;

//  THIS SOLUTION USES Dijkstra's ALGORITHM TO FIND THE SHORTEST PATH
class Solution {
public:
    //  YOU SHOULD HAVE USED FLOYD WARSHALL !!!!!!!!!
    long long dij(char src, char dest,
                  unordered_map<char, vector<pair<char, int>>>& adj) {

        priority_queue<pair<long long, char>, vector<pair<long long, char>>,
                       greater<pair<long long, char>>>
            pq;
        unordered_map<char, int> vis;

        pq.push({0, src});
        vis[src]++;

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            char c = it.second;
            long long d = it.first;
            vis[c]++;
            if (c == dest)
                return d;

            for (auto p : adj[c]) {

                if (!vis[p.first]) {

                    pq.push({p.second + d, p.first});
                }
            }
        }
        return -1;
    }
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {

        unordered_map<char, vector<pair<char, int>>> adj;
        int n = original.size();

        for (int i = 0; i < n; i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        long long ans = 0;
        vector<vector<int>> pre(26, vector<int>(26, -1));

        for (int i = 0; i < source.size(); i++) {

            if (source[i] != target[i]) {
                if (pre[int(source[i] - 'a')][int(target[i] - 'a')] != -1)
                    ans += pre[int(source[i] - 'a')][int(target[i] - 'a')];
                else {
                    long long dis = dij(source[i], target[i], adj);

                    if (dis == -1)
                        return -1;
                    pre[int(source[i] - 'a')][int(target[i] - 'a')] = dis;
                    ans += dis;
                }
            }
        }
        return ans;
    }
};