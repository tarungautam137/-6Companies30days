#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    Solution() { dp = vector<vector<int>>(12, vector<int>(12, -1)); }

    void f(int ind, string s, vector<pair<string, string>>& v, string& s1,
           string& s2) {

        int n = s.size();
        if (ind == n) {
            if (s1.size() > 0 && s2.size() > 0)
                v.push_back({s1, s2});
            return;
        }

        s1.push_back(s[ind]);
        f(ind + 1, s, v, s1, s2);
        s1.pop_back();

        s2.push_back(s[ind]);
        f(ind + 1, s, v, s1, s2);
        s2.pop_back();
    }
    int lcs(int ind1, int ind2, string& s, string& t) {

        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s[ind1] == t[ind2])
            return dp[ind1][ind2] = 1 + lcs(ind1 - 1, ind2 - 1, s, t);

        return dp[ind1][ind2] =
                   max(lcs(ind1 - 1, ind2, s, t), lcs(ind1, ind2 - 1, s, t));
    }

    int lps(string s) {

        int n = s.size();

        string t = s;
        reverse(t.begin(), t.end());

        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                dp[i][j] = -1;
            }
        }

        return lcs(n - 1, n - 1, s, t);
    }

    int maxProduct(string s) {

        vector<pair<string, string>> v;
        string s1 = "", s2 = "";

        f(0, s, v, s1, s2);

        int maxi = 0;
        string m1, m2;
        for (auto& it : v) {

            string first = it.first, second = it.second;

            int l1 = lps(first);
            int l2 = lps(second);

            if (l1 * l2 > maxi) {
                maxi = l1 * l2;
                m1 = first;
                m2 = second;
            }
        }
        cout << m1 << " " << m2;
        return maxi;
    }
};