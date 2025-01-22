# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(300*1000*20) top down dp
    bool f(int ind, vector<string>& wordDict, string& s, vector<int>& dp) {

        int n = s.size();

        if (ind == n)
            return true;

        if (dp[ind] != -1)
            return dp[ind];

        for (string word : wordDict) {

            int len = word.size();

            if (ind + len > n)
                continue;

            bool flag = true;

            for (int i = ind; i < ind + len; i++) {

                if (s[i] != word[i - ind]) {

                    flag = false;
                    break;
                }
            }

            if (flag && f(ind + len, wordDict, s, dp)) {

                dp[ind] = 1;
                return true;
            }
        }

        return dp[ind] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> dp(s.size(), -1);

        return f(0, wordDict, s, dp);
    }
};