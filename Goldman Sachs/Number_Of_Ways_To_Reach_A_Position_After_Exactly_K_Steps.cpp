# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // IT IS SIMPLY kCx of pnc WHERE X=(K-D)/2. BUT SOLVED BY DP
    
    int f(int front, int back, vector<vector<int>>& dp) {

        int mod = 1e9 + 7;

        if (front == 0 && back == 0) return 1;

        if (dp[front][back] != -1)  return dp[front][back];

        int sf = 0, sb = 0;

        if (front) sf = f(front - 1, back, dp);
        if (back) sb = f(front, back - 1, dp);

        return dp[front][back] = (sf + sb) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {

        int d = abs(startPos - endPos);

        if ((d % 2 == 1 && k % 2 == 0) || (d % 2 == 0 && k % 2 == 1) || (d > k)) return 0;

        int x = (k - d) / 2;

        vector<vector<int>> dp(d + x + 1, vector<int>(x + 1, -1));
        return f(d + x, x, dp);
    }
};