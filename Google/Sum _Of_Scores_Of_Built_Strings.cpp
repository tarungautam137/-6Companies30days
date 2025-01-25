# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumScores(string s) {

        //[l,r)-RIGHTMOST SEGMENT MATCH
        int n = s.size(), l = 0, r = 0;

        vector<int> z(n, 0);
        z[0] = n;

        for (int i = 1; i < n; i++) {

            if (i < r)
                z[i] = min(z[i - l], r - i);

            while (i + z[i] < n && s[i + z[i]] == s[z[i]])
                z[i]++;

            if (i + z[i] > r) {

                l = i;
                r = i + z[i];
            }
        }

        long long ans = 0;

        for (int x : z)
            ans += x;

        return ans;
    }
};