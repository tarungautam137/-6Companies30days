# include<bits/stdc++.h>
using namespace std;

// Dynamic Programming Solution to Maximum Profit with K transactions
class Solution {
public:
    // MEMOISATION
    int f(int ind, int buy, int sell, vector<vector<vector<int>>>& dp,
          vector<int>& prices) {

        int n = prices.size();

        if (ind == n || (buy == 0 && sell == 0))
            return 0;

        if (dp[ind][buy][sell] != -1)
            return dp[ind][buy][sell];

        int allow = 0, notallow = 0;

        if (buy == sell) {

            allow = f(ind + 1, buy - 1, sell, dp, prices) - prices[ind];
            notallow = f(ind + 1, buy, sell, dp, prices);
        } else {

            allow = f(ind + 1, buy, sell - 1, dp, prices) + prices[ind];
            notallow = f(ind + 1, buy, sell, dp, prices);
        }
        return dp[ind][buy][sell] = max(allow, notallow);
    }
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(k + 1, -1)));

        return f(0, k, k, dp, prices);
    }
};