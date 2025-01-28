# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // CAN BE SOLVED WITH DP ALSO
    int peopleAwareOfSecret(int n, int delay, int forget) {

        int mod = 1e9 + 7;

        vector<int> newPersons(n + 2, 0), forg(n + 2, 0);
        newPersons[1] = 1;

        for (int i = 1; i < n; i++) {

            int count = newPersons[i];

            int l = i + delay, r = min(i + forget - 1, n);

            for (int ind = l; ind <= r; ind++) newPersons[ind] = (newPersons[ind] + count) % mod;

            int ind = min(i + forget, n + 1);

            forg[ind] = (forg[ind] - count) % mod;
        }

        long long sum = 0, ns = 0;

        for (int i = 0; i <= n; i++) sum = (sum + newPersons[i]);

        for (int i = 0; i <= n; i++) ns = (ns + forg[i]);

        return (sum + ns) % mod;
    }
};